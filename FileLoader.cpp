#include "FileLoader.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>

#include "AliveState.hpp"
#include "DeadState.hpp"
#include "ObstacleState.hpp" // <--- 1. AJOUTER L'INCLUDE ICI

Grid FileLoader::load(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        throw std::runtime_error("Impossible d'ouvrir le fichier : " + path);
    }

    int rows, cols;
    if (!(file >> rows >> cols)) {
        throw std::runtime_error("Erreur de lecture des dimensions.");
    }

    Grid grid(rows, cols);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int value;
            file >> value;

            if (value == 1) {
                grid.getCell(i, j).setState(new AliveState());
            }
            // <--- 2. AJOUTER CETTE CONDITION POUR L'OBSTACLE
            else if (value == 2) { 
                grid.getCell(i, j).setState(new ObstacleState()); 
            }
            else {
                grid.getCell(i, j).setState(new DeadState());
            }
        }
    }

    return grid;
}