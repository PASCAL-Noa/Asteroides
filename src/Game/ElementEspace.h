#ifndef ELEMENTESPACE_H
#define ELEMENTESPACE_H

#include <SFML/Graphics.hpp>
#include "Vecteur.h"
#include "Coordonnees.h"

enum class TypeElement {VAISSEAU, ASTEROIDE, MISSILE, AUTRE};

class ElementEspace
{
    public:
    virtual ~ElementEspace() = default;
    explicit ElementEspace(std::string_view const&);
    ElementEspace(ElementEspace const& autre) = delete;
    void operator=(ElementEspace const& autre) = delete;
    void actualiser(float temps);
    virtual void afficher(sf::RenderWindow& fenetre) const;

    inline bool estDetruit() const {return detruit;};

    float getRayon() const;
    void testerCollision(ElementEspace& autre);
    virtual void reagirCollision(TypeElement typeAutre) = 0;

    protected:
    virtual void mettreAJour(float temps);
    TypeElement type{TypeElement::AUTRE};
    bool detruit{false};
    sf::Sprite sprite{};
    Coordonnees position{};
    Vecteur vitesse{0.f, 0.f};
    float vitesseAngulaire{};
};

#endif // ELEMENTESPACE_H
