#pragma once
#include <vector>
#include "Service.h"
class Menu {
private:
	Service& service;
public:
	Menu(Service& service);
	~Menu();

	void RunUI();
private:
	void PrintMenu();
	std::vector<std::string> SplitCommand(std::string command);
	
	void UIAddTransaction(std::string day, std::string sum, std::string type, std::string description);
	void UIDeleteTransactions(std::string day);
	void UIChangeTransaction(std::string day, std::string type, std::string description, std::string sum);
	void UIUndoTransaction();

	void UIShowAllTransactions();
};

