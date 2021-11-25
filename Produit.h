#pragma once
#include <string>

class Produit
{

private:

	std::string _produit;
	std::string _description;
	double _qtite;
	float _prix;
	double _id;


public:

	Produit(std::string _produit, double _id, std::string _description, double _qtite, float _prix);


		void setProduit(std::string _produit);
		void setDescription(std::string _description);
		void setId(double _id);
		void setQtite(double _qtite);
		void setPrix(float _prix);

		std::string getProduit() const;
		std::string getDescription() const;
		double getId() const;
		double getQtite() const;
		float getPrix() const;

	
};

std::ostream& operator<<(std::ostream& os, const Produit& produit);
