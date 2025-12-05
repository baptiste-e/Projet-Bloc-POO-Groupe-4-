#ifndef OBSTACLESTATE_HPP
#define OBSTACLESTATE_HPP

#include "CellState.hpp"

// Classe ObstacleState qui définit les cellules obstacles qui ne change jamais d'état durant tout le jeu
class ObstacleState : public CellState {
public:
    // Mettre 'true' ici pour qu'il apparaisse comme un '1' dans le fichier de sortie
    bool isAlive() const override { return true; }

    // Il renvoie toujours lui-même (immortel)
    CellState* nextState(int /*aliveNeighbors*/) const override {
        return new ObstacleState(); 
    }
};

#endif
