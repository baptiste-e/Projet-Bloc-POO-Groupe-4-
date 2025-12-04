#ifndef CELL_HPP
#define CELL_HPP

#include "DeadState.hpp"
#include "CellState.hpp"

class Cell {
private:
    CellState* state;

public:
    // CORRECTION : Ajout du constructeur par défaut nécessaire pour std::vector
    Cell() : state(new DeadState()) {}

    Cell(CellState* initialState) : state(initialState) {}

    bool isAlive() const {
        // Sécurité : on vérifie que state n'est pas null avant d'appeler la méthode
        if (!state) return false; 
        return state->isAlive();
    }

    void setState(CellState* newState) {
        // Optionnel : supprimer l'ancien état pour éviter les fuites de mémoire
        // if (state) delete state; 
        state = newState;
    }

    CellState* getState() const {
        return state;
    }
};

#endif