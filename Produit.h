#pragma once
#include <string>

class Produit
{

private:

	std::string _nomProduit;
	std::string _description;
	double _qtite;
	float _prix;
	double _id;


public:

	Produit(std::string _produit, int _id, std::string _description, int _qtite, float _prix);


		void setProduit(std::string _produit);
		void setDescription(std::string _description);
		void setId(int _id);
		void setQtite(int _qtite);
		void setPrix(float _prix);

		std::string getNameProduit() const;
		std::string getDescription() const;
		int getId() const;
		int getQtite() const;
		float getPrix() const;

	
};

std::ostream& operator<<(std::ostream& os, const Produit& produit);
