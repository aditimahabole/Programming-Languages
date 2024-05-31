#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <unordered_map>
#include <sstream>

const int MAX_TRANSACTIONS = 6;
const int MAX_DEPOSIT = 1000000;

using namespace std;

struct Transaction {
    string date;
    string type;
    double amount;
};

class User {
public:
    string username;

    vector<Transaction> transactions;
    // user has many transactions

    int transactions_limit;

    string lastWithdrawDate;
    // last date he withdraw 

    // Default constructor
    User() : transactions_limit(0) {}

    // Parameterized constructor
    User(const string& uname) : username(uname), transactions_limit(0) {}
};

class BankManagementSystem {
private:
    string file_path;

    unordered_map<string, User> users;
    // a bank will have many users

    string getCurrentDate() {
        // cout<<"---- Inside Get Current Date ---- "<<endl;

        time_t now = time(0);
        // cout<<"now : "<<now<<endl;
        tm* localTime = localtime(&now);
        // cout<<"localTime : "<<localTime<<endl;
        string today = to_string(1900 + localTime->tm_year) + "-" + to_string(1 + localTime->tm_mon) + "-" + to_string(localTime->tm_mday);
        cout<<"-->  Date : "<<today<<endl;
        // cout<<"--------------------------------- "<<endl;
        return today;
    }

    string getCurrentDateTime() {
        time_t now = time(0);
        tm* localTime = localtime(&now);
        string dateTime = to_string(1900 + localTime->tm_year) + "-" + to_string(1 + localTime->tm_mon) + "-" + to_string(localTime->tm_mday) +
                          " " + to_string(localTime->tm_hour) + ":" + to_string(localTime->tm_min) + ":" + to_string(localTime->tm_sec);
        return dateTime;
    }

    void loadTransactions() {
        cout<<"--- Loading Transactions of user ---"<<endl;
        ifstream file(file_path);
        if (!file.is_open()) {
            cerr << "Error: Unable to open file." << endl;
            return;
        }

        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string username, date, type;
            double amount;

            getline(ss, username, ',');
            getline(ss, date, ',');
            getline(ss, type, ',');
            ss >> amount;

            if (users.find(username) == users.end()) {
                users[username] = User(username);
            }
            
            users[username].transactions.push_back({date, type, amount});

            cout<<"name : "<<users[username].username<<endl;

            cout<<"transactions done : "<<users[username].transactions.size()<<endl;
           
        }

        file.close();
    }

    void saveTransactions() {
        ofstream file(file_path);
        if (!file.is_open()) {
            cerr << "Error: Unable to open file." << endl;
            return;
        }
        cout<<"Saving to file ..."<<endl;

        for (const auto& user_pair : users) {
            const User& user = user_pair.second;
            for (const auto& transaction : user.transactions) {
                file << user.username << "," << transaction.date << "," << transaction.type << "," << transaction.amount << endl;
            }
        }

        file.close();
        cout<<"All files saved!"<<endl;
    }

    // this will be called before every transaction
    bool checkDailyTransactionLimit(const User& user) {
        int count = 0;
        string today = getCurrentDate();

        for (const auto& transaction : user.transactions) {
            if (transaction.date.substr(0, 10) == today) {
                count++;
            }
        }
        cout<<user.username <<" -> "<<count<<endl;

        return count < MAX_TRANSACTIONS;
    }

    bool checkDepositLimit(const User& user, double amount) {
        double initialDeposit = 0;
        for (const auto& transaction : user.transactions) {
            if (transaction.type == "Deposit") {
                initialDeposit += transaction.amount;
            }
        }
        cout<<user.username<<" inital deposit "<<initialDeposit<<endl;
        double todayDeposit = 0;
        string today = getCurrentDate();

        for (const auto& transaction : user.transactions) {
            if (transaction.type == "Deposit" && transaction.date.substr(0, 10) == today) {
                todayDeposit += transaction.amount;
            }
        }
        cout<<user.username<<" today deposit "<<todayDeposit<<endl;

        return todayDeposit + amount <= initialDeposit * 10;
    }

    bool checkWithdrawLimit(const User& user, double amount) {
        double monthWithdrawals = 0;
        time_t now = time(0);
        tm* localTime = localtime(&now);
        int currentMonth = 1 + localTime->tm_mon;

        for (const auto& transaction : user.transactions) {
            if (transaction.type == "Withdraw" && stoi(transaction.date.substr(5, 2)) == currentMonth) {
                monthWithdrawals += transaction.amount;
            }
        }

        return monthWithdrawals + amount <= 0.8 * getInitialMonthDeposit(user);
    }

    double getInitialMonthDeposit(const User& user) {
        double initialMonthDeposit = 0;
        time_t now = time(0);
        tm* localTime = localtime(&now);
        int currentMonth = 1 + localTime->tm_mon;

        for (const auto& transaction : user.transactions) {
            if (transaction.type == "Deposit" && stoi(transaction.date.substr(5, 2)) == currentMonth) {
                initialMonthDeposit += transaction.amount;
            }
        }

        return initialMonthDeposit;
    }

