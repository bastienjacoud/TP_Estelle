#ifndef CANIMAL_H
#define CANIMAL_H

using namespace std;
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

class CAnimal
{
public:
    CAnimal(); // Constructeur par défaut
    CAnimal(int nbSteps, int step); // Constructeur spécialisé
    virtual ~CAnimal(); // Destructeur
    void Deplace();
    int GetX(); // Accesseur
    int GetY(); // Accesseur
    void SetTerrain(int x, int y, int dimX, int dimY); // Mutateur pour plusieurs variables

protected:
    int m_X; // Position X
    int m_Y; // Position Y
    int m_Xold; // Position antérieure X
    int m_Yold; // Position antérieuren Y
    int m_dimX; // Limite X
    int m_dimY; // Limite Y
    int m_nbSteps; // Nombre de pas à chaque itération du jeu
    int m_step; // Longueur de chaque pas
    bool UpdatePosition(int dir);
};

#endif