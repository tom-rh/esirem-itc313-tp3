#include "Menu.h"
#include "Produit.h"

Menu::Menu()
{
	bool exit = false;
	do{
	std::cout << "...................................................................................................." << std::endl;
	std::cout << ".		Bienvenu dans le Magasin EasyStock                                                           ." << std::endl;
	std::cout << ".		Pour naviguer dans le menu il suffit d'appuyer sur les touches du pave numerique             ." << std::endl;
	std::cout << ".		                                                                                             ." << std::endl;
	std::cout << ".		1 - Gestion du Magasin                                                                       ." << std::endl;
	std::cout << ".		2 - Gestion des Utilisateurs                                                                 ." << std::endl;
	std::cout << ".		3 - Gestion des Commandes                                                                    ." << std::endl;
	std::cout << ".		Autre - Quitter                                                                              ." << std::endl;
	std::cout << "...................................................................................................." << std::endl;

	std::cin >> _navigation;

	switch(_navigation) {
		case 1:
			this->clear();
			this->gestionMagasin();
			break;
		case 2:
			this->clear();
			this->gestionClient();
			break;
		case 3:
			this->clear();
			this->gestionCommande();
			break;
		default:
			exit = true;
	}	
	} while(exit == false);
}

void Menu::clear()
{
	for (int i=0 ; i<50 ; i++)
	{
		std::cout << std::endl;
	}
}

void Menu::gestionCommande()
{
	// TODO
}

void Menu::gestionClient()
{
	std::cout << "...................................................................................................." << std::endl;
	std::cout << ".		1 - Ajoutter un produit au Panier                                                            ." << std::endl;
	std::cout << ".		2 - Modifier la Quantité d'un Produit du Panier                                              ." << std::endl;
	std::cout << ".		3 - Vider le Panier                                                                          ." << std::endl;
	std::cout << ".		4 - Supprimer un Produit du Panier                                                           ." << std::endl;
	std::cout << ".	    0 - Retour au Menu                                                                           ." << std::endl;
	std::cout << "...................................................................................................." << std::endl;

	int navig;

	std::cin>> navig;

	switch(navig) {
		case 1:
			clear();
			break;
		case 2:
			clear();
			break;
		case 3:
			clear();
			break;
		case 4:
			clear();
			break;
		case 5:
			clear();
		default:
			clear();
	}
}

void Menu::gestionMagasin()
{
	std::cout << "...................................................................................................." << std::endl;
	std::cout << ".		1 - Ajoutter un produit                                                                      ." << std::endl;
	std::cout << ".		2 - Ajoutter un client                                                             		     ." << std::endl;
	std::cout << ".		3 - Ajoutter un produit au Panier                                                            ." << std::endl;
	std::cout << ".		4 - Trouver un Produit                                                                       ." << std::endl;
	std::cout << ".		5 - Trouver un Client                                                                        ." << std::endl;
	std::cout << ".		6 - Supprimer un Produit du Panier                                                           ." << std::endl;
	std::cout << ".		7 - Modifier la Quantité d'un Produit du Panier                                              ." << std::endl;
	std::cout << ".		8 - Modifier le Stock                                                                        ." << std::endl;
	std::cout << ".		9 - Afficher les Clients                                                                     ." << std::endl;
	std::cout << ".	   10 - Afficher les Produits                                                                    ." << std::endl;
	std::cout << ".	    0 - Retour au Menu                                                                           ." << std::endl;
	std::cout << "...................................................................................................." << std::endl;

	int navig;
	std::cin >> navig;
	
	std::string nomP,descrP;
	float prixP;
	int IDP,qtitP;

	switch(navig) {
		case 1:
			clear();
			std::cout << "Entrer un nom"<< std::endl;
			std::cin >> nomP;
			std::cout << "Entrer une Description"<< std::endl;
			std::cin >> descrP;
			std::cout << "Entrer un ID"<< std::endl;
			std::cin >> IDP;
			std::cout << "Entrer un Prix"<< std::endl;
			std::cin >> prixP;
			std::cout << "Entrer une Quantite"<< std::endl;
			std::cin >> qtitP;
			Produit (IDP,nomP,descrP,qtitP,prixP);
			break;
		case 2:
			clear();
			break;
		case 3:
			clear();
			break;
		case 4:
			clear();
			break;
		case 5:
			clear();
			break;
		case 6:
			clear();
			break;
		case 7:
			clear();
			break;
		case 8:
			clear();
			break;
		case 9:
			clear();
			break;
		case 10:
			clear();
			break;
		case 0:
			clear();
			break;
		default:
			clear();
	}
}