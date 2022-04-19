#pragma once
#include <vector>
#include "Repository.h"
#include "Transaction.h"
class Service {
private:
	Repository<Transaction>& repo;

public:
	Service();
	Service(Repository<Transaction>& repo);
	~Service();

	

	// Operations
	void addTransactionService(int day, int sum, std::string type, std::string description);
	void deleteTransactionService(int day);
	void changeTransactionService(int day, std::string type, std::string description, int sum);
	void undoTransactionService();
	std::vector<Transaction> getAll();
	int getIt();
};

