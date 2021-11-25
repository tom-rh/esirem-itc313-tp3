#include "Produit.h"
#include <iostream>

Produit::Produit(std::string produit, double id, std::string description, double qtite, float prix) :
	_produit(produit), _id(id), _description(description), _qtite(qtite), _prix(prix)
{



}


void Produit::setProduit(std::string produit) {

	_produit = produit;
}

void Produit::setDescription(std::string description) {

	_description = description;
}


void Produit::setId(double id) {

	_id = id;
}

void Produit::setQtite(double qtite) {

	_qtite = qtite;
}

void Produit::setPrix(float prix) {

	_prix = prix;
}


std::string Produit::getProduit() const {
	return _produit;
}

std::string Produit::getDescription() const {
	return _description;
}

double Produit::getId() const {
	return _id;
}

double Produit::getQtite() const {
	return _qtite;
}

float Produit::getPrix() const {
	return _prix;
}

std::ostream& operator<<(std::ostream& os, const Produit& produit)
{
	os << produit.getProduit() << " " << produit.getId() << " " << produit.getDescription() << " " << produit.getQtite() << " " << produit.getPrix();
	return os;

}
