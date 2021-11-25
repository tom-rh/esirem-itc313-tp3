#pragma once
#include "string"
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
	std::string findProduit(std::vector<Produit> _produits) const;

};

