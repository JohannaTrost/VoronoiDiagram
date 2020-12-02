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

grid::grid(const string fichier)
{
  // ouvrir fichier
  std::ifstream input(fichier);

  if(!input)
  {
      std::cerr << "Ne pas pouvoir ouvrir le fichier : "<<fichier<<std::endl;
  }
  else
  {
    vector<int> vec((istream_iterator<int>(input)), istream_iterator<int>());
    col = vec.at(0);
    line = vec.at(1);
    for(std::vector<int>::size_type i = 2; i != vec.size(); i++)
    {
      noeud *nouveau = new noeud;
      nouveau->hauteur = vec[i];
      cout << vec[i] << " hauteur" << nouveau->hauteur << endl;
      g.push_back(nouveau);
    }
  }
  /*
  std::string str;
  // Lisez la ligne suivante du fichier jusqu'à la fin.
  while (std::getline(input, str))
  {
      // La ligne contient une chaîne de longueur > 0 puis l'enregistre dans un vecteur
      if(str.size() > 0)
      {
          vecDeStrs.push_back(str);
          cout << str << endl;
      }
  }*/
  //Close The File
  input.close();

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
