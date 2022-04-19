#include "Service.h"

Service::Service() : repo(repo) {
};

Service::Service(Repository<Transaction>& repo) : repo(repo) {
};

Service::~Service() {
};

void Service::undoTransactionService()
{
	this->repo.undo();
}

std::vector<Transaction> Service::getAll()
{
	return this->repo.getAll();
}
int Service::getIt()
{
	return this->repo.getIt();
}
;

void Service::addTransactionService(int day, int sum, std::string type, std::string description)
{
	Transaction Transaction(day, sum, type, description);
	this->repo.addElem(Transaction);
}

void Service::deleteTransactionService(int day) {
	std::vector<Transaction> Transactions = this->repo.getAll();
	for (Transaction t : Transactions) {
		if (t.getDay() == day) {
			this->repo.deleteElem(t);
		}
			
	}
}
void Service::changeTransactionService(int day, std::string type, std::string description, int sum) {
	Transaction newElem(day, sum, type, description);
	std::vector<Transaction> Transactions = this->repo.getAll();
	for (Transaction t : Transactions) {
		std::cout << t.getDay();
		if ((t.getDay() == day) && (t.getType() == type) && (t.getDescription() == description))
			this->repo.updateElem(t, newElem);
	}
};
