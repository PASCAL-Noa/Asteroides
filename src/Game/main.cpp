#include <SFML/Graphics.hpp>
#include "Espace.h"
#include "Jeu.h"
#include <exception>

using namespace std;

constexpr int LONGUEUR_FENETRE{800};
constexpr int HAUTEUR_FENETRE{600};

int main()
{
    sf::RenderWindow fenetre{sf::VideoMode{LONGUEUR_FENETRE, HAUTEUR_FENETRE}, "Asteroids"};
    Coordonnees::initialiserEspace(LONGUEUR_FENETRE, HAUTEUR_FENETRE);
    auto espace = Espace{};
    auto jeu = Jeu{espace};

    while(fenetre.isOpen()) {
        try {
            auto evenement = sf::Event{};
            while(fenetre.pollEvent(evenement)) {
                if(evenement.type == sf::Event::Closed) {
                    fenetre.close();
                }
                if(evenement.type == sf::Event::KeyPressed && !jeu.estEnCours()) {
                    jeu.demarrer();
                }
            }

            espace.actualiser();
            espace.gererCollisions();

            fenetre.clear();
            espace.afficher(fenetre);
            jeu.afficher(fenetre);
            fenetre.display();

            espace.nettoyer();
        } catch(std::exception const& exception) {
            jeu.initialiserException(exception);
        }
    }
    return 0;
}
