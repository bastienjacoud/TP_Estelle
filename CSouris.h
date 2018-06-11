#ifndef CSOURIS_H
#define CSOURIS_H

using namespace std;
#include "CAnimal.h"
#include <iostream>
#include <math.h>

class CSouris: public CAnimal
{
public:
    CSouris(); // Constructeur par défaut
    CSouris(int nbSteps, int step); // Constructeur spécialisé
    virtual ~CSouris(); // Destructeur
    void Deplace(int x, int y); // Coordonnées à fuir

protected:
    bool m_EnFuite; // Statut actuel: 0=repos, 1=en fuite

};

#endif