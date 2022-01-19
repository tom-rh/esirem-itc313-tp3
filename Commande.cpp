#include "Commande.h"
#include <iostream>

int Commande::_debutId=1;

Commande::Commande(Client client) :
	_id(_debutId++), _client(client), _produitsAchetes(client.getPanier()), _statut(0)
{

}

int Commande::getId() const
{
    return _id;
}

Client& Commande::getClient()
{
    return _client;
}

std::vector<Produit>& Commande::getProduitsAchetes()
{
    return _produitsAchetes;
}

int Commande::getStatut() const
{
    return _statut;
}

std::string Commande::getDescriptionStatut() const
{
    switch (_statut)
    {
    case 0:
        return "Validée";
        break;
    case 1:
        return "Préparée";
        break;
    case 2:
        return "Expédiée";
        break;
    case 3:
        return "Livrée";
        break;
    default:
        return "Erreur";
        break;
    }
}

bool Commande::setStatut(int statut)
{
    if (statut >= 0 && statut <= 3)
    {
        _statut = statut;
        return true;
    }
    else
    {
        return false;
    }
}

std::ostream& operator<<(std::ostream& os, Commande& commande)
{
    os << "Commande :" << std::endl;
    os << "Statut :" << commande.getDescriptionStatut() << std::endl;
	os << "Client : " << commande.getClient() << std::endl;
    os << "Produits achetes : " << std::endl;
    int compteur = 1;
    for (Produit &produit : commande.getProduitsAchetes())
    {
        os << std::endl;
        os << "Produit " << compteur << std::endl;
        os << produit << std::endl;
        compteur++;
    }
	return os;
}