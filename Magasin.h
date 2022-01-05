#pragma once
#include <string>
#include "Produit.h"
#include <vector>
#include <iostream>
#include "Client.h"
#include "Commande.h"

class Magasin
{
private :
	std::string _namemagasin;
	std::vector<Produit> _produits;
	std::vector<Client> _clients;
	std::vector<Commande> _commandes;

public :
	Magasin(std::string _namemagasin);
	void addProduit(Produit _produit);
	void afficheMagasin();
	void trouverProduit(std::string _recherche) const;
	void changerQuantite(int _quantite, std::string _recherche);
	void addClient(Client _client);
	void afficheClient();
	void trouverClient(std::string _recherche) const;
	void addProduitToPanier(Produit _produit,Client _client);
	void suprProduitToPanier(Produit _produit,Client _client);
	void qtitProduitToPanier(Produit _produit,Client _client, int qtit);
	bool validerCommande(Client _client);
	bool setStatutCommande(Commande _commande, int _statut);
	void afficheCommandes() const;
	void afficheCommandesClient(Client _client) const;
};

