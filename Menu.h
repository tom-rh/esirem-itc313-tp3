#pragma once
#include <iostream>
#include "Magasin.h"

class Menu
{
private:
	int _navigation;
	bool _exit;
	int _tempsPause;
	Magasin _easystore;
public:
	Menu();
	void clear();
	void redirectionMenu();
	void principal();
	int gestionCommande();
	int gestionClient();
	int gestionMagasin();
};