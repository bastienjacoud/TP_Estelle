#include "CAnimal.h"

CAnimal::CAnimal()
{
    m_X = 1;
    m_Y = 1;
    m_dimX = 0;
    m_dimY = 0;
    m_Xold = -1;
    m_Yold = -1;

    m_nbSteps = 1;
    m_step = 1;
}

CAnimal::CAnimal(int nbSteps, int step)
{
    m_X = 1;
    m_Y = 1;
    m_dimX = 0;
    m_dimY = 0;
    m_Xold = -1;
    m_Yold = -1;

    m_nbSteps = nbSteps;
    m_step = step;
}

CAnimal::~CAnimal()
{

}

int CAnimal::GetX()
{
    return m_X;
}

int CAnimal::GetY()
{
    return m_Y;
}

void CAnimal::SetTerrain(int x, int y, int dimX, int dimY)
{
    m_X = x;
    m_Y = y;
    m_dimX = dimX;
    m_dimY = dimY;
}

void CAnimal::Deplace()
{
    int dir;
    bool isOK;
    for(unsigned k=0;k<m_nbSteps;k++)
    {
        isOK = false;
        while(!isOK)
        {
            dir = rand() % 4; // Tirage d'une direction aléatoire
            isOK = UpdatePosition(dir);
        }
    }
}

bool CAnimal::UpdatePosition(int dir)
{
    // On actualise la position si:
    // 1) on reste dans les limites du terrain
    // 2) on ne revient pas à la position antérieure
    bool isOK = false;
    switch(dir)
    {
        case 0:
            if( (m_X<m_dimX-m_step) && (m_X+m_step!=m_Xold) )
            {
                m_Xold = m_X;
                m_Yold = m_Y;
                m_X += m_step;
                isOK = true;
            }
            break;
        case 1:
            if( (m_X>m_step-1) && (m_X-m_step!=m_Xold) )
            {
                m_Xold = m_X;
                m_Yold = m_Y;
                m_X -= m_step;
                isOK = true;
            }
            break;
        case 2:
            if( (m_Y<m_dimY-m_step) && (m_Y+m_step!=m_Yold) )
            {
                m_Xold = m_X;
                m_Yold = m_Y;
                m_Y += m_step;
                isOK = true;
            }
            break;
        case 3:
            if( (m_Y>m_step-1) && (m_Y-m_step!=m_Yold) )
            {
                m_Xold = m_X;
                m_Yold = m_Y;
                m_Y -= m_step;
                isOK = true;
            }
            break;
    }
    return isOK;
}