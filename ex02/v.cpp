#include <iostream>
using namespace std;
class BankAccount {
    private:
        int balance;

    public:
        //constructor 
        BankAccount()
        {
            balance = 0;
        }
        ~BankAccount()
        {
            std::cou
        }
        void deposit(int add)
        {
            balance +=add ;
        }
        void  showbalance()
        {
            std::cout << "balance: " << balance;
        }
};


int main()
{
    BankAccount mybank;
    mybank.deposit(1000);
    mybank.showbalance();

    return 0;
}