#include "Bank.h"
//initialize the banl with  a specified number of account each having a maximum balance 
Bank::Bank(int num_accounts, int max_bal) {
    for (int i = 0; i < num_accounts; ++i) {
        accounts.emplace_back(max_bal); //constructs the object directly in the storage of the vector and initliazes it
    }
}

Bank::~Bank() {}

void Bank::validateAccount(int account_id) {
    if (account_id < 0 || account_id >= accounts.size()) {
        throw std::invalid_argument("Invalid account number.");
    }
}

void Bank::validateTransfer(int from_id, int to_id, int amount) {
    validateAccount(from_id);
    validateAccount(to_id);
    if (accounts[from_id].frozen || accounts[to_id].frozen) {
        throw std::runtime_error("One or both accounts are frozen.");
    }
    if (amount <= 0 || accounts[from_id].current_balance - amount < accounts[from_id].min_balance
        || accounts[to_id].current_balance + amount > accounts[to_id].max_balance) {
        throw std::runtime_error("Invalid transfer amount.");
    }
}

void Bank::validateBalance(int account_id, int new_balance) {
    if (new_balance < accounts[account_id].min_balance || new_balance > accounts[account_id].max_balance) {
        throw std::runtime_error("New balance out of allowed range.");
    }
}

void Bank::printCurrentBalance(int account_id) {
    validateAccount(account_id);
    std::cout << "Current balance: " << accounts[account_id].current_balance << std::endl;
}

void Bank::printMinBalance(int account_id) {
    validateAccount(account_id);
    std::cout << "Minimum balance: " << accounts[account_id].min_balance << std::endl;
}

void Bank::printMaxBalance(int account_id) {
    validateAccount(account_id);
    std::cout << "Maximum balance: " << accounts[account_id].max_balance << std::endl;
}

void Bank::freezeAccount(int account_id) {
    validateAccount(account_id);
    accounts[account_id].frozen = true;
    std::cout << "Account " << account_id << " frozen." << std::endl;
}

void Bank::unfreezeAccount(int account_id) {
    validateAccount(account_id);
    accounts[account_id].frozen = false;
    std::cout << "Account " << account_id << " unfrozen." << std::endl;
}

void Bank::transfer(int from_id, int to_id, int amount) {
    validateTransfer(from_id, to_id, amount);
    accounts[from_id].current_balance -= amount;
    accounts[to_id].current_balance += amount;
    std::cout << "Transfer successful." << std::endl;
}

void Bank::creditAll(int amount) {
    for (auto& account : accounts) {
        if (!account.frozen) {
            validateBalance(&account - &accounts[0], account.current_balance + amount);
            account.current_balance += amount;
        }
    }
    std::cout << "All accounts credited with " << amount << " units." << std::endl;
}

void Bank::debitAll(int amount) {
    for (auto& account : accounts) {
        if (!account.frozen) {
            validateBalance(&account - &accounts[0], account.current_balance - amount);
            account.current_balance -= amount;
        }
    }
    std::cout << "All accounts debited by " << amount << " units." << std::endl;
}

void Bank::setMinBalance(int account_id, int min_bal) {
    validateAccount(account_id);
    if (min_bal > accounts[account_id].current_balance) {
        throw std::runtime_error("Minimum balance exceeds current balance.");
    }
    accounts[account_id].min_balance = min_bal;
    std::cout << "Minimum balance for account " << account_id << " set to " << min_bal << "." << std::endl;
}

void Bank::setMaxBalance(int account_id, int max_bal) {
    validateAccount(account_id);
    if (max_bal < accounts[account_id].current_balance) {
        throw std::runtime_error("Maximum balance is less than current balance.");
    }
    accounts[account_id].max_balance = max_bal;
    std::cout << "Maximum balance for account " << account_id << " set to " << max_bal << "." << std::endl;
}

