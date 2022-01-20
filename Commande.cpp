#include "Commande.h"
#include <iostream>

int Commande::_debutId=1;

Commande::Commande(Client &client) :
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
        return "Validee";
        break;
    case 1:
        return "Preparee";
        break;
    case 2:
        return "Expediee";
        break;
    case 3:
        return "Livree";
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
    os << "Statut : " << commande.getDescriptionStatut() << std::endl;
	os << "Client : " << std::endl;
	os << "ID Client : " << commande.getClient().getId() << std::endl;
	os << "Prenom Client : " << commande.getClient().getPrenom() << std::endl;
	os << "Nom Client : " << commande.getClient().getNom() << std::endl;
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