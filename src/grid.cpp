#include "grid.h"

grid::grid(const int L, const int C) //Constructeur avec paramètres
{
    for (int i = 0; i < L * C; i++) //On fait un tableau de taille L*C
    {
        noeud *nouveau = new noeud;
        nouveau->hauteur = 0; //On met la hauteur de tous les noeuds à 0
        g.push_back(nouveau); //On met le noeud à la suite dans le tableau
    }

    col = C;  //Le nombre de(g.colonnes de la grille est C
    line = L; //Le nombre de lignes de la grille est L
}

grid::grid(const grid &copie) //Constructeur par copie
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

grid::grid(const string fichier) //Constructeur avec fichier
{
    // ouvrir fichier
    std::ifstream input(fichier);

    if (!input)
    {
        std::cerr << "Ne pas pouvoir ouvrir le fichier : " << fichier << std::endl;
    }
    else
    {
        vector<int> vec((istream_iterator<int>(input)), istream_iterator<int>());
        col = vec.at(0);
        line = vec.at(1);
        for (std::vector<int>::size_type i = 2; i != vec.size(); i++)
        {
            noeud *nouveau = new noeud;
            nouveau->hauteur = vec[i];
            g.push_back(nouveau);
        }
    }
    //Close The File
    input.close();
}
grid::~grid() //destructeur
{
    for (noeud *n : g)
        delete n; //On detruit chaque noeud
    g.clear();    //Puis on vide le vecteur
}

int grid::getTaille() const
{
  return col*line;
}

void grid::affichage()
{
    int n = 0;
    for (int i = 0; i < line; i++) //On parcours les lignes
    {
        for (int j = 0; j < col; j++) //On parcours les(g.colonnes
        {
            std::cout << g.at(n)->hauteur << "  ";
            n++;
        }

        std::cout << std::endl;
    }
}

void grid::modifhauteur(const int i, const int j, const int h)
{
    if (i < line && j < col && i >= 0 && j >= 0) //On verifie que le noeud (i,j) existe
        g.at(indice(i, j))->hauteur = h;         //on lui met la hauteur h
    else
        std::cout << "ce noeud n'existe pas" << std::endl;
}

int grid::indice(const int i, const int j)
{
    if (i < line && j < col && i >= 0 && j >= 0) //On verifie que le noeud (i,j) existe
        return i * col + j;                      //On retourne son indice dans la tableau
    else
    {
        std::cout << "ce noeud n'existe pas" << std::endl;
        return -1; //On retourne -1 si le noeud n'existe pas
    }
}

int grid::colonne(const int indice)
{
    if ((unsigned int)indice < g.size() && indice >= 0) //On verifie que l'indice du noeud est dans le tableau
        return indice % col;                            //On retourne la(g.colonne de la grille dans laquelle le noeud est
    else
    {
        std::cout << "ce noeud n'existe pas" << std::endl;
        return -1; //On retourne -1 si le noeud n'existe pas
    }
}

int grid::ligne(const int indice)
{
    if ((unsigned int)indice < g.size() && indice >= 0) //On verifie que l'indice du noeud est dans le tableau
        return indice / col;                            //On retourne la ligne de la grille dans laquelle le noeud est
    else
    {
        std::cout << "ce noeud n'existe pas" << std::endl;
        return -1; //On retourne -1 si le noeud n'existe pas
    }
}

int grid::hauteur(const int indice)
{
    if ((unsigned int)indice < g.size() && indice >= 0) //On verifie que l'indice du noeud est dans le tableau
        return g.at(indice)->hauteur;                   //On retourne sa hauteur
    else
    {
        std::cout << "ce noeud n'existe pas" << std::endl;
        return -1; //On retourne -1 si le noeud n'existe pas
    }
}

bool grid::existNord(const int i)
{
    if (i < line && i >= 0) //On verifie que la ligne du noeud est dans la grille
        return i - 1 >= 0;  //On retourne si la ligne d'au dessus existe
    else
    {
        // std::cout << "ce noeud n'existe pas" << std::endl;
        return false; //On retourne faux si le noeud n'existe pas
    }
}

bool grid::existSud(const int i)
{
    if (i < line && i >= 0)  //On verifie que la ligne du noeud est dans la grille
        return i + 1 < line; //On retourne si la ligne d'au dessous existe

    else
    {
        // std::cout << "ce noeud n'existe pas" << std::endl;
        return false; //On retourne faux si le noeud n'existe pas
    }
}

bool grid::existEst(const int j)
{
    if (j < col && j >= 0)  //On verifie que la(g.colonne du noeud est dans la grille
        return j + 1 < col; //On retourne si la(g.colonne à sa droite existe
    else
    {
        // std::cout << "ce noeud n'existe pas" << std::endl;
        return false; //On retourne faux si le noeud n'existe pas
    }
}

bool grid::existOuest(const int j)
{
    if (j < col && j >= 0) //On verifie que la(g.colonne du noeud est dans la grille
        return j - 1 >= 0; //On retourne si la(g.colonne à sa gauche existe
    else
    {
        // std::cout << "ce noeud n'existe pas" << std::endl;
        return false; //On retourne faux si le noeud n'existe pas
    }
}

