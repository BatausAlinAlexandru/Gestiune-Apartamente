#include <iostream>
#include "Transaction.h"

Transaction::Transaction() {
};

Transaction::Transaction(int day, int sum, std::string type, std::string description) {
	this->day = day, this->sum = sum, this->type = type, this->description = description;
};

Transaction::~Transaction() {
};

int Transaction::getDay() {
	return this->day;
};

int Transaction::getSum() {
	return this->sum;
};

std::string Transaction::getType() {
	return this->type;
};

std::string Transaction::getDescription() {
	return this->description;
};

void Transaction::setDay(int value) {
	this->day = value;
};

void Transaction::setSum(int value) {
	this->sum = value;
};

void Transaction::setType(std::string value) {
	this->type = value;
};

void Transaction::setDescription(std::string value) {
	this->description = value;
};

Transaction& Transaction::operator=(const Transaction& Transaction)
{
	if (this != &Transaction)
		this->setDay(Transaction.day), this->setSum(Transaction.sum), this->setType(Transaction.type), this->setDescription(Transaction.description);
	return *this;
};

bool Transaction::operator==(const Transaction& Transaction)
{
	return ((this->day == Transaction.day) && (this->sum == Transaction.sum) && (this->type == Transaction.type));
};

std::ostream& operator<<(std::ostream& os, const Transaction& Transaction)
{
	if (Transaction.description.empty())
		os << Transaction.day << " " << Transaction.sum << " " << Transaction.type << " [-]";
	else
		os << Transaction.day << " " << Transaction.sum << " " << Transaction.type << " " << Transaction.description;
	return os;
}

std::istream& operator>>(std::istream& is, Transaction& Transaction)
{
	std::string myDescription;
	is >> Transaction.day >> Transaction.sum >> Transaction.type;
	std::getline(is, myDescription);
	if (myDescription[0] == ' ')
		myDescription.erase(std::remove(myDescription.begin(), myDescription.begin() + 1, ' '), myDescription.begin() + 1);
	
	Transaction.description = myDescription;
	//std::cout << myDescription << std::endl;

	return is;
}
