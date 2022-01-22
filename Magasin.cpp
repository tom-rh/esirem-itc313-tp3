#include "Magasin.h"

Magasin::Magasin(std::string nom) : _nom(nom)
{

}

bool Magasin::addProduit(Produit produit)
{
	_produits.push_back(produit);
	return true;
}

void Magasin::afficheProduits()
{
    for (Produit &produit : _produits)
    {
    	std::cout << produit << std::endl;
    }
}

int Magasin::trouverProduit(std::string nom)
{
	for (Produit &produit : _produits) {
		if (produit.getNomProduit() == nom)
		{
			return produit.getId();
		}
	}
	return 0; // Renvoie 0 si le produit n'est pas trouvé
}

bool Magasin::changerQuantite(int quantite, std::string nom)
{
	getProduit(trouverProduit(nom)).setQuantite(quantite);
	return true;
}

bool Magasin::addClient(Client client)
{
	_clients.push_back(client);
	return true;
}

void Magasin::afficheClients()
{
    for (Client &client : _clients)
    {
        std::cout << client << std::endl;
    }
}

int Magasin::trouverClient(int identifiant)
{
	for (Client &client : _clients)
	{
		if (client.getId() == identifiant)
			return client.getId();
	}
	return 0; // Aucun client trouvé
}

bool Magasin::addProduitToPanier(int idProduit, int idClient)
{
	for (Client &client : _clients)
	{
		if ( idClient == client.getId())
		{
			for (auto i = _produits.begin(); i != _produits.end(); i++)
			{
				if ( idProduit == client.getId())
				{
					client.ajouterProduitPanier((*i));
					return true;
				}
			}
		}
	}
	return false;
}


bool Magasin::suprProduitToPanier(int idProduit, int idClient)
{
	for (Client &client : _clients)
	{
		if ( idClient == client.getId())
		{
			client.supprimerProduitPanier(idProduit);
			return true;
		}
	}
	return false;
}


bool Magasin::qtitProduitToPanier(int idProduit, int idClient, int quantite)
{
	for (Client &client : _clients)
	{
		if ( idClient == client.getId())
		{
			client.modifierQuantiteProduitPanier(idProduit, quantite);
			return true;
		}
	}
	return false;
}

bool Magasin::validerCommande(int idClient)
{
	for (Client &client : _clients) {
		if ( idClient == client.getId())
		{
			_commandes.push_back(Commande(client));
			for (Produit &produit : client.getPanier())
			{
				for (Produit &produitMagasin : _produits)
				{
					if (produit.getId() == produitMagasin.getId())
						changerQuantite((produitMagasin.getQuantite()-produit.getQuantite()), produit.getNomProduit());
				}
			}
			client.viderPanier();
			return true;
		}
	}
	return false;
}

bool Magasin::setStatutCommande(int idCommande, int statut)
{
	if (statut <= 4 && statut >=0) {
		for (Commande &commande : _commandes)
		{
			if (idCommande == commande.getId())
			{
				if (commande.setStatut(statut) == true)
					return true;
			}
    	}
	} 
	return false;
}

void Magasin::afficheCommandes()
{
	for (Commande &commande : _commandes)
	{
        std::cout << commande << std::endl;
    }
}

void Magasin::afficheCommandesClient(int idClient)
{
	for (Commande &commande : _commandes)
	{
		if (idClient == commande.getClient().getId())
        	std::cout << commande << std::endl;
    }
}

std::vector<Commande>& Magasin::getCommandes()
{
	return _commandes;
}

std::vector<Client>& Magasin::getClients()
{
	return _clients;
}

std::vector<Produit>& Magasin::getProduits()
{
	return _produits;
}

Client& Magasin::getClient(int idClient)
{
	for (auto &client : _clients)
	{
		if (idClient == client.getId())
			return client;
	}
}

Produit& Magasin::getProduit(int idProduit)
{
	for (auto &produit : _produits)
	{
		if (idProduit == produit.getId())
			return produit;
	}
}