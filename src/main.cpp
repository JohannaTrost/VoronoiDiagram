#include "grid.h"
#include <cstdio>
#include <cstdlib>
#include <time.h>
#include <iostream>

int main()
{
    grid grid(3, 4);
    grid.modifhauteur(2, 2, 5);
    grid.affichage();
    return EXIT_SUCCESS;
}
