#pragma once
#include <string>
#include <fstream>
class Tranzaction {
private:
	int day = 0;
	int sum = 0;
	std::string type = "";
	std::string description = "[-]";

public:
	Tranzaction();
	Tranzaction(int zi, int suma, std::string tip, std::string description);
	~Tranzaction();

	int getDay(), getSum(); 
	std::string getType(), getDescription();

	void setDay(int value), setSum(int value), setType(std::string value), setDescription(std::string value);

	Tranzaction& operator=(const Tranzaction& tranzaction);
	bool operator==(const Tranzaction& tranzaction);
	friend std::ostream& operator<<(std::ostream& os, const Tranzaction& tranzaction);
	friend std::istream& operator>>(std::istream& is, Tranzaction& tranzaction);

};

