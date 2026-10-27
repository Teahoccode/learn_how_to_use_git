#include "Account.h"  
#include <iostream>
using namespace std;

// Constructor
Account::Account() {
    balance = 0;
    totalDeposited = 0;
    totalWithdrawn = 0;
}

// deposit
bool Account::deposit(int money) {
    if (money <= 0) return false;
    balance += money;
    totalDeposited += money;
    return true;
}

// get_information
void Account::get_information() {
    cout << "\n--- THONG TIN TAI KHOAN ---" << endl;
    cout << "So du hien tai (Balance): " << balance << endl;
    cout << "Tong tien da nap: " << totalDeposited << endl;
    cout << "Tong tien da rut: " << totalWithdrawn << endl;
}

// withdrawal
bool Account::withdrawal(int money) {
    if (money <= 0 || money > balance) return false;
    balance -= money;
    totalWithdrawn += money;
    return true;
}

