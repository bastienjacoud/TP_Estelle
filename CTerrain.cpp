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

void CTerrain::Affiche(std::vector<CChat> vchats, std::vector<CSouris> vsouris)
{
    for(auto &chat : vchats){
        cout << "chat=" << chat.GetX() << "," << chat.GetY() << endl;
    }

    for(auto &souris : vsouris){
        cout << "souris=" << souris.GetX() << "," << souris.GetY() << endl;
    }

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
                    bool libre(true);
                    for(int k(0); (k < vchats.size()) && libre; k++) {
                        if ((vchats[k].GetX() == j) && (vchats[k].GetY() == i)) {
                            cout << "C";
                            libre = false;
                        }
                    }
                    for(int k(0); (k < vsouris.size()) && libre; k++) {
                        if ((vsouris[k].GetX() == j) && (vsouris[k].GetY() == i)) {
                            cout << "S";
                            libre = false;
                        }
                    }
                    if(libre) {
                        cout << " ";
                    }
                }
            }
        }
        cout << endl;
    }
}
