#pragma once
#include "Client.h"
#include "Produit.h"

class Commande
{
private:
    Client _client;
    std::vector<Produit> _produitsAchetes;
    int _statut;
public:
    Client getClient() const;
    std::vector<Produit> getProduitsAchetes() const;
    int getStatut() const;
};

std::ostream& operator<<(std::ostream& os, const Commande& commande);