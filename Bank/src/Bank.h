#ifndef BANK_H
#define BANK_H

#include <vector>
#include <iostream>
#include <stdexcept> //throw exceptions in case of errors

class Account {
public:
    int current_balance; //current balance of bank account
    int min_balance; //minimum allowed balance of the account
    int max_balance; //the maximum allowed balance of the account
    bool frozen; //indicating whether the account is froze

    Account(int max_bal)
        : current_balance(0), min_balance(0), max_balance(max_bal), frozen(false) {}
};

class Bank {
public:
    Bank(int num_accounts, int max_bal); //initialize the bank with a specified number of accounts, each having a maximum balance 
    ~Bank();

    void printCurrentBalance(int account_id);
    void printMinBalance(int account_id);
    void printMaxBalance(int account_id);
    void freezeAccount(int account_id);
    void unfreezeAccount(int account_id);
    void transfer(int from_id, int to_id, int amount);
    void creditAll(int amount);
    void debitAll(int amount);
    void setMinBalance(int account_id, int min_bal);
    void setMaxBalance(int account_id, int max_bal);

private:
    std::vector<Account> accounts; //store the list of accounts
//healper methods to validate the operations 
    void validateAccount(int account_id); //validates if the account ID is within the valid range
    void validateTransfer(int from_id, int to_id, int amount); //validates the transfer operation
    void validateBalance(int account_id, int new_balance); //validates if the new balance in within the allowed range
};

#endif 

