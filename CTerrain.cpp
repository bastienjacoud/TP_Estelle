#include "CTerrain.h"

CTerrain::CTerrain()
{
	m_dimX = 0;
	m_dimY = 0;
}

CTerrain::CTerrain(int dimX, int dimY)
{    
	m_dimX = dimX;
	m_dimY = dimY;
}

CTerrain::~CTerrain()
{

}

int CTerrain::GetDimX()
{
	return m_dimX;
}

int CTerrain::GetDimY()
{
	return m_dimY;
}

void CTerrain::Affiche(CChat* chat, CSouris* souris)
{
    cout << "chat=" << chat->GetX() << "," << chat->GetY() << endl;
    cout << "souris=" << souris->GetX() << "," << souris->GetY() << endl;
    
    for(int i=-1;i<m_dimY+1;i++) // rows (+1 margin on each side)
    {
        if( (i==-1) || (i==m_dimY) )
        {
            for(int j=-1;j<m_dimX+1;j++) // columns (+1 margin on each side)
            {
                cout << "X";
            }
        }
        else
        {
            for(int j=-1;j<m_dimX+1;j++) // columns (+1 margin on each side)
            {
                if( (j==-1) || (j==m_dimX) )
                {
                    cout << "X";
                }
                else
                {
                    if( (chat->GetX()==j) && (chat->GetY()==i) )
                    {
                        cout << "C";
                    }
                    else if( (souris->GetX()==j) && (souris->GetY()==i) )
                    {
                        cout << "S";
                    }
                    else
                    {
                        cout << " ";
                    }
                }
            }
        }
        cout << endl;
    }    
}
