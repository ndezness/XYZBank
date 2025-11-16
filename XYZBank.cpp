#include <iostream>
using namespace std;

class Account 
{
private:
    double balance = 0;

public:
    double Deposit(double amount);  
    double Withdraw(double amount); 
    double GetBalance();
    void SetBalance(double amount); 
    
    // Constructor
    Account(double init_balance) 
    {
        if (init_balance>= 1000) 
        {
            balance = init_balance;
        } else 
        {
            balance = 0;
            cout << "Warning! The initial balance is invalid.Please enter $1000 or more." << endl;
        }
    }
};

    // Deposit Function
   double Account::Deposit(double amount) {
        if (amount > 0)
        {
            balance= balance + amount;
            cout <<amount<< " deposited successfully.";
        } 
       else {
       cout << "Invalid amount. Deposit failed." << endl;
           
       }
       return balance;
   }
       // no else needed since we cant put $0 in an Atm
    
// Withdraw Function
    double Account::Withdraw(double amount) 
    {
        if (amount <= balance ) 
        {
            balance= balance - amount;
            cout << "transaction completed" << endl;
        }
        else 
        {
            cout << " amount exceeded account balance." << endl;
        }
        return balance;
    }
    
    

    // GetBalance Function
    double Account::GetBalance() 
    {
        return balance;
    }
    
    //SetBalance Function
    void Account::SetBalance(double amount) {
        balance = amount;
        cout << "Balance has been updated to $" << balance << endl;
}

int main()
 {
    double init_balance;
    cout << "Enter initial account balance: ";
    cin >> init_balance;

    // Create account object
    Account myaccount(init_balance);

    int choice;
    double amount;

    // ATM MENU LOOP
    while (true) 
    {
        cout << "\n===== XYZ BANK ATM MENU =====" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
         {
        case 1:
            cout << "Current Balance: $" << myaccount.GetBalance() << endl;
            break;

        case 2:
            cout << "Enter amount to deposit: ";
            cin >> amount;
            myaccount.Deposit(amount);
            break;

        case 3:
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            myaccount.Withdraw(amount);
            break;

        case 4:
            cout << "Thank you for using XYZ Bank ATM" << endl;
            return 0;

        default:
            cout << "Invalid choice. Please try again." << endl; }
    }
 }