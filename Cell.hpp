#ifndef CELL_HPP
#define CELL_HPP

#include "DeadState.hpp"
#include "CellState.hpp"
// On inclut CellState et Deadstate pour l'hérédité de ces deux classes.
class Cell { // on définit la classe Cell
private:
    CellState* state;

public:
    // Ajout du constructeur par défaut 
    Cell() : state(new DeadState()) {}

    Cell(CellState* initialState) : state(initialState) {}
// On déclare un état par défaut
    bool isAlive() const {
        //On vérifie que state n'est pas null avant d'appeler la méthode
        if (!state) return false;  // On supprime l'ancien état pour éviter les fuites de mémoire
        return state->isAlive();
    }

    void setState(CellState* newState) {
       
                                       // On déclare le nouvel état de la cellule
        state = newState;
    }

    CellState* getState() const {
        return state; // On récupère l'état de la cellule 
    }
};

#endif
