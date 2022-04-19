#include <iostream>
#include "Repository.h"
#include "Transaction.h"
#include "Service.h"
#include "Menu.h"
int main() {
	Repository<Transaction> repo("textfile.txt");
	Service service(repo);
	Menu menu(service);
	menu.RunUI();
}