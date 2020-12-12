/**
    Interface des classes Grid, Noeud et SitesLibrairies
    @file Grid.cpp
    @author Emie Lafourcade, Johanna Trost
    @version 1.0 12/12/20
*/

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

class Noeud
{
    friend class Grid;

private:
    int hauteur; //La hauteur du Noeud
};

class NoeudParcoursLarg
{
    friend class Grid;

public:
    char couleur;
    int pere;
    int fils;
    float distance;
    int coloration;
};

class Grid
{
public:
    //Constructeur-------------------------------------------------------------
    Grid(const int C, const int L);
    //Paramètres : C nombre de colonnes, L nombre de lignes

    //Constructeur par fichier-------------------------------------------------
    Grid(const string fichier);

    //Constructeur par copie---------------------------------------------------
    Grid(const Grid &copie);

    //Destructeur--------------------------------------------------------------
    ~Grid();

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
    std::vector<Noeud *> g; //Le tableau 1D de noeuds
    int col, line;          //Nombre de colonne et de lignes de la grille
};

class SitesLibrairies
{
    friend class Grid;

public:
    ~SitesLibrairies();

    std::vector<NoeudParcoursLarg *> pl;

    SitesLibrairies(Grid &g, const string fichier="", vector<int> indiceDepart=vector<int>());

    std::vector<int> vecVoisins(const int indice, Grid graphe);

    void affichage(const Grid g) const;
    //Précondition : None

private:
    void coloration(Grid &g, const vector<int> indiceDepart);
    //Précondition : grid g et pl comprennent bien tous indices dans indiceDepart
    //Résultat : couleurs associées aux sites sont stocké dans membre couleur de neouds de pl

    int defileMinimum(std::vector<int> &f, std::vector<NoeudParcoursLarg *> pl);
};

#endif