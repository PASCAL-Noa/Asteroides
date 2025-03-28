#include "Vecteur.h"
#include <cmath>
#include <numbers>

void Vecteur::operator+=(Vecteur const& autre) {
    x += autre.x;
    y += autre.y;
}

void Vecteur::operator-=(Vecteur const& autre) {
    x -= autre.x;
    y -= autre.y;
}

Vecteur Vecteur::operator*(float coefficient) const {
    return {x*coefficient, y*coefficient};
}

Vecteur Vecteur::creerDepuisAngle(float taille, float angleEnDegre) {
    float angleEnRadian = angleEnDegre * std::numbers::pi_v<float> / 180.0f;
    return {taille * cos(angleEnRadian), taille * sin(angleEnRadian)};
}