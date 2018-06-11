#ifndef CTERRAIN_H
#define CTERRAIN_H

using namespace std;
#include "CAnimal.h"
#include "CChat.h"
#include "CSouris.h"
#include <iostream>
#include <vector>

class CTerrain
{
public:
    CTerrain(); // Constructeur par défaut
    CTerrain(int dimX, int dimY); // Constructeur spécialisé
    virtual ~CTerrain(); // Destructeur
    void Affiche(std::vector<CChat> vchats, std::vector<CSouris> vsouris);
    int GetDimX(); // Accesseur
    int GetDimY(); // Accesseur

protected:
    int m_dimX;
    int m_dimY;
};

#endif