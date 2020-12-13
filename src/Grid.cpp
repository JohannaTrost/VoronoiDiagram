/**
    Contient toutes les fonctions appartenant aux classes Grid et SitesLibrairies
    nécessaires pour créer un graphe de "grille" et construire ses bibliothèques
    @file Grid.cpp
    @author Emie Lafourcade, Johanna Trost
    @version 1.0 12/12/20
*/

#include "Grid.h"

Grid::Grid(const int L, const int C) //Constructeur avec paramètres
{
    for (int i = 0; i < L * C; i++) //On fait un tableau de taille L*C
    {
        Noeud *nouveau = new Noeud;
        nouveau->hauteur = 0; //On met la hauteur de tous les noeuds à 0
        g.push_back(nouveau); //On met le noeud à la suite dans le tableau
    }

    col = C;  //Le nombre de(g.colonnes de la grille est C
    line = L; //Le nombre de lignes de la grille est L
}

Grid::Grid(const Grid &copie) //Constructeur par copie
{

    col = copie.col;
    line = copie.line;
    for (unsigned int i = 0; i < copie.g.size(); i++)
    {
        Noeud *nouveau = new Noeud;
        nouveau->hauteur = copie.g.at(i)->hauteur;
        g.push_back(nouveau);
    }
}

Grid::Grid(const string fichier) //Constructeur avec fichier
{
    // ouvrir fichier
    ifstream input(fichier);

    if (!input)
    {
        cerr << "Ne pas pouvoir ouvrir le fichier : " << fichier << endl;
    }
    else
    {
        vector<int> vec((istream_iterator<int>(input)), istream_iterator<int>());
        col = vec.at(0);
        line = vec.at(1);
        for (vector<int>::size_type i = 2; i != vec.size(); i++)
        {
            Noeud *nouveau = new Noeud;
            nouveau->hauteur = vec[i];
            g.push_back(nouveau);
        }
    }
    //Close The File
    input.close();
}
Grid::~Grid() //destructeur
{
    for (Noeud *n : g)
        delete n; //On detruit chaque noeud
    g.clear();    //Puis on vide le vecteur
}

int Grid::getTaille() const
{
    return col * line;
}

int Grid::getLine() const
{
    return line;
}

int Grid::getCol() const
{
    return col;
}

Grid & Grid::operator = (const Grid & grid)
{
    Grid gridCopie (grid);
    return gridCopie;
}

void Grid::affichage()
{
    int n = 0;
    for (int i = 0; i < line; i++) //On parcours les lignes
    {
        for (int j = 0; j < col; j++) //On parcours les(g.colonnes
        {
            cout << g.at(n)->hauteur << "  ";
            n++;
        }

        cout << endl;
    }
}

void Grid::modifhauteur(const int i, const int j, const int h)
{
    if (i < line && j < col && i >= 0 && j >= 0) //On verifie que le noeud (i,j) existe
        g.at(indice(i, j))->hauteur = h;         //on lui met la hauteur h
    else
        cout << "ce noeud n'existe pas" << endl;
}

int Grid::indice(const int i, const int j)
{
    if (i < line && j < col && i >= 0 && j >= 0) //On verifie que le noeud (i,j) existe
        return i * col + j;                      //On retourne son indice dans la tableau
    else
    {
        cout << "ce noeud n'existe pas" << endl;
        return -1; //On retourne -1 si le noeud n'existe pas
    }
}

int Grid::colonne(const int indice)
{
    if ((unsigned int)indice < g.size() && indice >= 0) //On verifie que l'indice du noeud est dans le tableau
        return indice % col;                            //On retourne la(g.colonne de la grille dans laquelle le noeud est
    else
    {
        cout << "ce noeud n'existe pas" << endl;
        return -1; //On retourne -1 si le noeud n'existe pas
    }
}

int Grid::ligne(const int indice)
{
    if ((unsigned int)indice < g.size() && indice >= 0) //On verifie que l'indice du noeud est dans le tableau
        return indice / col;                            //On retourne la ligne de la grille dans laquelle le noeud est
    else
    {
        cout << "ce noeud n'existe pas" << endl;
        return -1; //On retourne -1 si le noeud n'existe pas
    }
}

