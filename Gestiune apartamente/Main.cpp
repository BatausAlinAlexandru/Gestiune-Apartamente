#include <iostream>
#include "Repository.h"
#include "Tranzaction.h"
#include "Service.h"
#include "Menu.h"
int main() {
	Repository<Tranzaction> repo("textfile.txt");
	Service service(repo);
	Menu menu(service);
	menu.RunUI();
}