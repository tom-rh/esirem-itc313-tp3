#pragma once
#include <iostream>
#include "Magasin.h"

class Menu
{
private:
	int _navigation;
	bool _exit;
	Magasin _easystore;
public:
	Menu();
	void clear();
	void principal();
	void gestionCommande();
	void gestionClient();
	void gestionMagasin();
};