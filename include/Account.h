#ifndef ACCOUNT_H  // Header guard: tránh việc file bị include lặp lại nhiều lần
#define ACCOUNT_H

class Account {
    int balance;
    int totalDeposited;
    int totalWithdrawn;

public:
    Account(); // Constructor
    bool deposit(int money);
    void get_information();
    bool withdrawal(int money);
};

#endif