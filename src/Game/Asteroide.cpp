#include "Asteroide.h"

#include <iostream>
#include <random>
#include <chrono>
#include "Explosion.h"

Asteroide::Asteroide(Jeu& p_jeu, Espace& p_espace, Asteroide* parent) : ElementEspace{"../../res/Game/asteroide.png"}, jeu{p_jeu}, espace{p_espace}
{
    type = TypeElement::ASTEROIDE;

    // Présenté dans la session vidéo mais ne fonctionne que sous linux
    // auto generateur = std::random_device{};

    // Sous windows
    auto temps = std::chrono::high_resolution_clock::now().time_since_epoch();
    auto ns = std::chrono::duration_cast<std::chrono::nanoseconds>(temps).count();
    auto generateur = std::mt19937{static_cast<unsigned long>(ns)};

    auto distributionPosition = std::uniform_real_distribution<float>{-150, 150};
    auto distributionVitesse = std::uniform_real_distribution<float>{80,120};
    auto distributionAngle = std::uniform_real_distribution<float>{0,360};
    auto distributionVitesseAngulaire = std::uniform_real_distribution<float>{10,30};
    vitesse = Vecteur::creerDepuisAngle(distributionVitesse(generateur), distributionAngle(generateur));
    vitesseAngulaire = distributionVitesseAngulaire(generateur);
    if(parent) {
        sprite.setScale(parent->sprite.getScale().x/1.4, parent->sprite.getScale().y/1.4);
        position = parent->position;
    } else {
        position = {distributionPosition(generateur), distributionPosition(generateur)};
    }
}

void Asteroide::reagirCollision(TypeElement typeAutre) {
    if(typeAutre == TypeElement::MISSILE) {
        detruit = true;
        jeu.ajouterPoints(sprite.getScale().x * 100);
        if(sprite.getScale().x > 0.1) {
            espace.ajouter(std::make_unique<Asteroide>(jeu, espace, this));
            espace.ajouter(std::make_unique<Asteroide>(jeu, espace, this));
        }
        espace.ajouter(std::make_unique<Explosion>(position));
    }
}
