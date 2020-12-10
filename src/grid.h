#ifndef _GRID
#define _GRID
#include <vector>
#include <string>
#include <fstream>
#include <iterator>
#include <iostream>
#include <cmath>
#include <stdint.h>

using namespace std;

class noeud
{
    friend class grid;

private:
    int hauteur; //La hauteur du noeud
};

class noeudParcoursLarg
{
    friend class grid;

public:
    char couleur;
    int pere;
    float distance;
    int coloration;
};

class grid
{
public:
    //Constructeur-------------------------------------------------------------
    grid(const int C, const int L);
    //Paramètres : C nombre de colonnes, L nombre de lignes

    //Constructeur par fichier---------------------------------------------------
    grid(const string fichier);

    //Constructeur par copie---------------------------------------------------
    grid(const grid &copie);

    //Destructeur---------------------------------------------------------------
    ~grid();

    int getTaille() const;

    int getLine() const;

    int getCol() const;

    void modifhauteur(const int L, const int C, const int h);
    //Précondition : L et C compris dans la grille
    //Résultat : la hauteur du noeud L,C est h

    int indice(const int i, const int j);
    //Précondition : i et j compris dans la grille
    //Résultat : renvoie l'indice de la case du tableau où est contenu le noeud (i,j)

    int ligne(const int indice);
    //Précondition : indice compris dans le tableau
    //Résultat : renvoie la ligne de la grille où est le noeud contenu à l'indice "indice" du tableau

    int colonne(const int indice);
    //Précondition : indice compris dans le tableau
    //Résultat : renvoie la colonne de la grille où est le noeud contenu à l'indice "indice" du tableau

    int hauteur(const int indice);
    //Précondition : indice compris dans le tableau
    //Résultat : renvoie la chauteur du noeud contenu à l'indice "indice" du tableau

    bool existNord(const int i);
    //Précondition : 0 < i < nombre de lignes de la grille
    //Résultat : renvoie true si les noeuds de la ligne i ont un voisinNord, false sinon

    bool existSud(const int i);
    //Précondition : 0 < i < nombre de lignes de la grille
    //Résultat : renvoie true si les noeuds de la ligne i ont un voisin Sud, false sinon

    bool existEst(const int j);
    //Précondition : 0 < j < nombre de colonnes de la grille
    //Résultat : renvoie true si les noeuds de la ligne i ont un voisin Est, false sinon

    bool existOuest(const int j);
    //Précondition : 0 < j < nombre de colonnes de la grille
    //Résultat : renvoie true si les noeuds de la ligne i ont un voisin Ouest, false sinon

    int indiceNord(const int i, const int j);
    //Précondition : i et j compris dans la grille et le noeud (i,j) a un voisin Nord
    //Résultat : renvoie l'indice de la case du tableau où est contenu le voisin Nord du noeud (i,j), -1 si le noeud n'existe pas, -2 si il n'a pas de voisin

    int indiceSud(const int i, const int j);
    //Précondition : i et j compris dans la grille et le noeud (i,j) a un voisin Sud
    //Résultat : renvoie l'indice de la case du tableau où est contenu le voisin Sud du noeud (i,j), -1 si le noeud n'existe pas, -2 si il n'a pas de voisin

    int indiceEst(const int i, const int j);
    //Précondition : i et j compris dans la grille et le noeud (i,j) a un voisin Est
    //Résultat : renvoie l'indice de la case du tableau où est contenu le voisin Est du noeud (i,j), -1 si le noeud n'existe pas, -2 si il n'a pas de voisin

    int indiceOuest(const int i, const int j);
    //Précondition : i et j compris dans la grille et le noeud (i,j) a un voisin Ouest
    //Résultat : renvoie l'indice de la case du tableau où est contenu le voisin Ouest du noeud (i,j), -1 si le noeud n'existe pas, -2 si il n'a pas de voisin

    void affichage();
    //Précondition : None

    float distanceVoisin(const int indiceA, const int indiceB);
    //Précondition : indice a et b compris dans la grille
    //Résultat : revoie la distance euclidienne entre l'indice a et b en prenant en compte ses hauteurs

private:
    std::vector<noeud *> g; //Le tableau 1D de noeuds
    int col, line;          //Nombre de colonne et de lignes de la grille
};

class ParcoursLargeur
{
    friend class grid;

public:
    ~ParcoursLargeur();

    std::vector<noeudParcoursLarg *> pl;

    ParcoursLargeur(grid &g, const vector<int> indiceDepart);

    std::vector<int> vecVoisins(const int indice, grid graphe);

    void affichage(const grid g) const;
    //Précondition : None

    int defileMinimum(std::vector<int> &f, std::vector<noeudParcoursLarg *> pl);
};

#endif
