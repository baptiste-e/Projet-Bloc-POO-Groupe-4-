#ifndef OBSTACLESTATE_HPP
#define OBSTACLESTATE_HPP

#include "CellState.hpp"

class ObstacleState : public CellState {
public:
    // CORRECTION : Mettre 'true' ici pour qu'il apparaisse comme un '1' dans le fichier de sortie
    bool isAlive() const override { return true; }

    // CORRECTION : Il renvoie toujours lui-même (immortel)
    CellState* nextState(int /*aliveNeighbors*/) const override {
        return new ObstacleState(); 
    }
};

#endif