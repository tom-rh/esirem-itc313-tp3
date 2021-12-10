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
	std::vector<Produit> Magasin::getProduits() const;
	void addProduit(Produit _produit);
	void afficheMagasin();
	void trouverProduit(std::string _recherche) const;
	void changerQuantite(int _quantite, std::string _recherche);
	void addClient(Client _client);
	void afficheClient(std::vector<Client> _clients);
	void trouverClient(std::vector<Client> _clients, std::string _recherche) const;
	void addProduitToPanier(Produit _produit,Client _client);

};

