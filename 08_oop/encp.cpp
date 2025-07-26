#include <iostream>
using namespace std;

class BankAccount {
    private:
        string accountNumber;
        double balance;

    public:
        BankAccount(string accNum, double initialBalance){
            accountNumber = accNum;
            balance = initialBalance;
        }

        //getter
        double getBalance() const {
            cout << "Current Balance: " << balance << endl; cout << endl;
            return balance;
        }

        //Method to deposit money
        void deposit(double amount){
            if(amount > 0) {
                balance += amount;
                cout << "amount deposited: " << amount << " /- successfully!" << endl;
                getBalance();
            } else {
                cout << "Invalid deposit amount";
            }
        }

        void withdraw(double amount) {
            if(amount > 0 && amount <= balance){
                balance -= amount;
                cout << "amount withdrawn: " << amount << " /- successfully!" << endl;
                getBalance();
            }else if (amount > balance) {
                cout << "Insufficient balance!" << endl;
                getBalance();
            } else {
                cout << "Invalid withdrawal amount" << endl;
            }
        }
};

int main(){
    BankAccount myAccount("1229988", 500);

    myAccount.getBalance();
    myAccount.deposit(200);
    myAccount.withdraw(100); 
    myAccount.withdraw(700); // Attempting to withdraw more than balance

    return 0;
}