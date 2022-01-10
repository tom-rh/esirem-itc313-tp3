#include "Magasin.h"

Magasin::Magasin(std::string nom) : _nom(nom) {

}

void Magasin::addProduit(Produit produit){
	_produits.push_back(produit);
}

void Magasin::afficheMagasin() {
    for (int i=0; i < _produits.size(); i++)
    {
        std::cout << _produits.at(i) << std::endl;
    }
}

void Magasin::trouverProduit(std::string recherche) const {
	for (int i=0; i < _produits.size(); i++) {
		if ( _produits.at(i).getNameProduit() == recherche)
		{
			std::cout << _produits.at(i) << std::endl;
		}
	}
}

void Magasin::changerQuantite(int quantite,std::string recherche){
   for (int i=0; i < _produits.size(); i++) {
		if ( _produits.at(i).getNameProduit() == recherche)
		{
			_produits.at(i).setQuantite(_produits.at(i).getQuantite()+quantite);
		}
    }
}

void Magasin::addClient(Client client){
	_clients.push_back(client);
}

void Magasin::afficheClient() {
    for (int i=0; i < _clients.size(); i++)
    {
        std::cout << _clients.at(i) << std::endl;
    }
}

void Magasin::trouverClient(std::string recherche) const {
	for (int i=0; i < _clients.size(); i++) {
		if ( _clients.at(i).getNom() == recherche)
			std::cout << _produits.at(i) << std::endl;
		else if (_clients.at(i).getId() == std::stoi(recherche))
			std::cout << _produits.at(i) << std::endl;
		else
			std::cout << "Aucun client trouve !" << std::endl;
	}
}

void Magasin::addProduitToPanier(Produit produit,Client client) {
	client.ajouterProduitPanier(produit);
}


void Magasin::suprProduitToPanier(Produit produit,Client client) {
	client.supprimerProduitPanier(produit);
}


void Magasin::qtitProduitToPanier(Produit produit,Client client,int quantite){
	client.modifierQuantiteProduitPanier(produit, quantite);
}

bool Magasin::validerCommande(Client client) {
	// TODO Diminuer la quantité du  produit dans le magasin
	_commandes.push_back(Commande(client, client.getPanier()));
	client.viderPanier();
}

bool Magasin::setStatutCommande(Commande commande, int statut) {
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

void Magasin::afficheCommandes() const {
	for (auto i = 0; i != _commandes.size(); i++) {
        std::cout << _commandes.at(i) << std::endl;
    }
}

void Magasin::afficheCommandesClient(Client client) const {
	for (auto i = 0; i != _commandes.size(); i++) {
		if (client.getId() == _commandes.at(i).getClient().getId())
        	std::cout << _commandes.at(i) << std::endl;
    }
}
