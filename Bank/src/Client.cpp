#include "Bank.h"
#include <iostream>
#include <sstream> //string stream, allow treat strings as input output streams enabling to perform operations such as extraction insertion and formatting on strung data 

void processCommand(Bank& bank, const std::string& command) {
    std::istringstream iss(command);
    std::string operation;
    iss >> operation;

    try {
        if (operation == "printCurrentBalance") {
            int account_id;
            iss >> account_id;
            bank.printCurrentBalance(account_id);
        } else if (operation == "printMinBalance") {
            int account_id;
            iss >> account_id;
            bank.printMinBalance(account_id);
        } else if (operation == "printMaxBalance") {
            int account_id;
            iss >> account_id;
            bank.printMaxBalance(account_id);
        } else if (operation == "freezeAccount") {
            int account_id;
            iss >> account_id;
            bank.freezeAccount(account_id);
        } else if (operation == "unfreezeAccount") {
            int account_id;
            iss >> account_id;
            bank.unfreezeAccount(account_id);
        } else if (operation == "transfer") {
            int from_id, to_id, amount;
            iss >> from_id >> to_id >> amount;
            bank.transfer(from_id, to_id, amount);
        } else if (operation == "creditAll") {
            int amount;
            iss >> amount;
            bank.creditAll(amount);
        } else if (operation == "debitAll") {
            int amount;
            iss >> amount;
            bank.debitAll(amount);
        } else if (operation == "setMinBalance") {
            int account_id, min_bal;
            iss >> account_id >> min_bal;
            bank.setMinBalance(account_id, min_bal);
        } else if (operation == "setMaxBalance") {
            int account_id, max_bal;
            iss >> account_id >> max_bal;
            bank.setMaxBalance(account_id, max_bal);
        } else {
            std::cout << "Unknown command." << std::endl;
        }
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void Interface() {
	std::cout << "\t" << "Avaliable Commands" << std::endl;
	std::cout << "printCurrentBalance (account_id)" << std::endl;
	std::cout << "printMinBalance (account_id)" << std::endl;
	std::cout << "printMaxBalance (account_id)" << std::endl;
	std::cout << "freezeAccount (account_id)" << std::endl;
	std::cout << "unfreezeAccount (account_id)" << std::endl;
	std::cout << "transfer (from_id) (to_id) (amount)" << std::endl;
	std::cout << "creditAll (amount)" << std::endl;
	std::cout << "debitAll (amount)" << std::endl;
	std::cout << "setMinBalance (account_id) (min_balance)" << std::endl;
	std::cout << "setMaxBalance (account_id) (max_balance)" << std::endl << std::endl;
	std::cout << "Enter any command" << std::endl;	
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <num_accounts> <max_balance>" << std::endl;
        return 1;
    }

    int num_accounts = std::stoi(argv[1]);
    int max_balance = std::stoi(argv[2]);

    Bank bank(num_accounts, max_balance);
    Interface();
    std::string command;
    while (std::getline(std::cin, command)) {
        processCommand(bank, command);
    }

    return 0;
}

