#include "Commande.h"
#include <iostream>

Commande::Commande(int id, Client client) :
	_id(id), _client(client), _produitsAchetes(client.getPanier()), _statut(0)
{

}

int Commande::getId() const
{
    return _id;
}

Client Commande::getClient() const
{
    return _client;
}

std::vector<Produit> Commande::getProduitsAchetes() const
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

std::ostream& operator<<(std::ostream& os, const Commande& commande)
{
    os << "Commande :" << std::endl;
    os << "Statut :" << commande.getDescriptionStatut() << std::endl;
	os << "Client : " << commande.getClient() << std::endl;
    os << "Produits achetes : " << std::endl;
    for (auto i = 0; i != commande.getProduitsAchetes().size(); i++)
	{
        os << std::endl;
        os << "Produit " << i+1 << std::endl;
        os << commande.getProduitsAchetes().at(i) << std::endl;
    }
	return os;
}