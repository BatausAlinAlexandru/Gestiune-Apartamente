#pragma once
#include <fstream>
#include <vector>
#include <string>
#include <iostream>

template <class T> class Repository {
private:
	std::vector<T> vector;
	std::string fileName;
	std::string originalFileName;
	int it;
public:
	Repository();
	Repository(const std::string fileName);
	~Repository();

	std::vector<T> getAll();

	int getLenght();

	void addElem(const T& elem);
	void updateElem(const T& oldElem, const T& newElem);
	void deleteElem(const T& elem);

	void undo();
	void updateFileName();
	int getIt();
private:
	void loadFromFile();
	void saveToFile();
};

template<class T> inline Repository<T>::Repository() {
	this->fileName = "";
};

template<class T> inline Repository<T>::Repository(const std::string fileName) {
	this->originalFileName = fileName;
	
	std::ifstream file("iterator.txt");
	file >> this->it;
	file.close();

	char buffer[10];
	this->fileName = this->originalFileName.substr(0, this->originalFileName.size() - 4);
	_itoa_s(it, buffer, 10);
	this->fileName.append(buffer);
	this->fileName.append(".txt");

	std::ifstream in(this->fileName);
	if (!in.good()) {
		std::ofstream out(this->fileName);
		out.close();
	}
	in.close();
};

template<class T> inline Repository<T>::~Repository() = default;

template<class T> inline std::vector<T> Repository<T>::getAll() {
	this->loadFromFile();
	return this->vector;
}

template<class T> inline int Repository<T>::getLenght() {
	this->loadFromFile();
	return this->vector.size();
};

template<class T> inline void Repository<T>::addElem(const T & elem) {
	this->loadFromFile();
	this->vector.push_back(elem);

	this->updateFileName();
	// After every push_back we need to update the file
	this->saveToFile();
};

template<class T> inline void Repository<T>::updateElem(const T & oldElem, const T & newElem) {
	this->loadFromFile();
	for (int i = 0; i < this->getLenght(); i++) {
		if (this->vector[i] == oldElem)
			this->vector[i] = newElem;
	}
	
	this->updateFileName();
	// After every push_back we need to update the file
	this->saveToFile();
};

template<class T> inline void Repository<T>::deleteElem(const T & elem) {
	this->loadFromFile();
	typename std::vector<T>::iterator it = find(this->vector.begin(), this->vector.end(), elem);
	if (it != this->vector.end())
		this->vector.erase(it);

	this->updateFileName();
	// After every push_back we need to update the file
	this->saveToFile();
}

template<class T> inline void Repository<T>::undo() {
	this->it--;

	std::ofstream outIt("iterator.txt");
	outIt << this->it;
	outIt.close();

	char buffer[10];
	this->fileName = this->originalFileName.substr(0, this->originalFileName.size() - 4);
	_itoa_s(it, buffer, 10);
	this->fileName.append(buffer);
	this->fileName.append(".txt");

	this->vector.clear();
}

template<class T> void Repository<T>::updateFileName() {
	std::ifstream file("iterator.txt");
	file >> this->it;
	file.close();

	this->it++;
	char buffer[10];
	this->fileName = this->originalFileName.substr(0, this->originalFileName.size() - 4);
	_itoa_s(it, buffer, 10);
	this->fileName.append(buffer);
	this->fileName.append(".txt");

	std::ifstream in(this->fileName);
	if (!in.good()) {
		std::ofstream out(this->fileName);
		out.close();
	}
	in.close();

	std::ofstream outIt("iterator.txt");
	outIt << this->it;
	outIt.close();
}

template<class T>
inline int Repository<T>::getIt()
{
	return this->it;
}

template<class T> void Repository<T>::loadFromFile() {
	this->vector.clear();
	if (this->fileName.empty()) {
		std::cout << "The file is empty !!!! \n";
	}
	else {
		std::ifstream file(this->fileName);
		T element;

		while (!file.eof()) {
			file >> element;
			if (!(element == T()))
				this->vector.push_back(element);
		}
		file.close();
	}
};

template<class T> void Repository<T>::saveToFile() {
	if (this->fileName.empty()) {
		std::cout << "I can't save to file\n";
	}
	else {
		std::ofstream file(this->fileName);

		for (int i = 0; i < this->vector.size(); i++)
			if (i < this->vector.size() - 1)
				file << this->vector[i] << '\n';
			else
				file << this->vector[i];
		file.close();
	}
};