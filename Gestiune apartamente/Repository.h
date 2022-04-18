#pragma once
#include <vector>
#include <string>

template <class T>
class Repository {
private:
	std::vector<T> vector;
	std::string fileName;
public:

	Repository(const std::string fileName);
	~Repository();

private:
	void loadFromFile();
	void saveToFile();
};

