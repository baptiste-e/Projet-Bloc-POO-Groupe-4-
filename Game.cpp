#include "Game.hpp"
#include "Grid.hpp"
#include "Rules.hpp"
#include "IRenderer.hpp"
#include "FileLoader.hpp"
#include <string>
#include <unistd.h> // Pour usleep (pause)

// <--- MODIFICATION 1 : Nouveaux includes nécessaires
#include <SFML/Window/Keyboard.hpp> // Pour lire le clavier
#include <algorithm>                // Pour std::max
#include "AliveState.hpp"           // Pour créer des cellules vivantes (Glider)

Game::Game(const Rules& r, IRenderer& rend, int maxIter)
: grid(1,1), rules(r), renderer(rend), iteration(0), maxIterations(maxIter), sleepTime(100000) {}

void Game::loadFromFile(const std::string& path) {
    FileLoader loader;
    grid = loader.load(path);
}

bool Game::isStable(const Grid& oldGrid) const {
    return grid.isEqualTo(oldGrid);
}

void Game::step() {
    renderer.display(grid);
    grid.applyRules(rules);
    iteration++;
}

void Game::run() {
    while (iteration < maxIterations) {
        Grid oldGrid = grid; // Copie pour vérifier la stabilité
        
        step(); // Calcul de la génération suivante

        // <--- MODIFICATION 2 : Gestion des entrées Clavier (Vitesse + Motifs)

        // 1. GESTION DE LA VITESSE
        // Flèche HAUT = Plus vite (réduit la pause)
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            sleepTime = std::max(10000, sleepTime - 20000); // Minimum 0.01s
        }
        // Flèche BAS = Moins vite (augmente la pause)
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            sleepTime += 20000; // Ajoute 0.02s
        }

        // 2. AJOUT DE MOTIFS (Exemple : Glider avec la touche 'G')
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) {
            // On ajoute un Glider en haut à gauche (coordonnées 5,5 pour l'exemple)
            // Attention : Il faut s'assurer que la grille est assez grande !
            int startX = 5;
            int startY = 5;

            if (grid.getRows() > 10 && grid.getCols() > 10) {
                // Forme du Glider
                grid.getCell(startX, startY+1).setState(new AliveState());
                grid.getCell(startX+1, startY+2).setState(new AliveState());
                grid.getCell(startX+2, startY).setState(new AliveState());
                grid.getCell(startX+2, startY+1).setState(new AliveState());
                grid.getCell(startX+2, startY+2).setState(new AliveState());
            }
        }
        
        // Pause pour contrôler la vitesse
        usleep(sleepTime);

        // if (isStable(oldGrid))
        //    break;
    }
}