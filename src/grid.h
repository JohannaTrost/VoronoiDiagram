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

    int ligne(const int indice);
    int colonne(const int indice);
    int hauteur(const int indice);

    bool existNord(const int i);
    bool existSud(const int i);
    bool existEst(const int i);
    bool existOuest(const int i);

    int indiceNord(const int i, const int j);
    int indiceSud(const int i, const int j);
    int indiceEst(const int i, const int j);
    int indiceOuest(const int i, const int j);

    void affichage();

private:
    std::vector<noeud *> g;
    int col, line;
};

#endif