#include <iostream>
#include <sstream>
#include "Menu.h"

Menu::Menu(Service& service) : service(service) {
};

Menu::~Menu() {
};

void Menu::RunUI() {
	std::string command;
	bool optiune_gresita;

	while (true) {
		this->PrintMenu();
		std::cout << "Input command: ";
		std::getline(std::cin, command);
		std::vector<std::string> splitedCMD = this->SplitCommand(command);
		optiune_gresita = true;
		if (splitedCMD[0] == "add") {
			if (splitedCMD.size() != 5) {
				std::cout << "Format comanda gresita!" << std::endl;
			}
			else
			{
				this->UIAddTransaction(splitedCMD[1], splitedCMD[2], splitedCMD[3], splitedCMD[4]);
				optiune_gresita = false;
			}
		}
		else if (splitedCMD[0] == "listeaza")
			this->UIShowAllTransactions();
		else if (splitedCMD[0] == "delete")
			this->UIDeleteTransactions(splitedCMD[1]);
		else if (splitedCMD[0] == "change")
			this->UIChangeTransaction(splitedCMD[1], splitedCMD[2], splitedCMD[3], splitedCMD[4]);
		else if (splitedCMD[0] == "undo")
			this->UIUndoTransaction();
		else if (splitedCMD[0] == "exit")
			break;
		else
			std::cout << "Input a valid command." << std::endl;

	}
};

void Menu::PrintMenu() {
	std::cout << "*************************************************" << std::endl;
	std::cout << "*                                               *" << std::endl;
	std::cout << "*  add {day} {sum} {in/out} {[description]}     *" << std::endl;
	std::cout << "*  listeaza                                     *" << std::endl;
	std::cout << "*  delete                                       *" << std::endl;
	std::cout << "*  change {day} {type} {[descrtiption]} {sum}   *" << std::endl;
	std::cout << "*  undo                                         *" << std::endl;
	std::cout << "*  exit                                         *" << std::endl;
	std::cout << "*                                               *" << std::endl;
	std::cout << "*************************************************" << std::endl;
};

std::vector<std::string> Menu::SplitCommand(std::string command)
{
	std::vector<std::string> result;
	std::stringstream ss(command);
	std::string token;
	
	std::string commandString;
	std::string descriptionString;
	std::string description = "[";
	std::string restOfCommand;


	bool ok = false;
	while (std::getline(ss, token, '[')) {
		if (!ok)
			commandString = token, ok = !ok;
		else
			descriptionString = token;
	}

	std::stringstream ss1(descriptionString);
	while (std::getline(ss1, token, ']')) {
		if (ok) {
			descriptionString = token, ok = !ok;
		}
		else {
			restOfCommand = token;
		}
	}
	description += descriptionString;
	description += "]";

	std::stringstream ss2(commandString);
	while (std::getline(ss2, token, ' ')) {
		result.push_back(token);
	}

	result.push_back(description);

	std::stringstream ss3(restOfCommand);
	while (std::getline(ss3, token, ' ')) {
		if(!token.empty())
			result.push_back(token);
	}

	return result;
}

void Menu::UIAddTransaction(std::string day, std::string sum, std::string type, std::string description) {
	this->service.addTransactionService(std::stoi(day), std::stoi(sum), type.c_str(), description.c_str());
}
void Menu::UIDeleteTransactions(std::string day) {
	this->service.deleteTransactionService(std::stoi(day));
}
void Menu::UIChangeTransaction(std::string day, std::string type, std::string description, std::string sum) {
	int day1, sum1;
	try {
		day1 = std::stoi(day);
	}
	catch (...) {
		std::cout << "CRAPA DAY";
	}

	try {
		sum1 = std::stoi(sum);
	}
	catch (...) {
		std::cout << "SUM";
	}
	this->service.changeTransactionService(day1, type, description, sum1);
};

void Menu::UIUndoTransaction()
{	
	if (this->service.getIt() == 0) {
		std::cout << "Nothing to undo!\n";
	}
	else
		this->service.undoTransactionService();
}
;

void Menu::UIShowAllTransactions() {
	std::cout << "\x1B[31m**********************************************\033[0m" << std::endl;
	std::cout << "\x1B[32m";
	std::vector<Transaction> Transactions = this->service.getAll();
	for (int i = 0; i < Transactions.size(); i++)
		std::cout << "\t" << Transactions[i] << std::endl;
	std::cout << "\033[0m";
	std::cout << "\x1B[31m**********************************************\033[0m" << std::endl;

};
