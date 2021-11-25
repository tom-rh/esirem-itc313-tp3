#include "Magasin.h"

Magasin::Magasin(std::string name) : _namemagasin(name) {

}


void Magasin::addProduit(Produit _produit){

_produits.push_back(_produit);
}

void Magasin::afficheMagasin(std::vector<Produit> _produits){

    for (int i=0; i < _produits.size(); i++)
    {
        std::cout << _produits.at(i) << std::endl;
    }
}


std::string Magasin::findProduit(std::vector<Produit> _produits) const{

        std::string _recherche;
        sdt::cin>> _recherche;

        for (int i=0; i < _produits.size(); i++)
    {
        if (_produit == _recherche)
        {
            std::cout << _produits.at(i) << std::endl
        }
    }

}
