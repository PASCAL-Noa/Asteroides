#include "Coordonnees.h"
#include <iostream>
#include <cmath>
#include <algorithm>

int Coordonnees::longueurEspace{0};
int Coordonnees::hauteurEspace{0};

// Constructeur factultatif mais ici on envoie un message d’erreur si une coordonnée est créée avant l’initialisation de l’espace
Coordonnees::Coordonnees() {
    if(longueurEspace == 0 || hauteurEspace == 0) {
        std::cerr << "Attention : une coordonnée a été créée avant l’initialisation de l’espace !" << std::endl;
    }
}

Coordonnees::Coordonnees(float px, float py) : x(px), y(py) {
    recalculer();
}

// L’opérateur += ajoute déjà le vecteur en paramètre puis ajoute ou retire la taille de l’espace sur les composantes x,y si besoin
void Coordonnees::operator+=(Vecteur const& vecteur) {
    x += vecteur.x;
    y += vecteur.y;
    recalculer();
}

void Coordonnees::initialiserEspace(int longueur, int hauteur) {
    // on envoie un message d’erreur si l’espace était déjà initialisé
    if(longueurEspace != 0 || hauteurEspace != 0) {
        std::cerr << "Attention : l’espace était déjà initialisé !" << std::endl;
    }
    longueurEspace = longueur;
    hauteurEspace = hauteur;
}

void Coordonnees::recalculer() {
    while(x>longueurEspace) {
        x -= longueurEspace;
    }
    while(x < 0) {
        x += longueurEspace;
    }
    while(y > hauteurEspace) {
        y -= hauteurEspace;
    }
    while(y < 0) {
        y += hauteurEspace;
    }
}

float Coordonnees::calculerDistance(Coordonnees const& autre) const {
    auto delta = Vecteur{static_cast<float>(std::min({abs(x-autre.x), abs(x-autre.x-longueurEspace), abs(x-autre.x+longueurEspace)})), static_cast<float>(std::min({abs(y-autre.y), abs(y-autre.y-hauteurEspace), abs(y-autre.y+hauteurEspace)}))};
    return sqrt(delta.x*delta.x+delta.y*delta.y);
}
