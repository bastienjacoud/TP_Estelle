#include "CJeu.h"

CJeu::CJeu()
{
    m_terrain = NULL;
    m_chat = NULL;
    m_souris = NULL;
}

CJeu::CJeu(CTerrain* terrain, CChat* chat, CSouris* souris)
{
    m_terrain = terrain;
    m_chat = chat;
    m_souris = souris;
    
    int dimX = m_terrain->GetDimX();
    int dimY = m_terrain->GetDimY();
    int x,y;
    
    // Positionne aléatoirement le chat dans les limites du terrain
    x = rand() % dimX; // between 0 and m_dimX-1
    y = rand() % dimY; // between 0 and m_dimY-1
    m_chat->SetTerrain(x,y,dimX,dimY);
    
    // Positionne aléatoirement la souris dans les limites du terrain
    x = rand() % dimX; // between 0 and m_dimX-1
    y = rand() % dimY; // between 0 and m_dimY-1
    m_souris->SetTerrain(x,y,dimX,dimY);
}

CJeu::~CJeu()
{
    if(NULL != m_terrain)
    {
        delete m_terrain;
        m_terrain = NULL;
    }
    if(NULL != m_chat)
    {
        delete m_chat;
        m_chat = NULL;
    }
    if(NULL != m_souris)
    {
	    delete m_souris;
        m_souris = NULL;
    }
}

void CJeu::Launch(int nbIterations)
{
    for(int t=0;t<nbIterations;t++) // itère le jeu
    {
        cout << "It=" << t << endl;
        m_terrain->Affiche(m_chat, m_souris);
        
        // Le chat mange la souris si leurs positions coincident
        if( (m_chat->GetX()==m_souris->GetX()) && (m_chat->GetY()==m_souris->GetY()) )
        {
            m_chat->Mange();
            break;
        }

        m_chat->Deplace(m_souris->GetX(),m_souris->GetY()); // le chat se déplace vers la souris
        m_souris->Deplace(m_chat->GetX(),m_chat->GetY()); // la souris se déplace loin du chat
        system("sleep 0.2"); // pause de 0.2s pour faciliter la visualisation        
    }
    
    
}

