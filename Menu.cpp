#include "Menu.h"
#include "Produit.h"
#include <windows.h> 

Menu::Menu() : _navigation(0), _exit(false), _tempsPause(5000), _easystore(Magasin("easystore"))
{
	Client c1 = Client("Tom","Roth");
	_easystore.addClient(c1);
	std::cout << c1 << std::endl;
	Produit p1 = Produit("XBOX", "Console", 5, 25);
	_easystore.addProduit(p1);
	std::cout << p1 << std::endl;
	_easystore.afficheClients();
	_easystore.afficheProduits();
	Sleep(_tempsPause);
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
		std::cout << ".	Bienvenue dans le Magasin EasyStock" << std::endl;
		std::cout << ".	Pour naviguer dans le menu il suffit d'appuyer sur les touches du pave numerique" << std::endl;
		std::cout << "." << std::endl;
		std::cout << ".	1 - Gestion du Magasin" << std::endl;
		std::cout << ".	2 - Gestion des Clients" << std::endl;
		std::cout << ".	3 - Gestion des Commandes" << std::endl;
		std::cout << ".	Autre - Quitter" << std::endl;
		std::cout << "...................................................................................................." << std::endl;

		std::cin >> _navigation;

		switch(_navigation)
		{
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
	std::cout << "...................................................................................................." << std::endl;
	std::cout << ".	GESTION COMMANDE" << std::endl;
	std::cout << "." << std::endl;
	std::cout << ".	1 - Creer une commande" << std::endl;
	std::cout << ".	2 - Suivre/Editer une commande" << std::endl;
	std::cout << ".	Autre - Quitter" << std::endl;
	std::cout << "...................................................................................................." << std::endl;

	std::cin >> _navigation;

	switch(_navigation)
	{
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
			Sleep(_tempsPause);
			clear();
			break;
		case 2:
			this->clear();
			int numeroCommande;
			std::cout << "Indiquez le numero de votre commande" << std::endl;
			std::cin >> numeroCommande;
			this->clear();
			for (Commande &commande : _easystore.getCommandes()) {
				if ( numeroCommande == commande.getId()){
					char choix;
					std::cout << commande << std::endl;
					std::cout << std::endl;
					std::cout << "Voulez-vous modifier le statut de cette commande ? O/N" << std::endl;
					std::cin >> choix;
					switch(choix) {
						case 'o': case 'O':
							int choixStatut;
							std::cout << "Indiquez le chiffre du nouveau statut a indiquer :" << std::endl;
							std::cin >> choixStatut;
							this->clear();
							if (commande.setStatut(choixStatut) == true)
							{
								std::cout << "Nouveau statut !" << std::endl;
								std::cout << commande << std::endl;
							} 
							else
							{
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
			Sleep(_tempsPause);
			clear();
			break;
		default:
			break;
	}
	clear();
	return 0;
}

int Menu::gestionClient()
{
	clear();

	bool clientTrouve = false;
	int idClient = 0;
	std::cout << "Indiquez l'id de votre client" << std::endl;
	std::cin >> idClient;
	for (Client &client : _easystore.getClients())
	{
		if (idClient == client.getId())
		{
			clientTrouve = true;
			clear();
			std::cout << "Client " << idClient << " trouve !" << std::endl;
			std::cout << "Redirection vers le menu de gestion !" << std::endl;
			Sleep(_tempsPause);
			clear();
			break;
		}
	}
	if (clientTrouve == false)
	{
		clear();
		std::cout << "Identifiant incorrect ! - Pour ajouter un client, merci de vous rendre dans la section Gestion du magasin." << std::endl;
		this->redirectionMenu();
		Sleep(_tempsPause);
		clear();
		return 0;
	}

	int idProduit = 0, quantiteProduit = 0;
	bool produitTouve = false;
	Client clientIdentifie = _easystore.getClient(idClient);

	std::cout << "...................................................................................................." << std::endl;
	std::cout << ".	GESTION CLIENT - ID " << clientIdentifie.getId() << std::endl;
	std::cout << "." << std::endl;
	std::cout << ".	1 - Ajouter un produit au panier" << std::endl;
	std::cout << ".	2 - Modifier la quantite d'un produit du panier" << std::endl;
	std::cout << ".	3 - Supprimer un produit du panier" << std::endl;
	std::cout << ".	4 - Afficher les informations du client" << std::endl;
	std::cout << ".	5 - Vider le Panier" << std::endl;
	std::cout << ".	Autre - Retour au Menu" << std::endl;
	std::cout << "...................................................................................................." << std::endl;

	std::cin >> _navigation;

	switch(_navigation)
	{
		case 1:
			clear();
			std::cout << "Indiquez l'id du produit a ajouter au panier" << std::endl;
			std::cin >> idProduit;
			for (Produit &produit : _easystore.getProduits())
			{
				if (idProduit == produit.getId())
				{
					produitTouve = true;
					if (clientIdentifie.ajouterProduitPanier(produit) == true)
						std::cout << "Produit ajoute au panier !" << std::endl;
					else
						std::cout << "Erreur lors de l'ajout du produit au panier !" << std::endl;
					Sleep(_tempsPause);
					clear();
					break;
				}
			}
			if (produitTouve == false)
			{
				clear();
				std::cout << "Identifiant incorrect ! - Pour ajouter un produit au magasin, merci de vous rendre dans la section Gestion du magasin." << std::endl;
				this->redirectionMenu();
				Sleep(_tempsPause);
				clear();
				return 0;
			}
			break;
		case 2:
			clear();
			std::cout << "Indiquez l'id du produit ajoute panier auquel vous voulez modifier la quantite" << std::endl;
			std::cin >> idProduit;
			std::cout << "Indiquez la nouvelle quantite" << std::endl;
			std::cin >> quantiteProduit;
			for (Produit &produit : _easystore.getProduits())
			{
				if (idProduit == produit.getId())
				{
					produitTouve = true;
					if (clientIdentifie.modifierQuantiteProduitPanier(idProduit,quantiteProduit) == true)
						std::cout << "Quantite modifie avec succes !" << std::endl;
					else
						std::cout << "Erreur lors de la modification de la quantite du produit dans le panier !" << std::endl;
					Sleep(_tempsPause);
					clear();
					break;
				}
			}
			if (produitTouve == false)
			{
				clear();
				std::cout << "Identifiant incorrect ! - Pour ajouter un produit au magasin, merci de vous rendre dans la section Gestion du magasin." << std::endl;
				this->redirectionMenu();
				Sleep(_tempsPause);
				clear();
				return 0;
			}
			break;
		case 3:
			clear();
			std::cout << "Indiquez l'id du produit a supprimer du panier" << std::endl;
			std::cin >> idProduit;
			clear();
			for (Produit &produit : _easystore.getProduits())
			{
				if (idProduit == produit.getId())
				{
					produitTouve = true;
					if (clientIdentifie.supprimerProduitPanier(idProduit) == true)
						std::cout << "Produit supprime du panier !" << std::endl;
					else
						std::cout << "Erreur lors de la suppression du produit du panier !" << std::endl;
					this->redirectionMenu();
					Sleep(_tempsPause);
					clear();
					break;
				}
			}
			if (produitTouve == false)
			{
				clear();
				std::cout << "Identifiant incorrect ! - Pour ajouter un produit au magasin, merci de vous rendre dans la section Gestion du magasin." << std::endl;
				this->redirectionMenu();
				Sleep(_tempsPause);
				clear();
				return 0;
			}
			break;
		case 4:
			clear();
			std::cout << clientIdentifie << std::endl;
			this->redirectionMenu();
			Sleep(_tempsPause);
			clear();
			break;
		case 5:
			clear();
			if (clientIdentifie.viderPanier())
				std::cout << "Le panier du client a ete vide !" << std::endl;
			else
				std::cout << "Erreur lors de l'operation !" << std::endl;
			this->redirectionMenu();
			Sleep(_tempsPause);
			clear();
			break;
		default:
			clear();
			break;
	}
	clear();
	return 0;
}

int Menu::gestionMagasin()
{
	std::cout << "...................................................................................................." << std::endl;
	std::cout << ".	GESTION MAGASIN" << std::endl;
	std::cout << "." << std::endl;
	std::cout << ".	1 - Ajouter un produit" << std::endl;
	std::cout << ".	2 - Ajouter un client" << std::endl;
	std::cout << ".	3 - Trouver un produit" << std::endl;
	std::cout << ".	4 - Trouver un client" << std::endl;
	std::cout << ".	5 - Modifier le stock" << std::endl;
	std::cout << ".	6 - Afficher les clients" << std::endl;
	std::cout << ".	7 - Afficher les produits" << std::endl;
	std::cout << ".	Autre - Retour au Menu" << std::endl;
	std::cout << "...................................................................................................." << std::endl;

	int navig;
	std::cin >> navig;

	std::string nomProduit, descriptionProduit;
	float prixProduit;
	int quantiteProduit, idClient;
	char choix;

	std::string prenomCLient, nomClient;

	switch(navig) {
		case 1:
			clear();
			std::cout << "Entrez un nom" << std::endl;
			std::cin >> nomProduit;
			std::cout << "Entrez une description" << std::endl;
			std::cin >> descriptionProduit;
			std::cout << "Entrez un prix" << std::endl;
			std::cin >> prixProduit;
			std::cout << "Entrez une quantite" << std::endl;
			std::cin >> quantiteProduit;
			_easystore.addProduit(Produit(nomProduit,descriptionProduit,prixProduit,quantiteProduit));
			redirectionMenu();
			Sleep(_tempsPause);
			clear();
			break;
		case 2:
			clear();
			std::cout << "Entrez le prenom du client a ajouter" << std::endl;
			std::cin >> prenomCLient;
			std::cout << "Entrez le nom du client a ajouter" << std::endl;
			std::cin >> nomClient;
			if (_easystore.addClient(Client(prenomCLient,nomClient)))
			{
				clear();
				std::cout << "Client ajoute avec succes !" << std::endl;
			}
			else
			{
				clear();
				std::cout << "Erreur lors de l'ajout du client !" << std::endl;
			}
			this->redirectionMenu();
			Sleep(_tempsPause);
			clear();
			break;
		case 3:
			clear();
			std::cout << "Entrez le nom du produit" << std::endl;
			std::cin >> nomProduit;
			if (_easystore.trouverProduit(nomProduit) == 0)
			{
				clear();
				std::cout << "Erreur lors de la recherche !" << std::endl;
			}
			else
			{
				clear();
				std::cout << "Le produit que vous avez recherche a l'identidiant : " << _easystore.trouverProduit(nomProduit) << std::endl;
			}
			redirectionMenu();
			Sleep(_tempsPause);
			clear();
			break;
		case 4:
			clear();
			std::cout << "Voulez effectuer une recherche par identifiant ou par le nom du client ? I/N" << std::endl;
			std::cin >> choix;
			switch(choix) {
						case 'i': case 'I':
							std::cout << "Entrez l'identifiant du client" << std::endl;
							std::cin >> idClient;
							clear();
							if (_easystore.trouverClient(idClient) == 0)
								std::cout << "Erreur lors de la recherche !" << std::endl;
							else
							{
								std::cout << "Voici les informations du client : " << std::endl;
								std::cout << _easystore.getClient(_easystore.trouverClient(idClient)) << std::endl;
							}
							break;
						case 'n': case 'N': // Impossible d'afficher les informations du client quand le nom est correct
							/*std::cout << "Entrez le nom du client" << std::endl;
							std::cin >> nomClient;
							clear();
							if (_easystore.trouverClient(nomClient) == 0)
								std::cout << "Erreur lors de la recherche !" << std::endl;
							else
								std::cout << "Le client que vous avez recherche a l'identidiant : " << _easystore.trouverClient(nomClient) << std::endl;
								std::cout << "Voici les informations du client : " << std::endl;
								std::cout << _easystore.getClient(_easystore.trouverClient(idClient)) << std::endl;
							*/
							std::cout << "Nous sommes desoles mais il est impossible d'effectuer une recherche par un nom pour le moment." << std::endl;
							break;
						default:
							std::cout << "Choix incorrect !" << std::endl;
					}
			redirectionMenu();
			Sleep(_tempsPause);
			clear();
			break;
		case 5:
			clear();
			std::cout << "Entrez le nom du produit" << std::endl;
			std::cin >> nomProduit;
			std::cout << "Entrez la nouvelle quantite de " << nomProduit << std::endl;
			std::cin >> quantiteProduit;
			if ((_easystore.changerQuantite(quantiteProduit,nomProduit)) == true)
			{
				clear();
				std::cout << "Stock mis a jour !" << std::endl;
			}
			else
			{
				clear();
				std::cout << "Erreur lors la mise a jour du stock !" << std::endl;
			}
			this->redirectionMenu();
			Sleep(_tempsPause);
			clear();
			break;
		case 6:
			clear();
			_easystore.afficheClients();
			redirectionMenu();
			Sleep(_tempsPause);
			clear();
			break;
		case 7:
			clear();
			_easystore.afficheProduits();
			redirectionMenu();
			Sleep(_tempsPause);
			clear();
			break;
		default:
			break;
	}
	clear();
	return 0;
}