public:
    BankManagementSystem(const string& path) {
        this->file_path = path;
        loadTransactions();
    }

    void deposit(const string& username, double amount) {
        // if user not found then add key value of name : User Object
        if (users.find(username) == users.end()) {
            cout<<"New User Added (Deposit) : "<<username<<endl;
            users[username] = User(username);
        }
        // if already name is present then make a temp User object
        // named user and assigning the details of that user

        User& user = users[username];
        // first check the limit 

        bool can_do_transactions = checkDailyTransactionLimit(user);
        bool can_deposit_amount = checkDepositLimit(user, amount);

        if(!can_deposit_amount) cout<<"Cannot Deposit this much !"<<endl;

        if(!can_do_transactions) cout<<"Transaction Limit Exceeded !"<<endl;

        if ( can_do_transactions && can_deposit_amount ) {

            string dateTime = getCurrentDateTime();

            user.transactions.push_back({dateTime, "Deposit", amount});

            saveTransactions();

            cout <<username<< " : Deposit successful. " <<amount<< endl;
        } else {
            
             cout <<username<< " : Oops Deposit unsuccessful. Please check constraints." << endl;
        }
    }

    void withdraw(const string& username, double amount) {
        if (users.find(username) == users.end()) {
            cout<<"New User Added (Withdraw) : "<<username<<endl;
            users[username] = User(username);
        }
        User& user = users[username];
        
        string today = getCurrentDate();
        
        // Reset daily withdrawal count if the date has changed
        if (user.lastWithdrawDate != today) {
            user.transactions_limit = 0;
            user.lastWithdrawDate = today;
        }

        if (user.transactions_limit < 5 && checkWithdrawLimit(user, amount)) {

            string dateTime = getCurrentDateTime();

            user.transactions.push_back({dateTime, "Withdraw", amount});

            user.transactions_limit++;

            saveTransactions();

            cout <<username<< " : Withdrawal successful. " <<amount<< endl;
        } else {
            cout <<username<< "Oops Withdrawal unsuccessful. Please check constraints." << endl;
        }
        return;
    }

    void checkBalance(const string& username) {
        if (users.find(username) == users.end()) {
            users[username] = User(username);
        }
        User& user = users[username];

        double balance = 0;
        for (const auto& transaction : user.transactions) {
            if (transaction.type == "Deposit") {
                balance += transaction.amount;
            } else if (transaction.type == "Withdraw") {
                balance -= transaction.amount;
            }
        }
        cout << "Your current balance is: " << balance << endl;
    }
};

int main() {
    BankManagementSystem bank("C:\\Users\\ADITI KIRAN MAHABOLE\\Desktop\\cpp\\some.csv");
    bank.deposit("john_doe", 200);
    return 0;
}
