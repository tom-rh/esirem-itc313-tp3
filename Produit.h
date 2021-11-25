#pragma once
#include <string>

class Produit
{
private:
	int _id;
	std::string _nomProduit;
	std::string _description;
	int _quantite;
	float _prix;
public:
	Produit(int id, std::string nomProduit, std::string description, int qtite, float prix);
	void setProduit(std::string _produit);
	void setDescription(std::string _description);
	void setId(int _id);
	void setQuantite(int _quantite);
	void setPrix(float _prix);

	std::string getNameProduit() const;
	std::string getDescription() const;
	int getId() const;
	int getQuantite() const;
	float getPrix() const;
};

std::ostream& operator<<(std::ostream& os, const Produit& produit);
