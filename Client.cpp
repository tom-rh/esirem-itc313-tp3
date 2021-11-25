#include "Client.h"
#include <iostream>

Client::Client(int id, std::string prenom, std::string nom) :
	_id(id), _prenom(prenom), _nom(nom) {
}

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
	//Supprimer 1 produit du magasin
    _panier.push_back(produit);
}

void Client::viderPanier() {
    _panier.clear();
}

void Client::modifierQuantiteProduitPanier(Produit produit, int quantite) {
	for (std::vector<Produit>::iterator it = _panier.begin() ; it != _panier.end(); ++it) {
		if (produit.getId() == (*it).getId()) {
				//Supprimer quantite produit du magasin
				(*it).setQuantite(quantite);
			break;
		}
	}
}

void Client::supprimerProduitPanier(Produit produit) {
    //TODO
}

std::ostream& operator<<(std::ostream& os, const Client& client)
{
    os << "Fiche client - Numero " << client.getId() << std::endl;
	os << "Prenom et nom : " << client.getPrenom() << " " << client.getNom() << std::endl;
    os << "Panier (" << client.getPanier().size() << ") :" << std::endl;
    if (client.getPanier().empty())
        os << "Vide" << std::endl;
    else {
		for (auto i = 0; i != client.getPanier().size(); i++) {
			os << std::endl;
			os << "Produit " << i+1 << std::endl;
			os << client.getPanier().at(i) << std::endl;
		}
    }
	return os;

}
