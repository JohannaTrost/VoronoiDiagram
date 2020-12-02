#include <iostream>
#include "grid.h"

grid::grid(const int C, const int L)
{
    for (int i = 0; i < L * C; i++)
    {
        noeud *nouveau = new noeud;
        nouveau->hauteur = 0;
        g.push_back(nouveau);
    }

    col = C;
    line = L;
}

grid::~grid()
{
    for (noeud *n : g)
        delete n;
    g.clear();
}

void grid::affichage()
{
    for (int i = 0; i < line; i++)
    {
        for (int j = 0; j < col; j++)
            std::cout << g.at(i)->hauteur << "  ";
        std::cout << std::endl;
    }
}

void grid::modifhauteur(const int i, const int j, const int h)
{
    g.at(i * col + j)->hauteur = h;
}

int grid::indice(const int i, const int j)
{
    return i * col + j;
}

int grid::colonne(const int indice)
{
    return indice % col;
}

int grid::ligne(const int indice)
{
    return indice / col;
}

int grid::hauteur(const int indice)
{
    return g.at(indice)->hauteur;
}

bool grid::existNord(const int i)
{
    return i - 1 >= 0;
}

bool grid::existSud(const int i)
{
    return i + 1 < line;
}

bool grid::existEst(const int j)
{
    return j + 1 < col;
}

bool grid::existOuest(const int j)
{
    return j - 1 >= 0;
}

int grid::indiceNord(const int i, const int j)
{
    return (i - 1) * col + j;
}

int grid::indiceSud(const int i, const int j)
{
    return (i + 1) * col + j;
}

int grid::indiceEst(const int i, const int j)
{
    return i * col + (j + 1);
}

int grid::indiceOuest(const int i, const int j)
{
    return i * col + (j - 1);
}