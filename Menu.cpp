#include "Menu.h"
#include "Produit.h"
#include <windows.h> 

Menu::Menu() : _navigation(0), _exit(false), _tempsPause(5000), _easystore(Magasin("easystore"))
{
	Client c1 = Client("Tom","Roth");
	_easystore.addClient(c1);
	std::cout << c1 << std::endl;
}

void Menu::clear()
{
	for (int i=0 ; i<50 ; i++)
	{
		std::cout << std::endl;
	}
}

void Menu::redirectionMenu()
{
	std::cout << "Retour au menu principal dans 5 secondes !" << std::endl;
}

void Menu::principal()
{
	clear();
	do
	{
		std::cout << "...................................................................................................." << std::endl;
		std::cout << ".		Bienvenue dans le Magasin EasyStock                                                          ." << std::endl;
		std::cout << ".		Pour naviguer dans le menu il suffit d'appuyer sur les touches du pave numerique             ." << std::endl;
		std::cout << ".		                                                                                             ." << std::endl;
		std::cout << ".		1 - Gestion du Magasin                                                                       ." << std::endl;
		std::cout << ".		2 - Gestion des Clients                                                                      ." << std::endl;
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
				_exit = true;
		}
	} while(_exit == false);
}

int Menu::gestionCommande()
{
	clear();
	do
	{
		std::cout << "...................................................................................................." << std::endl;
		std::cout << ".		GESTION COMMANDE																             ." << std::endl;
		std::cout << ".		                                                                                             ." << std::endl;
		std::cout << ".		1 - Creer une commande                                                                       ." << std::endl;
		std::cout << ".		2 - Suivre/Editer une commande                                                               ." << std::endl;
		std::cout << ".		Autre - Quitter                                                                              ." << std::endl;
		std::cout << "...................................................................................................." << std::endl;

		std::cin >> _navigation;

		switch(_navigation) {
			case 1:
				this->clear();
				int idClient;
				std::cout << "Indiquez l'identifiant du client pour lequel vous souhaitez creer la commande :" << std::endl;
				std::cin >> idClient;
				this->clear();
				if (_easystore.validerCommande(idClient) == true)
					std::cout << "Commande cree" << std::endl;
				else
					std::cout << "Erreur lors de la creaton de la commande" << std::endl;
				break;
			case 2:
				this->clear();
				int numeroCommande;
				std::cout << "Indiquez le numero de votre commande" << std::endl;
				std::cin >> numeroCommande;
				this->clear();
				for (std::vector<Commande>::iterator it = _easystore.getCommandes().begin(); it != _easystore.getCommandes().end(); it++) {
					if ( numeroCommande == (*it).getId()){
						char choix;
						std::cout << (*it) << std::endl;
						std::cout << std::endl;
						std::cout << "Voulez-vous modifier le statut de cette commande ? O/N" << std::endl;
						std::cin >> choix;
						switch(choix) {
							case 'o': case 'O':
								int choixStatut;
								std::cout << "Indiquez le chiffre du nouveau statut à indiquer :" << std::endl;
								std::cin >> choixStatut;
								if ((*it).setStatut(choixStatut) == true)
								{
									this->clear();
									std::cout << "Nouveau statut !" << std::endl;
									std::cout << (*it) << std::endl;
								} 
								else
								{
									this->clear();
									std::cout << "Erreur lors de la configuration du nouveau statut !" << std::endl;
									break;
								}
							case 'n': case 'N':
								break;
							default:
								break;
						}
					}
					else
						std::cout << "Erreur avec le numero de commande" << std::endl;
				}
				break;
			default:
				_exit = true;
		}
	} while(_exit == false);
	return 0;
}

int Menu::gestionClient()
{
	clear();

	bool clientTrouve = false;
	int idClient = 0;

	std::cout << "Indiquez l'id de votre client" << std::endl;
	std::cin >> idClient;
	for (std::vector<Client>::iterator it = _easystore.getClients().begin(); it != _easystore.getClients().end(); it++)
	{
		if (idClient == (*it).getId())
		{
			clientTrouve = true;
			break;
		}
	}
	if (clientTrouve == false)
	{
		clear();
		std::cout << "Identifiant incorrect ! - Pour ajouter un client, merci de vous rendre dans la section Gestion du magasin." << std::endl;
		std::cout << "Retour au menu principal dans 5 secondes !" << std::endl;
		Sleep(_tempsPause);
		clear();
		return 0;
	}
	std::cout << "...................................................................................................." << std::endl;
	std::cout << ".		GESTION CLIENT																	             ." << std::endl;
	std::cout << ".		                                                                                             ." << std::endl;
	std::cout << ".		1 - Ajouter un produit au panier                                                             ." << std::endl;
	std::cout << ".		2 - Modifier la quantite d'un produit du panier                                              ." << std::endl;
	std::cout << ".		3 - Supprimer un produit du panier                                                           ." << std::endl;
	std::cout << ".		4 - Vider le Panier                                                                          ." << std::endl;
	std::cout << ".		Autre - Retour au Menu                                                                       ." << std::endl;
	std::cout << "...................................................................................................." << std::endl;

	std::cin >> _navigation;

	switch(_navigation) {
		case 1:
			clear();
			if (_easystore.validerCommande(idClient) == true)
				std::cout << "Commande cree" << std::endl;
			else
				std::cout << "Erreur lors de la creaton de la commande" << std::endl;
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
		default:
			break;
	}
	return 0;
}

int Menu::gestionMagasin()
{
	std::cout << "...................................................................................................." << std::endl;
	std::cout << ".		GESTION MAGASIN																	             ." << std::endl;
	std::cout << ".		                                                                                             ." << std::endl;
	std::cout << ".		1 - Ajouter un produit                                                                       ." << std::endl;
	std::cout << ".		2 - Ajouter un client                                                                        ." << std::endl;
	std::cout << ".		3 - Ajouter un produit au panier                                                             ." << std::endl;
	std::cout << ".		4 - Trouver un produit                                                                       ." << std::endl;
	std::cout << ".		5 - Trouver un client                                                                        ." << std::endl;
	std::cout << ".		6 - Supprimer un produit du panier                                                           ." << std::endl;
	std::cout << ".		7 - Modifier la quantité d'un produit du panier                                              ." << std::endl;
	std::cout << ".		8 - Modifier le stock                                                                        ." << std::endl;
	std::cout << ".		9 - Afficher les clients                                                                     ." << std::endl;
	std::cout << ".	   10 - Afficher les produits                                                                    ." << std::endl;
	std::cout << ".		Autre - Retour au Menu                                                                       ." << std::endl;
	std::cout << "...................................................................................................." << std::endl;

	int navig;
	std::cin >> navig;

	std::string nomP, descrP;
	float prixP;
	int qtitP;

	switch(navig) {
		case 1:
			clear();
			std::cout << "Entrer un nom :"<< std::endl;
			std::cin >> nomP;
			std::cout << "Entrer une description :"<< std::endl;
			std::cin >> descrP;
			std::cout << "Entrer un prix :"<< std::endl;
			std::cin >> prixP;
			std::cout << "Entrer une quantite :"<< std::endl;
			std::cin >> qtitP;
			_easystore.addProduit(Produit(nomP,descrP,qtitP,prixP));
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
		default:
			break;
	}
	return 0;
}