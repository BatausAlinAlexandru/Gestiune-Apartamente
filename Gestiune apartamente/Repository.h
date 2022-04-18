#include <vector>
#include <string>

template <class T> 
class Repository {
private:
	std::vector<T> vector;
	std::string fileName;
public:
	Repository();
	Repository(const std::string fileName);
	~Repository();

	int getLenght();

	void addElem(const T& elem);
	void updateElem(const T& oldElem, const T& newElem);
	void deleteElem(const T& elem);

private:
	void loadFromFile();
	void saveToFile();
};

template<class T> inline Repository<T>::Repository() {
	this->fileName = "";
};

template<class T> inline Repository<T>::Repository(const std::string fileName) {
	this->fileName = fileName;
};

template<class T> inline Repository<T>::~Repository() = default;

template<class T> inline int Repository<T>::getLenght() {
	return this->vector.size();
};

template<class T> inline void Repository<T>::addElem(const T& elem) {
	this->vector.push_back(elem);

	// After every push_back we need to update the file
	this->saveToFile();
};

template<class T> inline void Repository<T>::updateElem(const T& oldElem, const T& newElem) {
	for (int i = 0; i < this->getLenght(); i++) {
		if (this->vector[i] == oldElem)
			this->vector[i] = newElem;
	}

	// After every push_back we need to update the file
	this->saveToFile();
};

template<class T> inline void Repository<T>::deleteElem(const T& elem) {
	for (int i = 0; i < this->getLenght(); i++) {
		if (this->vector[i] == elem)
			this->vector[i].erase();
	}
	// After every push_back we need to update the file
	this->saveToFile();
};
