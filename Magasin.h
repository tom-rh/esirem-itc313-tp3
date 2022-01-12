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
	int trouverProduit(std::string recherche) const;
	bool changerQuantite(int quantite, std::string recherche);
	void addClient(Client client);
	void afficheClient();
	int trouverClient(std::string recherche) const;
	bool addProduitToPanier(int idProduit, int idClient);
	bool suprProduitToPanier(int idProduit, int idClient);
	bool qtitProduitToPanier(int idProduit, int idClient, int quantite);
	bool validerCommande(int idClient);
	bool setStatutCommande(int idCommande, int statut);
	void afficheCommandes() const;
	void afficheCommandesClient(int idClient) const;
	std::vector<Commande> getCommandes() const;
};

