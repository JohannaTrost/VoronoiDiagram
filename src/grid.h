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
    void destructeur(const std::vector<noeud> g);
    //Precondition : aucune
    //Resultat :le noeud nd est détruit et destructeur() est appelé sur les fils existants de nd
    std::vector<noeud> g;
};

#endif