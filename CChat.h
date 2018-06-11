#ifndef CCHAT_H
#define CCHAT_H

using namespace std;
#include "CAnimal.h"
#include <iostream>
#include <math.h>

class CChat: public CAnimal
{
public:
    CChat(); // Constructeur par défaut
    CChat(int nbSteps, int step); // Constructeur spécialisé
    virtual ~CChat(); // Destructeur
    void Mange(); // Mange
    void Attaque(int x, int y); // Attaque si on est assez proche
    void Deplace(int x, int y); // Le chat cherche à se rapprocher de la souris
    void UpdateIndex(unsigned long nbSourisDispo, int lastIndexDeleted);
    int GetTarget() { return indexTarget; }

protected:
    int indexTarget;

};

#endif