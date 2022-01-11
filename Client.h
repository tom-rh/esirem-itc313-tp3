#pragma once
#include <string>
#include <vector>
#include "Produit.h"


class Client
{
private:
    int _id;
	std::string _prenom;
	std::string _nom;
	std::vector<Produit> _panier;
public:
    Client(int id, std::string prenom, std::string nom);
    int getId() const;
    std::string getPrenom() const;
    std::string getNom() const;
    std::vector<Produit> getPanier() const;
    void ajouterProduitPanier(Produit produit);
    void viderPanier();
    void modifierQuantiteProduitPanier(int idProduit, int quantite);
    void supprimerProduitPanier(int idProduit);
};

std::ostream& operator<<(std::ostream& os, const Client& client);