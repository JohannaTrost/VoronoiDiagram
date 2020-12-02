#include <iostream>
#include "grid.h"

grid::grid(const int C, const int L)
{
    noeud *nouveau = new noeud;
    nouveau->hauteur = 0;

    for (int i = 0; i < L * C; i++)
        g.push_back(nouveau);
}