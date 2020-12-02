#include <iostream>
#include "grid.h"

grid::grid(const int C, const int L)
{
    noeud *nouveau = new noeud;
    nouveau->hauteur = 0;

    for (int i = 0; i < L * C; i++)
        g.push_back(nouveau);

    col=C;
    line=L;
}

void grid::modifhauteur(const int i, const int j, const int h)
{
    g.at(i*col+j)->hauteur=h;
}

int grid::indice(const int i, const int j)
{
    return i*col+j;
}

int grid::colonne (const int indice)
{
    return indice%col;
}

int grid::ligne (const int indice)
{
    return indice/col;
}

int grid::hauteur (const int indice)
{
    return g.at(indice)->hauteur;
}