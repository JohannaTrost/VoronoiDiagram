/**
    Demonstration d'utilisation de Grid et SitesLibrairies
    @file main.cpp
    @author Emie Lafourcade, Johanna Trost
    @version 1.0 12/12/20
*/

#include "Grid.h"
#include <cstdio>
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <boost/program_options.hpp>

using namespace boost::program_options;

int main(int argc, const char **argv)
{
    srand(time(NULL));
    Grid * grid;

    try
    {
      options_description desc("Allowed options");
      desc.add_options()
          ("help,h", "produce help message")
          ("input-file-grid,g", value<string>()->default_value(""), "Nom du ficher txt qui contient la grille"
                                               " qui est ensuite visualisée."
                                               " E.g. grille.txt. Si vous ne le"
                                               " specifiez pas la grille est crée"
                                               " de manière aléatoire")
           ("input-file-sites,s", value<string>()->default_value(""), "Nom du ficher txt qui contient les indices"
                                                " des sites qui sont ensuite visualisées."
                                                " E.g. sites.txt. Si vous ne le"
                                                " specifiez pas les sites sont choisis"
                                                " de manière aléatoire") // bool_switch()
          ("indices,i", value<vector<int> >()->multitoken(), "indice (ligne,colonne) e.g. (0,3) "
                                                             "pour afficher tous les voisins du sommet (i,j)")
      ;

      variables_map vm;
      store(parse_command_line(argc, argv, desc), vm);
      notify(vm);

      if (vm.count("help"))
      {
          cout << desc << "\n";
          return 1;
      }

      if (vm.count("input-file-grid"))
      {
          string filenameGrid = vm["input-file-grid"].as<string>();
          cout << "------------------------------------------------------\n"
               << "\tLa grille \n"
               << "------------------------------------------------------" << endl;
          cout << "\n";

          if(filenameGrid == "")
          {
            // creation d'une grille avec nb cols et lignes et modif d'hauteur
            cout << "Grille generée de manière aléatoire: " << ":\n" << endl;
            int colonnes = (rand() % 10 + 3);
            int lignes = (rand() % 10 + 3);
            grid = new Grid(lignes, colonnes);
            for (int h = 0; h < lignes * colonnes - 1; h++)
                grid->modifhauteur(grid->ligne(h), grid->colonne(h), rand() % 50);
            grid->affichage();
            cout << endl;
          }
          else
          {
            // creation de la grille à partir du fichier txt
            cout << "Grille du fichier " << filenameGrid << ":\n" << endl;
            grid = new Grid(filenameGrid);
            grid->affichage();
            cout << endl;
          }
      }

      if (vm.count("input-file-sites"))
      {
          string filenameSites = vm["input-file-sites"].as<string>();
          cout << "------------------------------------------------------\n"
               << "\tLibrairies de la grille \n"
               << "------------------------------------------------------" << endl;
          cout << "\n";
          
          if(filenameSites == "")
          {
            int nbPoints = 4;
            vector<int> indicesSites;
            int indice;

            cout << "Indices des sites: " << endl;
            for (int x = 0; x < nbPoints-1; x++)
            {
                indice = rand() % ((grid->getLine() * grid->getCol()) - 1);
                cout << indice << ", ";
                indicesSites.push_back(indice);
            }
            indice = rand() % ((grid->getLine() * grid->getCol()) - 1);
            cout << indice << "\n" << endl;
            indicesSites.push_back(indice);

            SitesLibrairies librairies(*grid, "", indicesSites);
            librairies.affichage(*grid);
          }
          else
          {
            SitesLibrairies librairies(*grid, filenameSites);
            librairies.affichage(*grid);
            cout << endl;
          }
      }

      if(vm.count("indices"))
      {
        vector<int> indices = vm["indices"].as<vector<int>>();
        int i = indices[0];
        int j = indices[1];

        cout << "\nL'hauteur à (" << i << "," << j << ") est: " << grid->hauteur(grid->indice(i, j)) << endl;

        int index = grid->indiceOuest(i, j);
        if (index != -1 && index != -2)
        {
            cout << "\t L'hauteur à l'ouest est: " << grid->hauteur(index) << endl;
        }
        else
        {
           cout << "\tPas de sommet à l'ouest" << endl;
        }

        index = grid->indiceNord(i, j);
        if (index != -1 && index != -2)
        {
            cout << "\t L'hauteur au nord est: " << grid->hauteur(index) << endl;
        }
        else
        {
           cout << "\tPas de sommet au nord" << endl;
        }

        index = grid->indiceEst(i, j);
        if (index != -1 && index != -2)
        {
            cout << "\t L'hauteur à l'est est: " << grid->hauteur(index) << endl;
        }
        else
        {
           cout << "\tPas de sommet à l'est" << endl;
        }

        index = grid->indiceSud(i, j);
        if (index != -1 && index != -2)
        {
            cout << "\t L'hauteur au sud est: " << grid->hauteur(index) << endl;
        }
        else
        {
           cout << "\tPas de sommet au sud" << endl;
        }
      }
    }
    catch (const error &ex)
   {
     cerr << ex.what() << '\n';
   }

    return EXIT_SUCCESS;
}
