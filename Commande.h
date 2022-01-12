#pragma once
#include "Client.h"
#include "Produit.h"

class Commande
{
private:
    int _id;
    Client _client;
    std::vector<Produit> _produitsAchetes;
    int _statut;
public:
    Commande(int id, Client client);
    int getId() const;
    Client getClient() const;
    std::vector<Produit> getProduitsAchetes() const;
    int getStatut() const;
    std::string getDescriptionStatut() const;
    bool setStatut(int statut);
};

std::ostream& operator<<(std::ostream& os, const Commande& commande);