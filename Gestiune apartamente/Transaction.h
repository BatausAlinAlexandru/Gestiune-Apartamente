#pragma once
#include <string>
#include <fstream>
class Transaction {
private:
	int day = 0;
	int sum = 0;
	std::string type = "";
	std::string description = "[-]";

public:
	Transaction();
	Transaction(int zi, int suma, std::string tip, std::string description);
	~Transaction();

	int getDay(), getSum(); 
	std::string getType(), getDescription();

	void setDay(int value), setSum(int value), setType(std::string value), setDescription(std::string value);

	Transaction& operator=(const Transaction& Transaction);
	bool operator==(const Transaction& Transaction);
	friend std::ostream& operator<<(std::ostream& os, const Transaction& Transaction);
	friend std::istream& operator>>(std::istream& is, Transaction& Transaction);

};

