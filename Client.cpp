#include "Client.h"
#include <iostream>

int Client::_debutId=1;

Client::Client(std::string prenom, std::string nom) :
	_id(_debutId++), _prenom(prenom), _nom(nom)
{

}

int Client::getId() const
{
	return _id;
}

std::string Client::getPrenom() const
{
	return _prenom;
}

std::string Client::getNom() const
{
	return _nom;
}

std::vector<Produit> Client::getPanier() const
{
    return _panier;
}

bool Client::ajouterProduitPanier(Produit produit)
{
    _panier.push_back(produit);
	return true;
}

bool Client::viderPanier()
{
    _panier.clear();
	return true;
}

bool Client::modifierQuantiteProduitPanier(int idProduit, int quantite)
{
	for (Produit &produit : _panier)
	{
		if (idProduit == produit.getId()) {
			produit.setQuantite(quantite);
			return true;
		}
	}
	return false;
}

bool Client::supprimerProduitPanier(int idProduit) {
    for (std::vector<Produit>::iterator it = _panier.begin() ; it != _panier.end(); ++it)
	{
		if (idProduit == (*it).getId()) {
			_panier.erase(it);
			return true;
		}
	}
	return false;
}

std::ostream& operator<<(std::ostream& os, const Client& client)
{
    os << "Fiche client - Numero " << client.getId() << std::endl;
	os << "Prenom et nom : " << client.getPrenom() << " " << client.getNom() << std::endl;
    os << "Panier (" << client.getPanier().size() << ") :" << std::endl;
    if (client.getPanier().empty())
        os << "Vide" << std::endl;
    else {
		for (auto i = 0; i < client.getPanier().size(); i++) {
			os << std::endl;
			os << "Produit " << i+1 << std::endl;
			os << client.getPanier().at(i) << std::endl;
		}
    }
	return os;

}
