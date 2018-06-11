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

class CJeu
{
    public:
    	CJeu(); // Constructeur par défaut
	    CJeu(CTerrain* terrain, CChat* chat, CSouris* souris); // Constructeur spécialisé
        virtual ~CJeu(); // Destructeur
	    void Launch(int nbIterations);

    protected:
	    CTerrain* m_terrain;
	    CChat* m_chat;
	    CSouris* m_souris;
};

#endif
