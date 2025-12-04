#ifndef GAME_HPP
#define GAME_HPP

#include "Grid.hpp"
#include "Rules.hpp"
#include "IRenderer.hpp"
#include <string>

class Game {
private:
    Grid grid;
    const Rules& rules;
    IRenderer& renderer;
    int iteration;
    int maxIterations;
    
    int sleepTime; // Gestion de la vitesse

public:
    Game(const Rules& r, IRenderer& rend, int maxIter = 50);

    void loadFromFile(const std::string& path);
    void step();
    bool isStable(const Grid& oldGrid) const;
    void run();

    // Permet de changer la vitesse
    void setSleepTime(int microsecondes) {
        sleepTime = microsecondes;
    }

    // AJOUT : Nécessaire pour le test unitaire
    const Grid& getGrid() const { return grid; }
};

#endif