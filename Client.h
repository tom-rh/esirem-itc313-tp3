#pragma once
#include <string>
#include <vector>
#include "Produit.h"


class Client
{
private:
    static int _debutId;
    int _id;
	std::string _prenom;
	std::string _nom;
	std::vector<Produit> _panier;
public:
    Client(std::string prenom, std::string nom);
    int getId() const;
    std::string getPrenom() const;
    std::string getNom() const;
    std::vector<Produit> getPanier() const;
    bool ajouterProduitPanier(Produit &produit);
    bool viderPanier();
    bool modifierQuantiteProduitPanier(int idProduit, int quantite);
    bool supprimerProduitPanier(int idProduit);
};

std::ostream& operator<<(std::ostream& os, const Client& client);