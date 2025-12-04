#include "AliveState.hpp"
#include "DeadState.hpp"

// Implémentation de AliveState
CellState* AliveState::nextState(int aliveNeighbors) const {
    if (aliveNeighbors == 2 || aliveNeighbors == 3) {
        return new AliveState();
    } else {
        return new DeadState();
    }
}

// Implémentation de DeadState
CellState* DeadState::nextState(int aliveNeighbors) const {
    if (aliveNeighbors == 3) {
        return new AliveState();
    } else {
        return new DeadState();
    }
}