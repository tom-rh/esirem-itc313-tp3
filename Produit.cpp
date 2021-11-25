#include "Produit.h"
#include <iostream>

Produit::Produit(std::string produit, int id, std::string description, int qtite, float prix) :
	_nomProduit(produit), _id(id), _description(description), _quantite(qtite), _prix(prix)
{



}


void Produit::setProduit(std::string produit) {

	_nomProduit = produit;
}

void Produit::setDescription(std::string description) {

	_description = description;
}


void Produit::setId(int id) {

	_id = id;
}

void Produit::setQuantite(int quantite) {

	_quantite = quantite;
}

void Produit::setPrix(float prix) {

	_prix = prix;
}


std::string Produit::getNameProduit() const {
	return _nomProduit;
}

std::string Produit::getDescription() const {
	return _description;
}

int Produit::getId() const {
	return _id;
}

int Produit::getQuantite() const {
	return _quantite;
}

float Produit::getPrix() const {
	return _prix;
}

std::ostream& operator<<(std::ostream& os, const Produit& produit)
{
	os << produit.getNameProduit() << " " << produit.getId() << " " << produit.getDescription() << " " << produit.getQtite() << " " << produit.getPrix();
	return os;

}
