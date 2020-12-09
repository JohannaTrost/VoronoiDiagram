#include "grid.h"
#include <cstdio>
#include <cstdlib>
#include <time.h>
#include <iostream>

int main(int argc, const char **argv)
{
    string filename(argv[1]);

    // test constructeur avec fichier
    grid gridDeFichier(filename);
    gridDeFichier.affichage();

    // test index nord
    cout << "nord de " << gridDeFichier.hauteur(gridDeFichier.indice(2, 3)) << ": " << gridDeFichier.hauteur(gridDeFichier.indiceNord(2, 3)) << endl;
    // verifier s'il y a une valeur à l'est de (2,3)
    if (!gridDeFichier.existEst(3))
        cout << "Rien à l'est de " << gridDeFichier.hauteur(gridDeFichier.indice(2, 3)) << endl;

    // test constructeur avec nb cols et lignes et modif d'hauteur
    grid grid34(3, 4);
    grid34.modifhauteur(2, 2, 5);
    grid34.affichage();

    // test fonction de distance
    cout << "Distance entre (0,0) et (0,1): " << gridDeFichier.distance(gridDeFichier.indice(0,0), gridDeFichier.indice(0,1)) << endl;

    return EXIT_SUCCESS;
}
