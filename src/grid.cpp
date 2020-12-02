#include <iostream>
#include "grid.h"

grid::grid(const int L, const int C)
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

grid::grid(const grid &copie)
{

    col = copie.col;
    line = copie.line;
    for (unsigned int i = 0; i < copie.g.size(); i++)
    {
        noeud *nouveau = new noeud;
        nouveau->hauteur = copie.g.at(i)->hauteur;
        g.push_back(nouveau);
    }
}

grid::~grid()
{
    for (noeud *n : g)
        delete n;
    g.clear();
}

void grid::affichage()
{
    int n = 0;
    for (int i = 0; i < line; i++)
    {
        for (int j = 0; j < col; j++)
        {
            std::cout << g.at(n)->hauteur << "  ";
            n++;
        }

        std::cout << std::endl;
    }
}

void grid::modifhauteur(const int i, const int j, const int h)
{
    if (i < line && j < col && i >= 0 && j >= 0)
        g.at(indice(i, j))->hauteur = h;
    else
        std::cout << "ce noeud n'existe pas" << std::endl;
}

int grid::indice(const int i, const int j)
{
    if (i < line && j < col && i >= 0 && j >= 0)
        return i * col + j;
    else
        return -1;
}

int grid::colonne(const int indice)
{
    if ((unsigned int)indice < g.size() && indice >= 0)
        return indice % col;
    else
    {
        std::cout << "ce noeud n'existe pas" << std::endl;
        return -1;
    }
}

int grid::ligne(const int indice)
{
    if ((unsigned int)indice < g.size() && indice >= 0)
        return indice / col;
    else
    {
        std::cout << "ce noeud n'existe pas" << std::endl;
        return -1;
    }
}

int grid::hauteur(const int indice)
{
    if ((unsigned int)indice < g.size() && indice >= 0)
        return g.at(indice)->hauteur;
    else
    {
        std::cout << "ce noeud n'existe pas" << std::endl;
        return -1;
    }
}

bool grid::existNord(const int i)
{
    if (i < line && i >= 0)
        return i - 1 >= 0;
    else
    {
        std::cout << "ce noeud n'existe pas" << std::endl;
        return false;
    }
}

bool grid::existSud(const int i)
{
    if (i < line && i >= 0)
        return i + 1 < line;

    else
    {
        std::cout << "ce noeud n'existe pas" << std::endl;
        return false;
    }
}

bool grid::existEst(const int j)
{
    if (j < col && j >= 0)
        return j + 1 < col;
    else
    {
        std::cout << "ce noeud n'existe pas" << std::endl;
        return false;
    }
}

bool grid::existOuest(const int j)
{
    if (j < col && j >= 0)
        return j - 1 >= 0;
    else
    {
        std::cout << "ce noeud n'existe pas" << std::endl;
        return false;
    }
}

int grid::indiceNord(const int i, const int j)
{
    if (i < line && j < col && i >= 0 && j >= 0)
        return (i - 1) * col + j;
    else
    {
        std::cout << "ce noeud n'existe pas" << std::endl;
        return -1;
    }
}

int grid::indiceSud(const int i, const int j)
{
    if (i < line && j < col && i >= 0 && j >= 0)
        return (i + 1) * col + j;
    else
    {
        std::cout << "ce noeud n'existe pas" << std::endl;
        return -1;
    }
}

int grid::indiceEst(const int i, const int j)
{
    if (i < line && j < col && i >= 0 && j >= 0)
        return i * col + (j + 1);

    else
    {
        std::cout << "ce noeud n'existe pas" << std::endl;
        return -1;
    }
}

int grid::indiceOuest(const int i, const int j)
{
    if (i < line && j < col && i >= 0 && j >= 0)
        return i * col + (j - 1);
    else
    {
        std::cout << "ce noeud n'existe pas" << std::endl;
        return -1;
    }
}