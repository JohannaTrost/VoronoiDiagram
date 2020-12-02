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

    void modifhauteur(const int C, const int L, const int h);

    int indice(const int i, const int j);

    int ligne (const int indice);
    int colonne (const int indice);
    int hauteur (const int indice);
    
private:
    std::vector<noeud *> g;
    int col, line;
};

#endif