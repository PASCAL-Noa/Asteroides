#ifndef COORDONNEES_H
#define COORDONNEES_H

#include "Vecteur.h"

class Coordonnees
{
    public:
        static void initialiserEspace(int longueur, int hauteur); // méthode static car l’espace sera le même pour tous les objets Coordonnees
        static inline int getLongueurEspace() {return longueurEspace;};
        static inline int getHauteurEspace() {return hauteurEspace;};
        Coordonnees();
        Coordonnees(float px, float py);

        // inline pour plus de performance, revient en terme de performance à un accès direct à l’attribut
        inline float getX() const {return x;};
        inline float getY() const {return y;};

        void operator+=(Vecteur const& vecteur);
        float calculerDistance(Coordonnees const& autre) const;

    private:
        void recalculer(); // recalcule les coordonnées pour qu’elles soient dans les limites ; inutile d’y accéder de l’extérieur, donc privée
        float x{longueurEspace/2.f};
        float y{hauteurEspace/2.f};

        // longueur et hauteur de l’espace sont static, partagés par tous les objets Coordonnees
        static int longueurEspace;
        static int hauteurEspace;
};

#endif // COORDONNEES_H
