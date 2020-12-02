#ifndef _GRID
#define _GRID
#include <vector>

class noeud
{
    friend class grid;

private:
};

class grid
{
public:
    //Constructeur-------------------------------------------------------------
    grid();

    grid(const grid &grid);
    //Postcondition : Aucunes

    grid &operator=(const grid &copie);
    //Précondition : aucune
    //Postcondition :

    //Destructeur---------------------------------------------------------------
    ~grid();

private:

    std::vector<noeud> g;
};

#endif