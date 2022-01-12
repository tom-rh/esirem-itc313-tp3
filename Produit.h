#pragma once
#include <string>

class Produit
{
private:
	static int _debutId;
	int _id;
	std::string _nomProduit;
	std::string _description;
	int _quantite;
	float _prix;
public:
	Produit(std::string nomProduit, std::string description, int quantite, float prix);
	void setNom(std::string produit);
	void setDescription(std::string description);
	void setId(int id);
	void setQuantite(int quantite);
	void setPrix(float prix);
	std::string getNameProduit() const;
	std::string getDescription() const;
	int getId() const;
	int getQuantite() const;
	float getPrix() const;
};

std::ostream& operator<<(std::ostream& os, const Produit& produit);
