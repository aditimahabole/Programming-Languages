#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <unordered_map>
#include <sstream>

const int MAX_TRANSACTIONS = 4;
const int MAX_DEPOSIT = 1000000;

using namespace std;

struct Transaction
{
    string date;
    string time; 
    string type;
    double amount;
};

class User
{
public:
    string username;
    vector<Transaction> transactions;
    int transactions_limit;
    string last_transaction_date;

    User() : transactions_limit(0) {}
    User(const string &uname) : username(uname), transactions_limit(0) {}
};

class BankManagementSystem
{
private:
    string file_path;
    unordered_map<string, User> users;

    string getCurrentDate()
    {
        time_t now = time(0);
        tm *localTime = localtime(&now);
        string today = to_string(1900 + localTime->tm_year) + "-" + to_string(1 + localTime->tm_mon) + "-" + to_string(localTime->tm_mday);
        return today;
    }

    string getCurrentTime()
    {
        time_t now = time(0);
        tm *localTime = localtime(&now);
        string currentTime = to_string(localTime->tm_hour) + ":" + to_string(localTime->tm_min) + ":" + to_string(localTime->tm_sec);
        return currentTime;
    }

    void loadTransactions()
    {
        ifstream file(file_path);
        if (!file.is_open())
        {
            cerr << "Error: Unable to open file." << endl;
            return;
        }

        string line;
        while (getline(file, line))
        {
            stringstream ss(line);
            string username, date, time, type;
            double amount;

            getline(ss, username, ',');
            getline(ss, date, ',');
            getline(ss, time, ',');
            getline(ss, type, ',');
            ss >> amount;

            if (users.find(username) == users.end())
            {
                users[username] = User(username);
            }

            users[username].transactions.push_back({date, time, type, amount});
        }

        file.close();
    }

    void saveTransactions()
    {
        ofstream file(file_path);
        if (!file.is_open())
        {
            cerr << "Error: Unable to open file." << endl;
            return;
        }

        for (const auto &user_pair : users)
        {
            const User &user = user_pair.second;

            for (const auto &transaction : user.transactions)
            {
                file << user.username << "," << transaction.date << "," << transaction.time << "," << transaction.type << "," << transaction.amount << endl;
            }
        }

        file.close();
    }

    bool checkDailyTransactionLimit(const User &user)
    {
        int count = 0;
        string today = getCurrentDate();

        for (const auto &transaction : user.transactions)
        {
            if (transaction.date == today)
            {
                count++;
            }
        }

        return count < MAX_TRANSACTIONS;
    }

    bool checkDepositLimit(const User &user, double amount)
    {
        double initialDeposit = 0;
        for (const auto &transaction : user.transactions)
        {
            if (transaction.type == "Deposit")
            {
                initialDeposit += transaction.amount;
            }
        }

        if (initialDeposit == 0)
        {
            return true; // No previous deposits, so no limit reached
        }

        double todayDeposit = 0;
        string today = getCurrentDate();

        for (const auto &transaction : user.transactions)
        {
            if (transaction.type == "Deposit" && transaction.date == today)
            {
                todayDeposit += transaction.amount;
            }
        }

        return todayDeposit + amount <= initialDeposit * 10;
    }

    bool checkWithdrawLimit(const User &user, double amount)
    {
        double monthWithdrawals = 0;
        time_t now = time(0);
        tm *localTime = localtime(&now);
        int currentMonth = 1 + localTime->tm_mon;

        for (const auto &transaction : user.transactions)
        {
            if (transaction.type == "Withdraw" && stoi(transaction.date.substr(5, 2)) == currentMonth)
            {
                monthWithdrawals += transaction.amount;
            }
        }

        return monthWithdrawals + amount <= 0.8 * getInitialMonthDeposit(user);
    }

    double getInitialMonthDeposit(const User &user)
    {
        double initialMonthDeposit = 0;
        time_t now = time(0);
        tm *localTime = localtime(&now);
        int currentMonth = 1 + localTime->tm_mon;

        for (const auto &transaction : user.transactions)
        {
            if (transaction.type == "Deposit" && stoi(transaction.date.substr(5, 2)) == currentMonth)
            {
                initialMonthDeposit += transaction.amount;
            }
        }

        return initialMonthDeposit;
    }

public:
    BankManagementSystem(const string &path)
    {
        this->file_path = path;
        loadTransactions();
    }

