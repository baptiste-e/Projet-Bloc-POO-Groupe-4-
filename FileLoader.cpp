#include "FileLoader.hpp" // on inclut le header
#include <fstream>
#include <iostream>
#include <stdexcept>

#include "AliveState.hpp" // on inclut AliveState
#include "DeadState.hpp" // on inclut DeadState pour définir les cases vivantes et mortes dans le fichier source
#include "ObstacleState.hpp" // on inclut ObstacleState pour définir les cases obstacles dans le fichier source

Grid FileLoader::load(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        throw std::runtime_error("Impossible d'ouvrir le fichier : " + path); // on ouvre le fichier et sort une erreur si on peut pas le lire
    }

    int rows, cols;
    if (!(file >> rows >> cols)) {
        throw std::runtime_error("Erreur de lecture des dimensions."); // On détecte une erreur de dimension dans la source
    }

    Grid grid(rows, cols);

    for (int i = 0; i < rows; ++i) { 
        for (int j = 0; j < cols; ++j) { // on définit le dimensionnement de la grille
            int value;
            file >> value;

            if (value == 1) {
                grid.getCell(i, j).setState(new AliveState());
            }
           
            else if (value == 2) {  // Condition pour les obstacles
                grid.getCell(i, j).setState(new ObstacleState()); 
            }
            else {
                grid.getCell(i, j).setState(new DeadState());
            }
        }
    }

    return grid;
}
