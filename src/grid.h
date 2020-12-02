#ifndef _GRID
#define _GRID
#include <vector>

class noeud
{
    friend class grid;

private:
    int hauteur;
};

class grid
{
public:
    //Constructeur-------------------------------------------------------------
    grid(const int C, const int L);

    //Destructeur---------------------------------------------------------------
    ~grid();

private:
    std::vector<noeud *> g;
};

#endif