#include "Service.h"

Service::Service() : repo(repo) {
};

Service::Service(Repository<Tranzaction>& repo) : repo(repo) {
};

Service::~Service() {
};

std::vector<Tranzaction> Service::getAll()
{
	return this->repo.getAll();
};

void Service::addTranzactionService(int day, int sum, std::string type, std::string description)
{
	Tranzaction tranzaction(day, sum, type, description);
	this->repo.addElem(tranzaction);
}
