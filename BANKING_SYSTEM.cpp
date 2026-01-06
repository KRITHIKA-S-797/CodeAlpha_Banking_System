#include <iostream>
#include <string>
using namespace std;
class Account {
private:
    int accountNumber;
    float balance;
public:
    Account(int accNo = 0, float initialBalance = 0.0f)
        : accountNumber(accNo), balance(initialBalance) {}

    int getAccountNumber() const {
        return accountNumber;
    }

    float getBalance() const {
        return balance;
    }

    void deposit(float amount) {
        if (amount <= 0) {
            cout << "Amount must be positive.\n";
            return;
        }
        balance += amount;
        cout << "Money deposited successfully.\n";
        showBalance();
    }

    void withdraw(float amount) {
        if (amount <= 0) {
            cout << "Amount must be positive.\n";
            return;
        }
        if (amount > balance) {
            cout << "Not enough balance!\n";
        } else {
            balance -= amount;
            cout << "Money withdrawn successfully.\n";
            showBalance();
        }
    }

    void showBalance() const {
        cout << "Current Balance: " << balance << endl;
    }
};

class Customer {
private:
    string name;
    Account account;

public:
    Customer(const string& customerName, int accNo, float initialBalance = 0.0f)
        : name(customerName), account(accNo, initialBalance) {}

    void showDetails() const {
        cout << "\nCustomer Name: " << name << endl;
        cout << "Account Number: " << account.getAccountNumber() << endl;
        account.showBalance();
    }

    Account& getAccount() {
        return account;
    }
};

int main() {
    Customer c("Student", 1001, 0.0f);
    int choice = -1;
    float amount;

    cout << "==== Simple Banking System ====\n";

    do {
        cout << "\n1. Deposit";
        cout << "\n2. Withdraw";
        cout << "\n3. View Account Details";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        
        if (!(cin >> choice)) {
            cout << "Invalid input! Exiting.\n";
            break;
        }

        switch (choice) {
        case 1:
            cout << "Enter amount to deposit: ";
            if (cin >> amount) {
                c.getAccount().deposit(amount);
            } else {
                cout << "Invalid amount!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            break;

        case 2:
            cout << "Enter amount to withdraw: ";
            if (cin >> amount) {
                c.getAccount().withdraw(amount);
            } else {
                cout << "Invalid amount!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            break;

        case 3:
            c.showDetails();
            break;
        case 4:
            cout << "Exiting... Thank you.\n";
            break;

        default:
            cout << "Invalid choice!\n";
            break;
        }

    } while (choice != 4);

    return 0;
}
