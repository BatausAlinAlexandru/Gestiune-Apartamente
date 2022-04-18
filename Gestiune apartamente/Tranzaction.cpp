#include <iostream>
#include "Tranzaction.h"

Tranzaction::Tranzaction() {
};

Tranzaction::Tranzaction(int day, int sum, std::string type, std::string description) {
	this->day = day, this->sum = sum, this->type = type, this->description = description;
};

Tranzaction::~Tranzaction() {
};

int Tranzaction::getDay() {
	return this->day;
};

int Tranzaction::getSum() {
	return this->sum;
};

std::string Tranzaction::getType() {
	return this->type;
};

std::string Tranzaction::getDescription() {
	return this->description;
};

void Tranzaction::setDay(int value) {
	this->day = value;
};

void Tranzaction::setSum(int value) {
	this->sum = value;
};

void Tranzaction::setType(std::string value) {
	this->type = value;
};

void Tranzaction::setDescription(std::string value) {
	this->description = value;
};

Tranzaction& Tranzaction::operator=(const Tranzaction& tranzaction)
{
	if (this != &tranzaction)
		this->setDay(tranzaction.day), this->setSum(tranzaction.sum), this->setType(tranzaction.type), this->setDescription(tranzaction.description);
	return *this;
};

bool Tranzaction::operator==(const Tranzaction& tranzaction)
{
	return ((this->day == tranzaction.day) && (this->sum == tranzaction.sum) && (this->type == tranzaction.type));
};

std::ostream& operator<<(std::ostream& os, const Tranzaction& tranzaction)
{
	if (tranzaction.description.empty())
		os << tranzaction.day << " " << tranzaction.sum << " " << tranzaction.type << " ";
	else
		os << tranzaction.day << " " << tranzaction.sum << " " << tranzaction.type << " " << tranzaction.description;
	return os;
}

std::istream& operator>>(std::istream& is, Tranzaction& tranzaction)
{
	std::string myDescription;
	is >> tranzaction.day >> tranzaction.sum >> tranzaction.type;
	std::getline(is, myDescription);
	if (myDescription[0] == ' ')
		myDescription.erase(std::remove(myDescription.begin(), myDescription.begin() + 1, ' '), myDescription.begin() + 1);
	
	tranzaction.description = myDescription;
	std::cout << myDescription << std::endl;

	return is;
}
