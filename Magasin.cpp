#include "Magasin.h"

Magasin::Magasin(std::string name) : _namemagasin(name) {

}

void Magasin::addProduit(Produit _produit){
	_produits.push_back(_produit);
}

void Magasin::afficheMagasin() {
    for (int i=0; i < _produits.size(); i++)
    {
        std::cout << _produits.at(i) << std::endl;
    }
}

void Magasin::trouverProduit(std::string _recherche) const {
	for (int i=0; i < _produits.size(); i++) {
		if ( _produits.at(i).getNameProduit() == _recherche)
		{
			std::cout << _produits.at(i) << std::endl;
		}
	}
}

void Magasin::changerQuantite(int _quantite,std::string _recherche){
   for (int i=0; i < _produits.size(); i++) {
		if ( _produits.at(i).getNameProduit() == _recherche)
		{
			_produits.at(i).setQuantite(_produits.at(i).getQuantite()+_quantite);
		}
    }
}

void Magasin::addClient(Client _client){
	_clients.push_back(_client);
}


void Magasin::afficheClient(std::vector<Client> _clients) {
    for (int i=0; i < _clients.size(); i++)
    {
        std::cout << _clients.at(i) << std::endl;
    }
}


void Magasin::trouverClient(std::vector<Client> _clients,std::string _recherche) const {

	int rch;

	for (int i=0; i < _clients.size(); i++) {
		if ( _clients.at(i).getNom() == _recherche)
		{
			std::cout << _produits.at(i) << std::endl;
		}
		
		else if (_clients.at(i).getId() == (rch=std::stoi(_recherche)))
		{
			std::cout << _produits.at(i) << std::endl;
		}

		else{
			std::cout << "aucun client correspondant" << std::endl;
		}
}
}


void Magasin::addProduitToPanier(Produit _produit,Client _client){

	_client.ajouterProduitPanier(_produit);
}