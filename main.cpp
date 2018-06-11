#include <iostream>

#include "CJeu.h"
#include "CTerrain.h"
#include "CAnimal.h"
#include "CChat.h"
#include "CSouris.h"

using namespace std;

int main()
{
    srand (time(NULL));

    std::vector<CChat> vchats;
    vchats.emplace_back(1, 2); // 1 step of 2 at each iteration
    vchats.emplace_back(1, 2);
    vchats.emplace_back(1, 2);
    vchats.emplace_back(1, 2);
    vchats.emplace_back(1, 2);

    std::vector<CSouris> vsouris;
    vsouris.emplace_back(3,1); // 2 steps of 1 at each iteration
    vsouris.emplace_back(3,1);
    vsouris.emplace_back(3,1);
    vsouris.emplace_back(3,1);
    vsouris.emplace_back(3,1);
    vsouris.emplace_back(3,1);
    vsouris.emplace_back(3,1);
    vsouris.emplace_back(3,1);
    vsouris.emplace_back(3,1);
    vsouris.emplace_back(3,1);

    CJeu jeu(new CTerrain(60,20),vchats,vsouris);
    jeu.Launch(200);

    return 0;
}
