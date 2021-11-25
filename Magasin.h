#pragma once
#include <string>
#include "Produit.h"
#include <vector>
#include <iostream>

class Magasin
{
private :

	std::string _namemagasin;
	std::vector<Produit> _produits;




public :

	Magasin(std::string _namemagasin);
	void addProduit(Produit _produit);
	void afficheMagasin(std::vector<Produit> _produits);
	void findProduit(std::vector<Produit> _produits,std::string _recherche) const;
	void changeQtite(std::vector<Produit> _produits, int _qtite,std::string _recherche);


};

