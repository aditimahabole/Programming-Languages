#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <unordered_map>

using namespace std;

struct MenuItem {
    string name;
    double price;
};

class User {
private:
    string username;
    int seats;
    vector<MenuItem> order;

public:
    User(const string &name) : username(name), seats(0) {}

    string getUsername() const {
        return username;
    }

    int getSeats() const {
        return seats;
    }

    bool addSeats(int numSeats) {
        if (seats + numSeats <= 4) {
            seats += numSeats;
            return true;
        }
        return false;
    }

    void addOrderItem(const MenuItem &item) {
        order.push_back(item);
    }

    vector<MenuItem> getOrder() const {
        return order;
    }
};

class Restaurant {
private:
    vector<MenuItem> menu;
    unordered_map<string, User> users;
    User *currentUser;

public:
    Restaurant() : currentUser(nullptr) {}

    void addMenuItem(const string &name, double price) {
        MenuItem item = {name, price};
        menu.push_back(item);
    }

    void viewMenu() {
        cout << "\nMenu:\n";
        cout << setw(20) << left << "Item" << setw(10) << "Price" << endl;
        cout << "-----------------------------------\n";
        for (const auto &item : menu) {
            cout << setw(20) << left << item.name << "$" << setw(8) << right << item.price << endl;
        }
    }

    void createUser(const string &username) {
        if (users.find(username) == users.end()) {
            users[username] = User(username);
            cout << "User " << username << " created.\n";
        } else {
            cout << "User " << username << " already exists.\n";
        }
        currentUser = &users[username];
    }

    void assignSeats(int numSeats) {
        if (!currentUser) {
            cout << "No user found. Please create a user first.\n";
            return;
        }
        if (currentUser->addSeats(numSeats)) {
            cout << "Seats assigned successfully. Total seats for " << currentUser->getUsername() << ": " << currentUser->getSeats() << endl;
        } else {
            cout << "Cannot assign more than 4 seats per user.\n";
        }
    }

    void takeOrder() {
        if (!currentUser) {
            cout << "No user found. Please create a user first.\n";
            return;
        }

        if (currentUser->getSeats() == 0) {
            cout << "Please assign seats to the user first.\n";
            return;
        }

        string itemName;
        int quantity;
        char choice;

        do {
            cout << "Enter item name to order: ";
            cin.ignore();
            getline(cin, itemName);

            bool found = false;
            for (const auto &item : menu) {
                if (item.name == itemName) {
                    cout << "Enter quantity: ";
                    cin >> quantity;
                    for (int i = 0; i < quantity; ++i) {
                        currentUser->addOrderItem(item);
                    }
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Item not found in menu.\n";
            }

            cout << "Do you want to order another item? (y/n): ";
            cin >> choice;

        } while (choice == 'y' || choice == 'Y');
    }

    void generateBill() {
        if (!currentUser) {
            cout << "No user found. Please create a user first.\n";
            return;
        }

        double total = 0;
        cout << "\nYour Order:\n";
        cout << setw(20) << left << "Item" << setw(10) << "Price" << endl;
        cout << "-----------------------------------\n";
        for (const auto &item : currentUser->getOrder()) {
            cout << setw(20) << left << item.name << "$" << setw(8) << right << item.price << endl;
            total += item.price;
        }
        cout << "-----------------------------------\n";
        cout << setw(20) << left << "Total" << "$" << setw(8) << right << total << endl;
    }

    ~Restaurant() {
        for (auto &user : users) {
            delete &user.second;
        }
    }
};

int main() {
    Restaurant restaurant;
    int choice;
    string username;
    int seats;

    // Adding some initial items to the menu
    restaurant.addMenuItem("Burger", 5.99);
    restaurant.addMenuItem("Pizza", 8.99);
    restaurant.addMenuItem("Pasta", 7.49);
    restaurant.addMenuItem("Salad", 4.99);

    do {
        cout << "\nRestaurant Management System\n";
        cout << "1. Create User\n";
        cout << "2. Assign Seats\n";
        cout << "3. View Menu\n";
        cout << "4. Take Order\n";
        cout << "5. Generate Bill\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter username: ";
            cin >> username;
            restaurant.createUser(username);
            break;
        case 2:
            cout << "Enter number of seats to assign: ";
            cin >> seats;
            restaurant.assignSeats(seats);
            break;
        case 3:
            restaurant.viewMenu();
            break;
        case 4:
            restaurant.takeOrder();
            break;
        case 5:
            restaurant.generateBill();
            break;
        case 6:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Please enter a number between 1 and 6.\n";
        }
    } while (choice != 6);

    return 0;
}
