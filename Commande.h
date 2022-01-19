#pragma once
#include "Client.h"
#include "Produit.h"

class Commande
{
private:
    static int _debutId;
    int _id;
    Client _client;
    std::vector<Produit> _produitsAchetes;
    int _statut;
public:
    Commande(Client &client);
    int getId() const;
    Client& getClient();
    std::vector<Produit>& getProduitsAchetes();
    int getStatut() const;
    std::string getDescriptionStatut() const;
    bool setStatut(int statut);
};

std::ostream& operator<<(std::ostream& os, Commande& commande);