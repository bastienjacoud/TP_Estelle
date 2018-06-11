#ifndef CJEU_H
#define CJEU_H

using namespace std;
#include "CTerrain.h"
#include "CAnimal.h"
#include "CChat.h"
#include "CSouris.h"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include <vector>

class CJeu
{
public:
    CJeu(); // Constructeur par défaut
    CJeu(CTerrain* terrain, std::vector<CChat> chats, std::vector<CSouris> souris); // Constructeur spécialisé
    virtual ~CJeu(); // Destructeur
    void Launch(int nbIterations);

protected:
    CTerrain* m_terrain;
    std::vector<CChat> m_chats;
    std::vector<CSouris> m_souris;
};

#endif