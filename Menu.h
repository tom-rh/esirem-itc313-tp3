#pragma once
#include <iostream>
#include "Magasin.h"

class Menu
{
private:
	int _navigation;
	bool _exit = false;
	Magasin _easystore = Magasin("easystore");
public:
	Menu();
	void clear();
	void gestionCommande();
	void gestionClient();
	void gestionMagasin();
};