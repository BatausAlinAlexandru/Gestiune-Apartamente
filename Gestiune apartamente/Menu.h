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
	
	void UIAddTranzaction(std::string day, std::string sum, std::string type, std::string description);
	void UIDeleteTranzactions(std::string day);

	void UIUndoTranzaction();

	void UIShowAllTranzactions();
};

