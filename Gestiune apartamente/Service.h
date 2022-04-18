#pragma once
#include <vector>
#include "Repository.h"
#include "Tranzaction.h"
class Service {
private:
	Repository<Tranzaction>& repo;

public:
	Service();
	Service(Repository<Tranzaction>& repo);
	~Service();

	std::vector<Tranzaction> getAll();

	// Operations
	void addTranzactionService(int day, int sum, std::string type, std::string description);
};