int Grid::hauteur(const int indice)
{
    if ((unsigned int)indice < g.size() && indice >= 0) //On verifie que l'indice du noeud est dans le tableau
        return g.at(indice)->hauteur;                   //On retourne sa hauteur
    else
    {
        cout << "ce noeud n'existe pas" << endl;
        return -1; //On retourne -1 si le noeud n'existe pas
    }
}

bool Grid::existNord(const int i)
{
    if (i < line && i >= 0) //On verifie que la ligne du noeud est dans la grille
        return i - 1 >= 0;  //On retourne si la ligne d'au dessus existe
    else
    {
        // cout << "ce noeud n'existe pas" << endl;
        return false; //On retourne faux si le noeud n'existe pas
    }
}

bool Grid::existSud(const int i)
{
    if (i < line && i >= 0)  //On verifie que la ligne du noeud est dans la grille
        return i + 1 < line; //On retourne si la ligne d'au dessous existe

    else
    {
        // cout << "ce noeud n'existe pas" << endl;
        return false; //On retourne faux si le noeud n'existe pas
    }
}

bool Grid::existEst(const int j)
{
    if (j < col && j >= 0)  //On verifie que la(g.colonne du noeud est dans la grille
        return j + 1 < col; //On retourne si la(g.colonne à sa droite existe
    else
    {
        // cout << "ce noeud n'existe pas" << endl;
        return false; //On retourne faux si le noeud n'existe pas
    }
}

bool Grid::existOuest(const int j)
{
    if (j < col && j >= 0) //On verifie que la(g.colonne du noeud est dans la grille
        return j - 1 >= 0; //On retourne si la(g.colonne à sa gauche existe
    else
    {
        // cout << "ce noeud n'existe pas" << endl;
        return false; //On retourne faux si le noeud n'existe pas
    }
}

int Grid::indiceNord(const int i, const int j)
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
        cout << "ce noeud n'existe pas" << endl;
        return -1; //On retourne -1 si le noeud n'existe pas
    }
}

int Grid::indiceSud(const int i, const int j)
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
        cout << "ce noeud n'existe pas" << endl;
        return -1; //On retourne -1 si le noeud n'existe pas
    }
}

int Grid::indiceEst(const int i, const int j)
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
        cout << "ce noeud n'existe pas" << endl;
        return -1; //On retourne -1 si le noeud n'existe pas
    }
}

int Grid::indiceOuest(const int i, const int j)
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
        cout << "ce noeud n'existe pas" << endl;
        return -1; //On retourne -1 si le noeud n'existe pas
    }
}

float Grid::distanceVoisin(const int indiceA, const int indiceB)
{
    int diffAB = hauteur(indiceA) - hauteur(indiceB);
    return sqrt(1 + diffAB * diffAB); // distance euclidienne
}

SitesLibrairies::~SitesLibrairies() //destructeur
{
    for (NoeudLibrairies *n : gridLibrairies)
        delete n; //On detruit chaque noeud
    gridLibrairies.clear();   //Puis on vide le vecteur
}

vector<int> SitesLibrairies::vecVoisins(const int indice, Grid graphe)
{
    vector<int> vec;
    int i = graphe.ligne(indice);
    int j = graphe.colonne(indice);

    int x = graphe.indiceOuest(i, j);
    if (x != -1 && x != -2)
        vec.push_back(x);

    x = graphe.indiceNord(i, j);
    if (x != -1 && x != -2)
        vec.push_back(x);

    x = graphe.indiceEst(i, j);
    if (x != -1 && x != -2)
        vec.push_back(x);

    x = graphe.indiceSud(i, j);
    if (x != -1 && x != -2)
        vec.push_back(x);

    return vec;
}

