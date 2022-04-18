#include "Repository.h"

template <typename T>
Repository<T>::Repository(const std::string fileName) {
	this->fileName = fileName;
}