#include "Magasin.h"

Magasin::Magasin(std::string name) : _namemagasin(name) {

}

void Magasin::addProduit(Produit _produit){
	_produits.push_back(_produit);
}

void Magasin::afficheMagasin(std::vector<Produit> _produits) {
    for (int i=0; i < _produits.size(); i++)
    {
        std::cout << _produits.at(i) << std::endl;
    }
}

void Magasin::trouverProduit(std::vector<Produit> _produits,std::string _recherche) const {
	for (int i=0; i < _produits.size(); i++) {
		if ( _produits.at(i).getNameProduit() == _recherche)
		{
			std::cout << _produits.at(i) << std::endl;
		}
	}
}

void Magasin::changerQuantite(std::vector<Produit> _produits, int _quantite,std::string _recherche){
   for (int i=0; i < _produits.size(); i++) {
		if ( _produits.at(i).getNameProduit() == _recherche)
		{
			_produits.at(i).setQuantite(_produits.at(i).getQuantite()+_quantite);
		}
    }
}
