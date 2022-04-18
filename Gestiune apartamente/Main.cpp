#include <iostream>
#include "Repository.h"
#include "Tranzaction.h"

int main() {
	Repository<Tranzaction> repo("textfile.txt");
}