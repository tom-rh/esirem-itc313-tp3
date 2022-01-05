#include "Commande.h"
#include <iostream>

Commande::Commande(Client client, std::vector<Produit> produitsAchetes) :
	_client(client), _produitsAchetes(produitsAchetes), _statut(0)
{

}

Client Commande::getClient() const {
    return _client;
}

std::vector<Produit> Commande::getProduitsAchetes() const{
    return _produitsAchetes;
}

int Commande::getStatut() const{
    return _statut;
}

std::ostream& operator<<(std::ostream& os, const Commande& commande)
{
    os << "Commande :" << std::endl;
	os << "Client : " << commande.getClient() << std::endl;
    os << "Produits achetés : " << std::endl;
    for (auto i = 0; i != commande.getProduitsAchetes().size(); i++) {
        os << std::endl;
        os << "Produit " << i+1 << std::endl;
        os << commande.getProduitsAchetes().at(i) << std::endl;
    }
	return os;
}