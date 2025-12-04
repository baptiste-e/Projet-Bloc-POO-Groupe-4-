#ifndef DEADSTATE_HPP
#define DEADSTATE_HPP

#include "CellState.hpp"
// On RETIRE #include "AliveState.hpp" pour casser la boucle

class DeadState : public CellState {
public:
    bool isAlive() const override { return false; }

    // Juste la déclaration
    CellState* nextState(int aliveNeighbors) const override;
};

#endif