#include <iostream>
#include <cstdlib>
#include <cstring>
#include <limits> // Include the <limits> header for numeric_limits
using namespace std;

class Bank {
private:
    string name;
    long long accnumber;
    char type[10];
    long long amount = 0;
    long long tot = 0;

public:
    void setvalue() {
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Account number: ";
        while (!(cin >> accnumber) || cin.peek() != '\n') {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Enter a valid integer for Account number: ";
        }

        cout << "Enter Account type: ";
        cin.ignore(); // Ignore the newline character left in the buffer
        cin.getline(type, 10);

        cout << "Enter Balance: ";
        while (!(cin >> tot) || cin.peek() != '\n') {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Enter a valid integer for Balance: ";
        }
    }

    void showdata() {
        cout << "Name: " << name << endl;
        cout << "Account No: " << accnumber << endl;
        cout << "Account type: " << type << endl;
        cout << "Balance: " << tot << endl;
    }

    void deposit() {
        cout << "\nEnter amount to be Deposited: ";
        while (!(cin >> amount) || cin.peek() != '\n') {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Enter a valid integer for Deposit amount: ";
        }
    }

    void showbal() {
        tot = tot + amount;
        cout << "\nTotal balance is: " << tot;
    }

    void withdrawl() {
        int a, avai_balance;
        cout << "Enter amount to withdraw: ";
        while (!(cin >> a) || cin.peek() != '\n') {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Enter a valid integer for Withdraw amount: ";
        }
        avai_balance = tot - a;
        cout << "Available Balance is: " << avai_balance;
    }
};

int main() {
    Bank b;
    int choice;

    while (1) {
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~"
            << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
            << "~~~WELCOME~~~~~~~~~~~~~~~~~~"
            << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
            << "~~~~~~~~~\n\n";
        cout << "Enter Your Choice\n";
        cout << "\t1. Enter name, Account number, Account type\n";
        cout << "\t2. Balance Enquiry\n";
        cout << "\t3. Deposit Money\n";
        cout << "\t4. Show Total balance\n";
        cout << "\t5. Withdraw Money\n";
        cout << "\t6. Cancel\n";
        cin >> choice;

        switch (choice) {
        case 1:
            b.setvalue();
            break;
        case 2:
            b.showdata();
            break;
        case 3:
            b.deposit();
            break;
        case 4:
            b.showbal();
            break;
        case 5:
            b.withdrawl();
            break;
        case 6:
            exit(1);
            break;
        default:
            cout << "\nInvalid choice\n";
        }
    }
}

