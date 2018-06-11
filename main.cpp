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

    CTerrain* terrain = new CTerrain(60,20);
    CChat* chat = new CChat(1,2); // 1 step of 2 at each iteration
    CSouris* souris = new CSouris(3,1); // 2 steps of 1 at each iteration

    CJeu jeu(terrain,chat,souris);
    jeu.Launch(100);
    
    return 0;
}
