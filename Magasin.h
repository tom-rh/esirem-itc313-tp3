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
	std::vector<Produit> getProduits() const;
	void addProduit(Produit _produit);
	void afficheMagasin();
	void trouverProduit(std::string _recherche) const;
	void changerQuantite(int _quantite, std::string _recherche);
};

