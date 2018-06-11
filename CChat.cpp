#include "CChat.h"

CChat::CChat(): CAnimal::CAnimal(1,2)
{

}

CChat::CChat(int nbSteps, int step): CAnimal::CAnimal(nbSteps,step)
{

}

CChat::~CChat()
{

}

void CChat::Mange()
{
    cout << endl << "Miam miam" << endl << endl;
}

void CChat::Attaque(int x, int y)
{
    m_X = x;
    m_Y = y;
}

void CChat::Deplace(int x, int y)
{
    int dir;
    bool isOK;
    for(unsigned k=0;k<m_nbSteps;k++)
    {
        // Calcul de la direction à cibler
        int dX = x - m_X;
        int dY = y - m_Y;
        double d = sqrt( dX*dX + dY*dY );
        
        if(d<=m_step*sqrt(2)) // si la souris est trop proche, on la mange
        {
            Attaque(x,y);
        }
        else
        {
            if( dX*dX >= dY*dY )
            {
                if(dX>=0)
                {
                    dir = 0; // x++
                }
                else
                {
                    dir = 1; // x--
                }
            }
            else
            {
                if(dY>=0)
                {
                    dir = 2; // y++
                }
                else
                {
                    dir = 3; // y--
                }
            }
            isOK = UpdatePosition(dir);
            
            while(!isOK) // si cette direction n'est pas autorisée
            {
                int dir = rand() % 4; // direction aléatoire
                isOK = UpdatePosition(dir);
            }
        }
    }
}


