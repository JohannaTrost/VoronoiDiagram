#include "grid.h"
#include <cstdio>
#include <cstdlib>
#include <time.h>
#include <iostream>

int main()
{
    grid grid1(3, 4);
    grid1.modifhauteur(2, 2, 5);
    grid1.affichage();

    grid grid2(grid1);
    std::cout << std::endl;
    grid2.affichage();
    return EXIT_SUCCESS;
}
