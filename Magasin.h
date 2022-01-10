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
	std::string _nom;
	std::vector<Produit> _produits;
	std::vector<Client> _clients;
	std::vector<Commande> _commandes;

public :
	Magasin(std::string nom);
	void addProduit(Produit produit);
	void afficheMagasin();
	void trouverProduit(std::string recherche) const;
	void changerQuantite(int quantite, std::string recherche);
	void addClient(Client client);
	void afficheClient();
	void trouverClient(std::string recherche) const;
	void addProduitToPanier(Produit produit,Client client);
	void suprProduitToPanier(Produit produit,Client client);
	void qtitProduitToPanier(Produit produit,Client client, int quantite);
	bool validerCommande(Client client);
	bool setStatutCommande(Commande commande, int statut);
	void afficheCommandes() const;
	void afficheCommandesClient(Client client) const;
};

