#include "CSouris.h"

CSouris::CSouris(): CAnimal::CAnimal(2,1)
{
	m_EnFuite = false;
}

CSouris::CSouris(int nbSteps, int step): CAnimal::CAnimal(nbSteps,step)
{
	m_EnFuite = false;
}

CSouris::~CSouris()
{

}

void CSouris::Deplace(int x, int y)
{
    int dir;
    bool isOK;
    for(unsigned k=0;k<m_nbSteps;k++)
    {
        // Calcul de la direction pour fuir
        int dX = x - m_X;
        int dY = y - m_Y;
        double d = sqrt( dX*dX + dY*dY );
        
        if( ((d<5) || m_EnFuite) && (d!=0) ) // si le chat est trop proche (et pas mangé), on fuit
        {
            m_EnFuite = true;

            // plan A = on éloigne la direction la plus proche
            if( dX*dX >= dY*dY ) // le chat est plus près en Y
            {
                if(dY>=0)
                {
                    dir = 3; // y--
                }
                else
                {
                    dir = 2; // y++
                }
            }
            else // le chat est plus près en X
            {
                if(dX>=0)
                {
                    dir = 1; // x--
                }
                else
                {
                    dir = 0; // x++
                }
            }
            isOK = UpdatePosition(dir);

            if(!isOK)
            {
                // plan B = plan A impossible = on éloigne l'autre direction
                if( dX*dX >= dY*dY ) // le chat est plus près en Y
                {
                    if(dX>=0)
                    {
                        dir = 1; // x--
                    }
                    else
                    {
                        dir = 0; // x++
                    }
                }
                else // le chat est plus près en X
                {
                    if(dY>=0)
                    {
                        dir = 3; // y--
                    }
                    else
                    {
                        dir = 2; // y++
                    }
                }
                isOK = UpdatePosition(dir);
                
                // plan C = on bouge aléatoirement
                while(!isOK)
                {
                    int dir = rand() % 4; // direction aléatoire
                    isOK = UpdatePosition(dir);
                }
            }
        }
    }
}


