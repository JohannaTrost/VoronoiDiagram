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

grid::grid(const string fichier)
{
  std::vector<std::string> vecDeStrs;
  // ouvrir fichier
  std::ifstream input(fichier);

  if(!input)
  {
      std::cerr << "Ne pas pouvoir ouvrir le fichier : "<<fichier<<std::endl;
  }
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
  }
  //Close The File
  input.close();
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
