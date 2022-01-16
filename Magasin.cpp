#include "Magasin.h"

Magasin::Magasin(std::string nom) : _nom(nom)
{

}

bool Magasin::addProduit(Produit produit)
{
	_produits.push_back(produit);
	return true;
}

void Magasin::afficheProduits() const
{
    for (auto i = _produits.begin(); i != _produits.end(); i++)
    {
        std::cout << (*i) << std::endl;
    }
}

int Magasin::trouverProduit(std::string recherche) const
{
	for (auto i = _produits.begin(); i != _produits.end(); i++) {
		if ( (*i).getNameProduit() == recherche)
		{
			return (*i).getId();
		}
	}
	return 0; // Error
}

bool Magasin::changerQuantite(int quantite, std::string recherche)
{
   for (auto i = _produits.begin(); i != _produits.end(); i++) {
		if ( (*i).getNameProduit() == recherche)
		{
			(*i).setQuantite((*i).getQuantite() + quantite);
			return true;
		}
    }
	return false;
}

bool Magasin::addClient(Client client)
{
	_clients.push_back(client);
	return true;
}

void Magasin::afficheClients() const
{
    for (auto i = _clients.begin(); i != _clients.end(); i++)
    {
        std::cout << (*i) << std::endl;
    }
}

int Magasin::trouverClient(std::string recherche) const
{
	for (auto i = _clients.begin(); i != _clients.end(); i++)
	{
		if ( (*i).getNom() == recherche)
			return (*i).getId();
		else if ((*i).getId() == std::stoi(recherche))
			return (*i).getId();
		else
			std::cout << "Aucun client trouve !" << std::endl;
	}
	return 0; // Error
}

bool Magasin::addProduitToPanier(int idProduit, int idClient)
{
	for (std::vector<Client>::iterator it = _clients.begin(); it != _clients.end(); it++)
	{
		if ( idClient == (*it).getId())
		{
			for (auto i = _produits.begin(); i != _produits.end(); i++)
			{
				if ( idProduit == (*i).getId())
				{
					(*it).ajouterProduitPanier((*i));
					return true;
				}
			}
		}
	}
	return false;
}


bool Magasin::suprProduitToPanier(int idProduit, int idClient)
{
	for (std::vector<Client>::iterator it = _clients.begin(); it != _clients.end(); it++) {
		if ( idClient == (*it).getId())
		{
			(*it).supprimerProduitPanier(idProduit);
			return true;
		}
	}
	return false;
}


bool Magasin::qtitProduitToPanier(int idProduit, int idClient, int quantite)
{
	for (std::vector<Client>::iterator it = _clients.begin(); it != _clients.end(); it++) {
		if ( idClient == (*it).getId()){
			(*it).modifierQuantiteProduitPanier(idProduit, quantite);
			return true;
		}
	}
	return false;
}

bool Magasin::validerCommande(int idClient)
{
	// TODO Diminuer la quantité du  produit dans le magasin
	for (std::vector<Client>::iterator it = _clients.begin(); it != _clients.end(); it++) {
		if ( idClient == (*it).getId()){
			_commandes.push_back(Commande((*it)));
			(*it).viderPanier();
			return true;
		}
	}
	return false;
}

bool Magasin::setStatutCommande(int idCommande, int statut)
{
	if (statut <= 4 && statut >=0) {
		for (auto i = _commandes.begin(); i != _commandes.end(); i++) {
			if (idCommande == (*i).getId()) {
				// TODO
				return true;
			}
    	}
	} 
	return false;
}

void Magasin::afficheCommandes() const
{
	for (auto i = _commandes.begin(); i != _commandes.end(); i++) {
        std::cout << (*i) << std::endl;
    }
}

void Magasin::afficheCommandesClient(int idClient) const
{
	for (auto i = _commandes.begin(); i != _commandes.end(); i++) {
		if (idClient == (*i).getClient().getId())
        	std::cout << (*i) << std::endl;
    }
}

std::vector<Commande> Magasin::getCommandes() const
{
	return _commandes;
}

std::vector<Client> Magasin::getClients() const
{
	return _clients;
}

std::vector<Produit> Magasin::getProduits() const
{
	return _produits;
}

Client Magasin::getClient(int idClient)
{
	for (Client &client : _clients)
	{
		if (idClient == client.getId())
			return client;
	}
}