/**
    Demonstration d'utilisation de Grid et SitesLibrairies
    @file main.cpp
    @author Emie Lafourcade, Johanna Trost
    @version 1.0 12/12/20
*/

#include "grid.h"
#include <cstdio>
#include <cstdlib>
#include <time.h>
#include <iostream>

int main(int argc, const char **argv)
{
    srand(time(NULL));
    string filenameGrid(argv[1]);
    string filenameSites;
    if(argv[2] != NULL) filenameSites = argv[2];

    // test constructeur avec fichier
    Grid gridDeFichier(filenameGrid);
    gridDeFichier.affichage();
    cout << endl;

    // test index nord
    cout << "nord de " << gridDeFichier.hauteur(gridDeFichier.indice(2, 3)) << ": " << gridDeFichier.hauteur(gridDeFichier.indiceNord(2, 3)) << endl;
    // verifier s'il y a une valeur à l'est de (2,3)
    if (!gridDeFichier.existEst(3))
        cout << "Rien à l'est de " << gridDeFichier.hauteur(gridDeFichier.indice(2, 3)) << endl
             << endl;

    // test constructeur avec nb cols et lignes et modif d'hauteur
    // int colonnes = (rand() % 10 + 3);
    // int lignes = (rand() % 10 + 3);
    int colonnes = 10;
    int lignes = 20;
    Grid gridLC(lignes, colonnes);
    for (int h = 0; h < lignes * colonnes - 1; h++)
        gridLC.modifhauteur(gridLC.ligne(h), gridLC.colonne(h), rand() % 50);
    gridLC.affichage();
    cout << endl;

    // test fonction de distance
    cout << "Distance entre (0,0) et (0,1): " << gridDeFichier.distanceVoisin(gridDeFichier.indice(0, 0), gridDeFichier.indice(0, 1)) << endl
         << endl;
    ;

    vector<int> vecIndicesGridLC;
    int points = 4;
    for (int x = 0; x < points; x++)
        vecIndicesGridLC.push_back(rand() % ((lignes * colonnes) - 1));

/*
    vector<int> vecIndicesGridFichier;
    for (int y = 0; y < 2; y++)
        vecIndicesGridFichier.push_back(rand() % 10);
*/
    SitesLibrairies parcours(gridDeFichier, filenameSites);
    parcours.affichage(gridDeFichier);
    cout << endl;

    cout << "Distance entre (0,0) et (0,1): " << gridLC.distanceVoisin(gridLC.indice(0, 0), gridLC.indice(0, 1)) << endl
         << endl;

    SitesLibrairies parcours1(gridLC, "", vecIndicesGridLC);
    parcours1.affichage(gridLC);

    return EXIT_SUCCESS;
}
