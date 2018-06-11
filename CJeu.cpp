#include "CJeu.h"
#include <utility>

CJeu::CJeu() : m_chats(), m_souris()
{
    m_terrain = NULL;
}

CJeu::CJeu(CTerrain* terrain, std::vector<CChat> vchats, std::vector<CSouris> vsouris) : m_chats(std::move(vchats)), m_souris(
        std::move(vsouris))
{
    m_terrain = terrain;

    int dimX = m_terrain->GetDimX();
    int dimY = m_terrain->GetDimY();
    int x,y;

    std::vector<bool> dispos;

    for(int i(0); i < dimX; i++) {
        for(int j(0); j < dimY; j++) {
            dispos.push_back(true);
        }
    }
    // Positionne aléatoirement les chats dans les limites du terrain
    for (auto &chat : m_chats) {
        do{
            x = rand() % dimX; // between 0 and m_dimX-1
            y = rand() % dimY; // between 0 and m_dimY-1
        } while (!dispos[(x*dimY)+y]);

        dispos[(x*dimY)+y] = false;
        chat.SetTerrain(x,y,dimX,dimY);
    }

    // Positionne aléatoirement les souris dans les limites du terrain
    for (auto &souris : m_souris) {
        do{
            x = rand() % dimX; // between 0 and m_dimX-1
            y = rand() % dimY; // between 0 and m_dimY-1
        } while (!dispos[(x*dimY)+y]);

        dispos[(x*dimY)+y] = false;
        souris.SetTerrain(x,y,dimX,dimY);
    }
}

CJeu::~CJeu()
{
    if(nullptr != m_terrain)
    {
        delete m_terrain;
        m_terrain = nullptr;
    }
}

void CJeu::Launch(int nbIterations)
{
    for(auto &chat : m_chats){
        chat.UpdateIndex(m_souris.size(), 0);
    }
    for(int t=0;(t < nbIterations) && (!m_souris.empty());t++) // itère le jeu
    {
        cout << "It=" << t << endl;
        m_terrain->Affiche(m_chats, m_souris);

        // Le chat mange la souris si leurs positions coincident
        for(auto &chat : m_chats){
            for(int i(0);i<m_souris.size();i++){
                if( (chat.GetX()==m_souris[i].GetX()) && (chat.GetY()==m_souris[i].GetY()) )
                {
                    chat.Mange();
                    m_souris.erase(m_souris.begin() + i);
                    if(!m_souris.empty()) {
                        for(auto &chat1 : m_chats) {
                            chat1.UpdateIndex(m_souris.size(), i);
                        }
                    }
                    break;
                }
            }
        }

        if(!m_souris.empty()) {
            for (auto &chat : m_chats) {
                if(chat.GetTarget() < m_souris.size()){
                    chat.Deplace(m_souris[chat.GetTarget()].GetX(),
                                 m_souris[chat.GetTarget()].GetY()); // le chat se déplace vers la souris
                }
            }

            for (auto &souris : m_souris) {
                // on choisit un chat random dans la liste
                unsigned long indexChat = rand() % m_chats.size(); // between 0 and m_dimX-1

                souris.Deplace(m_chats[indexChat].GetX(),
                               m_chats[indexChat].GetY()); // la souris se déplace loin du chat
            }
            system("sleep 0.5"); // pause de 0.2s pour faciliter la visualisation
        }
    }


}

