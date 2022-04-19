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

	

	// Operations
	void addTranzactionService(int day, int sum, std::string type, std::string description);
	void deleteTranzactionService(int day);
	void updateTranzactionService(int day, int sum, std::string type, std::string description);
	void undoTranzactionService();
	std::vector<Tranzaction> getAll();
	int getIt();
};

