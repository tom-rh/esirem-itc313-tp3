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
    int getId() const;
    std::string getPrenom() const;
    std::string getNom() const;
    std::vector<Produit> getPanier() const;
    void ajouterProduitPanier(Produit produit);

std::ostream& operator<<(std::ostream& os, const Client& client);