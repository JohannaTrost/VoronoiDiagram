#include "grid.h"
#include <cstdio>
#include <cstdlib>
#include <time.h>
#include <iostream>

int main()
{
    grid g ("../grille_ex1.txt");
    g.affichage();
    grid grid(3, 4);
    grid.affichage();
    return EXIT_SUCCESS;
}
