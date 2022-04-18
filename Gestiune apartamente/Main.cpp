#include <iostream>
#include "Repository.h"
#include "Tranzaction.h"
#include "Service.h"
int main() {
	Repository<Tranzaction> repo("textfile.txt");
	Service service(repo);
}