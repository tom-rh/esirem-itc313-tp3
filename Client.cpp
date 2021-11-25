#include "Client.h"

int Client::getId() const {
	return _id;
}

std::string Client::getPrenom() const {
	return _prenom;
}

std::string Client::getNom() const {
	return _nom;
}

std::vector<Produit> Client::getPanier() const {
    return _panier;
}

void Client::ajouterProduit(Produit produit) {
    _panier.push_back(produit);
}