    void deposit(const string &username, double amount)
    {
        if (users.find(username) == users.end())
        {
            cout<<"Account Created Successfully !"<<endl;
            users[username] = User(username);
        }

        User &user = users[username];
        string today = getCurrentDate();

        // if user's latest transaction starts on a new day then obvio
        // we have to resent the number of transactions limit right

        if (user.last_transaction_date != today)
        {
            user.transactions_limit = 0;
            user.last_transaction_date = today;
        }
    

        bool can_do_transactions = checkDailyTransactionLimit(user);
        bool can_deposit_amount = checkDepositLimit(user, amount);

        if (can_do_transactions && can_deposit_amount)
        {
            string currentDate = getCurrentDate();
            string currentTime = getCurrentTime();
            vector<Transaction> &transactions = user.transactions;
            transactions.push_back({currentDate, currentTime, "Deposit", amount});
            user.transactions_limit++;
            saveTransactions();

            cout<<"-------------------------------------"<<endl;
            cout<<"Username           : "<<username<<endl;
            cout<<"Deposited amount   : "<<amount<<endl;
            cout<<"No Of Transactions : "<<user.transactions_limit<<endl;
            cout <<"***** Transaction successful *****"<< endl;
            cout<<"-------------------------------------"<<endl;
        }
        else
        {
            cout<<"-------------------------------------"<<endl;
            if(!can_do_transactions) cout<<"Transactions limit exceeded! Come next time"<<endl;
            if(!can_deposit_amount) cout<<"Deposit Amount exceeded!"<<endl;
            cout <<"Transaction Unsuccessful !"<< endl;
            cout<<"-------------------------------------"<<endl;
            
        }
    }

    void withdraw(const string &username, double amount)
    {
        if (users.find(username) == users.end())
        {
            cout<<"Account Created Successfully !"<<endl;
            users[username] = User(username);
        }

        User &user = users[username];
        string today = getCurrentDate();
        // if user's latest transaction starts on a new day then obvio
        // we have to resent the number of transactions limit right

        if (user.last_transaction_date != today)
        {
            user.transactions_limit = 0;
            user.last_transaction_date = today;
        }
        bool can_withdraw =  checkWithdrawLimit(user, amount);
        if (user.transactions_limit <= MAX_TRANSACTIONS && can_withdraw)
        {
            string currentDate = getCurrentDate();
            string currentTime = getCurrentTime();
            vector<Transaction> &transactions = user.transactions;
            transactions.push_back({currentDate, currentTime, "Withdraw", amount});

            user.transactions_limit++;
            saveTransactions();
            cout<<"-------------------------------------"<<endl;
            cout<<"Username           : "<<username<<endl;
            cout<<"Withdraw amount    : "<<amount<<endl;
            cout<<"No Of Transactions : "<<user.transactions_limit<<endl;
            cout <<"***** Transaction successful *****"<< endl;
            cout<<"-------------------------------------"<<endl;
        }
        else
        {
            cout<<"-------------------------------------"<<endl;
            if(user.transactions_limit > MAX_TRANSACTIONS) cout<<"Transactions limit exceeded! Come next time"<<endl;
            if(!can_withdraw) cout<<"Withdraw Amount exceeded!"<<endl;
            cout <<"Transaction Unsuccessful !"<< endl;
            cout<<"-------------------------------------"<<endl;
           
        }
    }

    void checkBalance(const string &username)
    {
        if (users.find(username) == users.end())
        {
            cout<<"Account Created Successfully !"<<endl;
            users[username] = User(username);
        }

        User &user = users[username];
        double balance = 0;

        for (const auto &transaction : user.transactions)
        {
            if (transaction.type == "Deposit")
            {
                balance += transaction.amount;
            }
            else if (transaction.type == "Withdraw")
            {
                balance -= transaction.amount;
            }
        }
        cout<<"-------------------------------------"<<endl;
        cout<<"Username                 : "<<username<<endl;
        cout<<"Current Balance          : " << balance << endl;
        cout<<"-------------------------------------"<<endl;
    }
};

int main()
{
    BankManagementSystem bank("C:\\Users\\ADITI KIRAN MAHABOLE\\Desktop\\cpp\\some.csv");
    int choice;
    string username;
    double amount;

    do
    {
        cout << "\n ------------Bank Management System-------------- \n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Check Balance\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter amount to deposit: ";
            cin >> amount;
            bank.deposit(username, amount);
            break;
        case 2:
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            bank.withdraw(username, amount);
            break;
        case 3:
            cout << "Enter username: ";
            cin >> username;
            bank.checkBalance(username);
            break;
        case 4:
            cout << "Exiting...";
            break;
        default:
            cout << "Invalid choice! Please enter a number between 1 and 4.";
        }
    } while (choice != 4);

    return 0;
}
