#include "AliveState.hpp"
#include "DeadState.hpp"

// Implémentation de AliveState
CellState* AliveState::nextState(int aliveNeighbors) const { // On appelle la méthode nextState depuis aliveState
    if (aliveNeighbors == 2 || aliveNeighbors == 3) { // On vérifie si le nombre de cellule voisine vivante est de 2 ou 3
        return new AliveState(); // On retourne la cellule comme vivante
    } else {
        return new DeadState(); // On retourne la cellule comme morte
    }
}

// Implémentation de DeadState
CellState* DeadState::nextState(int aliveNeighbors) const { // On appelle encore la méthode nextState depuis deadState
    if (aliveNeighbors == 3) { // On vérifie si le nombre de cellules voisines vivantes est de 3
        return new AliveState(); // On retourne la cellule comme vivante
    } else {
        return new DeadState(); // On retourne la cellule comme morte
    }
}
