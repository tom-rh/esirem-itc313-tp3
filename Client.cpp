#include "Client.h"
#include <iostream>

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

void Client::ajouterProduitPanier(Produit produit) {
    _panier.push_back(produit);
}

std::ostream& operator<<(std::ostream& os, const Client& client)
{
    os << "Fiche client n°" << client.getId();
	os << "Prénom et nom : " << client.getPrenom() << " " << client.getNom();
    os << "Panier :";
    if (client.getPanier().empty())
        os << "Vide";
    else {
        for (Produit i: client.getPanier())
            std::cout << i << ' ';
    }
	return os;

}
