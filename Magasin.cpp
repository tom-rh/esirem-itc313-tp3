#include "Magasin.h"

Magasin::Magasin(std::string nom) : _nom(nom)
{

}

void Magasin::addProduit(Produit produit)
{
	_produits.push_back(produit);
}

void Magasin::afficheMagasin()
{
    for (int i=0; i < _produits.size(); i++)
    {
        std::cout << _produits.at(i) << std::endl;
    }
}

int Magasin::trouverProduit(std::string recherche) const
{
	for (int i=0; i < _produits.size(); i++) {
		if ( _produits.at(i).getNameProduit() == recherche)
		{
			return _produits.at(i).getId();
		}
	}
}

bool Magasin::changerQuantite(int quantite, std::string recherche)
{
   for (int i=0; i < _produits.size(); i++) {
		if ( _produits.at(i).getNameProduit() == recherche)
		{
			_produits.at(i).setQuantite(_produits.at(i).getQuantite() + quantite);
			return true;
		}
		else
			return false;
    }
}

void Magasin::addClient(Client client)
{
	_clients.push_back(client);
}

void Magasin::afficheClient()
{
    for (int i=0; i < _clients.size(); i++)
    {
        std::cout << _clients.at(i) << std::endl;
    }
}

int Magasin::trouverClient(std::string recherche) const
{
	for (int i=0; i < _clients.size(); i++) {
		if ( _clients.at(i).getNom() == recherche)
			return _produits.at(i).getId();
		else if (_clients.at(i).getId() == std::stoi(recherche))
			return _produits.at(i).getId();
		else
			std::cout << "Aucun client trouve !" << std::endl;
	}
}

bool Magasin::addProduitToPanier(Produit produit, int idClient)
{
	for (std::vector<Client>::iterator it = _clients.begin(); it != _clients.end(); it++) {
		if ( idClient == (*it).getId()){
			(*it).ajouterProduitPanier(produit);
			return true;
		}
		else
			return false;
	}
}


bool Magasin::suprProduitToPanier(int idProduit, int idClient)
{
	for (std::vector<Client>::iterator it = _clients.begin(); it != _clients.end(); it++) {
		if ( idClient == (*it).getId()){
			(*it).supprimerProduitPanier(idProduit);
			return true;
		}
		else
			return false;
	}
}


bool Magasin::qtitProduitToPanier(int idProduit, int idClient, int quantite)
{
	for (std::vector<Client>::iterator it = _clients.begin(); it != _clients.end(); it++) {
		if ( idClient == (*it).getId()){
			(*it).modifierQuantiteProduitPanier(idProduit, quantite);
			return true;
		}
		else
			return false;
	}
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
		else
			return false;
	}
}

bool Magasin::setStatutCommande(Commande commande, int statut)
{
	if (statut <= 4 && statut >=0) {
		for (auto i = 0; i != _commandes.size(); i++) {
			/*if (i == _commandes.at(i)) {
				// TODO
				return true;
			}*/
    	}
	} 
	else {
		return false;
	}
}

void Magasin::afficheCommandes() const
{
	for (auto i = 0; i != _commandes.size(); i++) {
        std::cout << _commandes.at(i) << std::endl;
    }
}

void Magasin::afficheCommandesClient(int idClient) const
{
	for (auto i = 0; i != _commandes.size(); i++) {
		if (idClient == _commandes.at(i).getClient().getId())
        	std::cout << _commandes.at(i) << std::endl;
    }
}
