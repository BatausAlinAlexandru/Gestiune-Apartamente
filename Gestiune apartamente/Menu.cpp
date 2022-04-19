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
		if (splitedCMD[0] == "adauga") {
			if (splitedCMD.size() != 5) {
				std::cout << "Format comanda gresita!" << std::endl;
			}
			else
			{
				this->UIAddTranzaction(splitedCMD[1], splitedCMD[2], splitedCMD[3], splitedCMD[4]);
				optiune_gresita = false;
			}
		}
		else if (splitedCMD[0] == "listeaza")
			this->UIShowAllTranzactions();
		else if (splitedCMD[0] == "delete")
			this->UIDeleteTranzactions(splitedCMD[1]);
		else if (splitedCMD[0] == "undo")
			this->UIUndoTranzaction();
		else if (splitedCMD[0] == "exit")
			break;
		else
			std::cout << "Input a valid command." << std::endl;

	}
};

void Menu::PrintMenu() {
	std::cout << "**********************************************" << std::endl;
	std::cout << "*                                            *" << std::endl;
	std::cout << "*  add {day} {sum} {in/out} {[description]}  *" << std::endl;
	std::cout << "*  listeaza                                  *" << std::endl;
	std::cout << "*  delete                                    *" << std::endl;
	std::cout << "*  undo                                      *" << std::endl;
	std::cout << "*  exit                                      *" << std::endl;
	std::cout << "*                                            *" << std::endl;
	std::cout << "**********************************************" << std::endl;
};

std::vector<std::string> Menu::SplitCommand(std::string command)
{
	std::vector<std::string> result;
	std::stringstream ss(command);
	std::string token;

	std::string descriptionString;

	bool merge = true;
	while (std::getline(ss, token, ' ') && merge)
	{
		if (token[0] == '[')
			merge = false;
		else
			result.push_back(token);
	}

	bool pentru_for = false;
	for (int i = 0; command[i] != '\0'; i++) {
		if (command[i] == '[' || pentru_for)
			descriptionString.push_back(command[i]), pentru_for = true;
		if (command[i] == ']')
			pentru_for = false;
	}




	result.push_back(descriptionString);
	return result;
}

void Menu::UIAddTranzaction(std::string day, std::string sum, std::string type, std::string description) {
	this->service.addTranzactionService(std::stoi(day), std::stoi(sum), type.c_str(), description.c_str());
}
void Menu::UIDeleteTranzactions(std::string day) {
	this->service.deleteTranzactionService(std::stoi(day));
}
void Menu::UIUndoTranzaction()
{	
	if (this->service.getIt() == 0) {
		std::cout << "Nothing to undo!\n";
	}
	else
		this->service.undoTranzactionService();
}
;

void Menu::UIShowAllTranzactions() {
	std::cout << "\x1B[31m**********************************************\033[0m" << std::endl;
	std::cout << "\x1B[32m";
	std::vector<Tranzaction> tranzactions = this->service.getAll();
	for (int i = 0; i < tranzactions.size(); i++)
		std::cout << "\t" << tranzactions[i] << std::endl;
	std::cout << "\033[0m";
	std::cout << "\x1B[31m**********************************************\033[0m" << std::endl;

};
