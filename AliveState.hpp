#ifndef ALIVESTATE_HPP
#define ALIVESTATE_HPP

#include "CellState.hpp"
// On RETIRE #include "DeadState.hpp" pour casser la boucle

class AliveState : public CellState {
public:
    bool isAlive() const override { return true; }

    // On déclare juste la fonction, sans le code (le ; remplace les {})
    CellState* nextState(int aliveNeighbors) const override;
};

#endif