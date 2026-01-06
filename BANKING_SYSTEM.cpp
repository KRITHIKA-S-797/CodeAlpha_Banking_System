// Banking System - CodeAlpha Task 2
#include <iostream>
#include <string>
using namespace std;

class Account {
public:
    int accountNumber;
    double balance;

    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Invalid amount!\n";
            return;
        }
        balance += amount;
        cout << "Money deposited successfully.\n";
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid amount!\n";
            return;
        }
        if (amount > balance) {
            cout << "Not enough balance!\n";
            return;
        }
        balance -= amount;
        cout << "Money withdrawn successfully.\n";
    }

    void showBalance() {
        cout << "Current Balance: $" << balance << endl;
    }
};

class Customer {
public:
    string name;
    Account account;

    void showDetails() {
        cout << "\nCustomer Name: " << name << endl;
        cout << "Account Number: " << account.accountNumber << endl;
        account.showBalance();
    }
};

int main() {
    Customer c;
    cout << "Enter Customer Name: ";
    cin.ignore();
    getline(cin, c.name);

    cout << "Enter Account Number: ";
    cin >> c.account.accountNumber;
    c.account.balance = 0.0;

    int choice = -1;
    double amount;

    while (true) {
        cout << "\n====== Banking Menu ======\n";
        cout << "1. Deposit\n2. Withdraw\n3. View Account Details\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter amount to deposit: $";
                cin >> amount;
                c.account.deposit(amount);
                break;
            case 2:
                cout << "Enter amount to withdraw: $";
                cin >> amount;
                c.account.withdraw(amount);
                break;
            case 3:
                c.showDetails();
                break;
            case 4:
                cout << "Thank you for using the banking system! ALICE
                AL\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
