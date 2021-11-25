#include "Produit.h"
#include <iostream>

Produit::Produit(int id, std::string nomProduit, std::string description, int qtite, float prix) :
	_id(id), _nomProduit(nomProduit), _description(description), _quantite(qtite), _prix(prix)
{

}

void Produit::setProduit(std::string nomProduit) {

	_nomProduit = nomProduit;
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
	os << "Fiche produit" << std::endl;
	os << "Id : " << produit.getId() << std::endl;
	os << "Nom : " << produit.getNameProduit() << std::endl;
	os << "Description : " << produit.getDescription() << std::endl;
	os << "Quantite : " << produit.getQuantite() << std::endl;
	os << "Prix : " << produit.getPrix() << std::endl;
	return os;
}