SitesLibrairies::SitesLibrairies(Grid &g, const string fichier/*=""*/, vector<int> indiceDepart/*=vector<int>()*/)
{
    // remgridLibrairiesi indiceDepart avec valeurs du fichier si un fichier est donné
    if (fichier != "")
    {
        // ouvrir fichier
        ifstream input(fichier);

        if (!input)
        {
            cerr << "Ne pas pouvoir ouvrir le fichier : " << fichier << endl;
        }
        else
        {
            vector<int> vec((istream_iterator<int>(input)), istream_iterator<int>());
            for (vector<int>::size_type i = 0; i != vec.size(); i++)
            {
                indiceDepart.push_back(vec[i]);
            }
        }
        //Close The File
        input.close();
    }

    // init de table gridLibrairies qui memorise les infos necessaires au parcours
    for (int i = 0; i < g.getTaille(); i++)
    {
        NoeudLibrairies *nouveau = new NoeudLibrairies;
        nouveau->distance = INT32_MAX; //On met la hauteur de tous les noeuds à MAX
        nouveau->pere = INT32_MAX;
        nouveau->coloration = 41;
        gridLibrairies.push_back(nouveau); //On met le noeud à la suite dans le tableau
    }

    // parcours de l'ensemble de points de départ (sites)
    for (unsigned int j = 0; j < indiceDepart.size(); j++)
    {
        // Dijkstra

        // tous sommets sont blanc au début
        for (unsigned int i = 0; i < gridLibrairies.size(); i++)
        {
            gridLibrairies.at(i)->couleur = 'b';
        }

        // init de point de départ
        gridLibrairies.at(indiceDepart.at(j))->pere = -1;
        gridLibrairies.at(indiceDepart.at(j))->couleur = 'n';
        gridLibrairies.at(indiceDepart.at(j))->distance = 0;
        gridLibrairies.at(indiceDepart.at(j))->coloration += j;

        vector<int> file; // file d'attente
        file.push_back(indiceDepart.at(j));
        int u; // indice du sommet traité actuellement
        vector<int> voisins;
        while (!file.empty())
        {
            u = defileMinimum(file, gridLibrairies);

            voisins = vecVoisins(u, g);

            for (unsigned int i = 0; i < voisins.size(); i++) // parcourir tous voisins
            {
                gridLibrairies.at(u)->fils.push_back(voisins.at(i));
                if (gridLibrairies.at(voisins.at(i))->couleur == 'b')
                {
                    gridLibrairies.at(voisins.at(i))->couleur = 'g'; // gris indique qu'on a déjè "consideré" ce sommet

                    // verifier si le voisin appartient au site
                    if (gridLibrairies.at(voisins.at(i))->distance > g.distanceVoisin(voisins.at(i), u) + gridLibrairies[u]->distance)
                    {
                        gridLibrairies.at(voisins.at(i))->pere = u;
                        gridLibrairies.at(voisins.at(i))->distance = g.distanceVoisin(voisins.at(i), u) + gridLibrairies[u]->distance;
                    }

                    file.push_back(voisins.at(i));
                }
            }
            gridLibrairies.at(u)->couleur = 'n'; // noir indique que ce sommet était traité
        }
    }

    coloration(g, indiceDepart); // indique quel sommet correspond à quelle librairie
}

void SitesLibrairies::coloration(Grid &g, const vector<int> indiceDepart)
{
    vector<int> indicesSuivants;
    for (unsigned int m = 0; m < gridLibrairies.size(); m++)
        for (unsigned int n = 0; n < indiceDepart.size(); n++)
            if (gridLibrairies.at(m)->pere == indiceDepart.at(n))
            {
                gridLibrairies.at(m)->coloration = gridLibrairies.at(indiceDepart.at(n))->coloration;

                if (gridLibrairies.at(m)->fils.size() != 0)
                    indicesSuivants.push_back(m);
            }

    if (indicesSuivants.size() != 0)
        coloration(g, indicesSuivants);
}

int SitesLibrairies::defileMinimum(vector<int> &f, vector<NoeudLibrairies *> gridLibrairies)
{
    float min = gridLibrairies.at(f.at(0))->distance;
    int indice = f.at(0);
    int indiceFile = 0;
    for (unsigned int i = 1; i < f.size(); i++)
    {
        if (min > gridLibrairies.at(f.at(i))->distance)
        {
            min = gridLibrairies.at(f.at(i))->distance;
            indice = f.at(i);
            indiceFile = i;
        }
    }
    f.erase(f.begin() + indiceFile);
    return indice;
}

void SitesLibrairies::affichage(const Grid g) const
{
    int n = 0;
    for (int i = 0; i < g.getLine(); i++) //On parcours les lignes
    {
        for (int j = 0; j < g.getCol(); j++) //On parcours les(g.colonnes
        {

            if (gridLibrairies.at(n)->distance != 0)
            {
                cout << "\033[1;" << gridLibrairies.at(n)->coloration << "m"
                          << (int)gridLibrairies.at(n)->distance << "  "
                          << "\033[0m";
            }
            else
                cout << gridLibrairies.at(n)->distance << " ";
            n++;
        }

        cout << endl;
    }
}
