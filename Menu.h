#pragma once
#include <iostream>

class Menu
{
private:
	int _navigation;
	bool _exit = false;
public:
	Menu();
	void clear();
	void gestionCommande();
	void gestionClient();
	void gestionMagasin();
};