#ifndef GAME_HPP
#define GAME_HPP

#include "Grid.hpp"
#include "Rules.hpp"
#include "IRenderer.hpp"
#include <string>

class Game { // On crée la classe Game qui est le coeur du jeu
private:
    Grid grid; // Attribut privé de la grille
    const Rules& rules; // Attribut privé des règles du jeu
    IRenderer& renderer; // Attribut privé d'affichage
    int iteration; // Attribut privé des différentes itérations au cours du jeu
    int maxIterations; // Attribut privé du max d'itérations données pour le jeu
    
    int sleepTime; // Gestion de la vitesse

public:
    Game(const Rules& r, IRenderer& rend, int maxIter = 50);

    void loadFromFile(const std::string& path); // Méthode vide qui sert à charger un fichier externe avec une grille
    void step();
    bool isStable(const Grid& oldGrid) const; // Méthode qui sert à vérifier si la grille est stable, si les états des cellules sont stables
    void run();

    // Permet de changer la vitesse des itérations soit les temps entre chaque itération
    void setSleepTime(int microsecondes) {
        sleepTime = microsecondes;
    }

    // AJOUT : Nécessaire pour le test unitaire
    const Grid& getGrid() const { return grid; } // Getter de grille qui récupère l'état de la grille après chaque itération
};

#endif
