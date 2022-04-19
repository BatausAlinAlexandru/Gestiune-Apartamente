#include "Service.h"

Service::Service() : repo(repo) {
};

Service::Service(Repository<Tranzaction>& repo) : repo(repo) {
};

Service::~Service() {
};

void Service::undoTranzactionService()
{
	this->repo.undo();
}

std::vector<Tranzaction> Service::getAll()
{
	return this->repo.getAll();
}
int Service::getIt()
{
	return this->repo.getIt();
}
;

void Service::addTranzactionService(int day, int sum, std::string type, std::string description)
{
	Tranzaction tranzaction(day, sum, type, description);
	this->repo.addElem(tranzaction);
}

void Service::deleteTranzactionService(int day) {
	std::vector<Tranzaction> tranzactions = this->repo.getAll();
	for (Tranzaction t : tranzactions) {
		if (t.getDay() == day) {
			this->repo.deleteElem(t);
		}
			
	}
}
void Service::updateTranzactionService(int day, int sum, std::string type, std::string description) {
	std::vector<Tranzaction> tranzactions = this->repo.getAll();
	for (Tranzaction t : tranzactions) {
		if ((t.getDay() == day) && (t.getType() == type) && (t.getDescription() == description))
			t.setSum(sum);
	}
};