int grid::indiceNord(const int i, const int j)
{
    if (i < line && j < col && i >= 0 && j >= 0) //On verifie que le noeud (i,j) existe
    {
        if (existNord(i))             //On verifie que son voisin Nord existe
            return (i - 1) * col + j; //On retourne son indice dans le tableau
        else
            return -2; //On retourne -2 si le voisin n'existe pas
    }
    else
    {
        std::cout << "ce noeud n'existe pas" << std::endl;
        return -1; //On retourne -1 si le noeud n'existe pas
    }
}

int grid::indiceSud(const int i, const int j)
{
    if (i < line && j < col && i >= 0 && j >= 0) //On verifie que le noeud (i,j) existe
    {
        if (existSud(i))              //On verifie que son voisin Sud existe
            return (i + 1) * col + j; //On retourne son indice dans le tableau
        else
            return -2; //On retourne -2 si le voisin n'existe pas
    }
    else
    {
        std::cout << "ce noeud n'existe pas" << std::endl;
        return -1; //On retourne -1 si le noeud n'existe pas
    }
}

int grid::indiceEst(const int i, const int j)
{
    if (i < line && j < col && i >= 0 && j >= 0) //On verifie que le noeud (i,j) existe
    {
        if (existEst(j))              //On verifie que son voisin Est existe
            return i * col + (j + 1); //On retourne son indice dans le tableau
        else
            return -2; //On retourne -2 si le voisin n'existe pas
    }
    else
    {
        std::cout << "ce noeud n'existe pas" << std::endl;
        return -1; //On retourne -1 si le noeud n'existe pas
    }
}

int grid::indiceOuest(const int i, const int j)
{
    if (i < line && j < col && i >= 0 && j >= 0) //On verifie que le noeud (i,j) existe
    {
        if (existOuest(j))            //On verifie que son voisin Ouest existe
            return i * col + (j - 1); //On retourne son indice dans le tableau
        else
            return -2; //On retourne -2 si le voisin n'existe pas
    }
    else
    {
        std::cout << "ce noeud n'existe pas" << std::endl;
        return -1; //On retourne -1 si le noeud n'existe pas
    }
}

float grid::distanceVoisin(const int indiceA, const int indiceB)
{
  int diffAB= hauteur(indiceA) - hauteur(indiceB);
  return sqrt(1+diffAB*diffAB); // distance euclidienne
}

void ParcoursLargeur::parcoursEnLargeur(grid & g, const int indiceDepart)
{
      // init tableau parcours largeur
      for (int i = 0; i < g.getTaille(); i++)
      {
          noeudParcoursLarg *nouveau = new noeudParcoursProf;
          nouveau->distance = INT_MAX; //On met la hauteur de tous les noeuds à 0
          nouveau->pere = INT_MAX;
          nouveau->couleur = 'b';
          pl.push_back(nouveau); //On met le noeud à la suite dans le tableau
      }
      pl.at(indiceDepart)->pere = 0;
      pl.at(indiceDepart)->couleur = 'g';
      vector<int> file;
      file.push_back(indiceDepart);
      int u;
      int est;
      int ouest;
      int sud;
      int nord;
      auto sommetFile;
      while(file.empty())
      {
        sommetFile = file.begin();
        u = file[sommetFile];
        if(g.existEst(g.colonne(u)) &&
           pl[g.indiceEst(g.ligne(u), g.colonne(u))]->couleur == 'b')
        {
          est = g.indiceEst(g.ligne(u), g.colonne(u));
          pl[est]->couleur = 'g';
          pl[est]->pere = u;
          file.push_back(est);
        }
        if(g.existOuest(g.colonne(u)) &&
           pl[g.indiceOuest(g.ligne(u), g.colonne(u))]->couleur == 'b')
        {
          ouest = g.indiceOuest(g.ligne(u),(g.colonne(u));
          pl[ouest]->couleur = 'g';
          pl[ouest]->pere = u;
          file.push_back(ouest);
        }
        if(g.existNord(g.ligne(u)) &&
           pl[g.indiceNord(g.ligne(u),(g.colonne(u))]->couleur == 'b')
        {
          nord = g.indiceOuest(g.ligne(u),(g.colonne(u));
          pl[nord]->couleur = 'g';
          pl[nord]->pere = u;
          file.push_back(nord);
        }
        if(g.existSud(g.ligne(u)) &&
           pl[g.indiceSud(g.ligne(u),(g.colonne(u))]->couleur == 'b')
        {
          sud = g.indiceSud(g.ligne(u),(g.colonne(u));
          pl[sud]->couleur = 'g';
          pl[sud]->pere = u;
          file.push_back(sud);
          pl[sud]->distance = g.distanceVoisin(sud, u) + pl[sud]->distance;
        }
        file.erase(file.begin());
        pl[sommetFile]->couleur = 'n';
      }
}

std::vector<int> ParcoursLargeur::vecVoisins(const int indice, grid graphe)
{
    std::vector<int> vec;
    int i = graphe.ligne(indice);
    int j = graphe.colonne(indice);

    int x = graphe.indiceOuest(i, j);
    if (x != -1)
        vec.push_back(x);

    x = graphe.indiceNord(i, j);
    if (x != -1)
        vec.push_back(x);

    x = graphe.indiceEst(i, j);
    if (x != -1)
        vec.push_back(x);

    x = graphe.indiceSud(i, j);
    if (x != -1)
        vec.push_back(x);

    // for (unsigned int i = 0; i < vec.size(); i++)
    //     std::cout << vec.at(i) << std::endl;
    return vec;
}
