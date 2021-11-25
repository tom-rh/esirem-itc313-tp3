#include "Magasin.h"
#include "Client.h"

int main()
{
	Magasin magasin("EasyStock");

	Produit p1(1, "PS5", "Console de jeux", 5, 600);

	std::cout << p1 << std::endl;

	Client c1(1, "Tom", "Roth");

	c1.ajouterProduitPanier(p1);

	std::cout << c1;

	c1.modifierQuantiteProduitPanier(p1, 2);

	std::cout << "Ajout de 2 produits dans le panier" << std::endl;

	std::cout << c1;

	return 0;
}