#pragma once
#include <string>
#include "Produit.h"
#include <vector>
#include <iostream>
#include "Client.h"

class Magasin
{
private :
	std::string _namemagasin;
	std::vector<Produit> _produits;
	std::vector<Client> _clients;

public :
	Magasin(std::string _namemagasin);
	void addProduit(Produit _produit);
	void afficheMagasin(std::vector<Produit> _produits);
	void trouverProduit(std::vector<Produit> _produits, std::string _recherche) const;
	void changerQuantite(std::vector<Produit> _produits, int _quantite, std::string _recherche);
	void addClient(Client _client);
	void afficheClient(std::vector<Client> _clients);
	void trouverClient(std::vector<Client> _clients, std::string _recherche) const;
	void addProduitToPanier(Produit _produit,Client _client);

};

