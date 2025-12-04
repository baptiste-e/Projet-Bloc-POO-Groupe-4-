#ifndef RULES_HPP
#define RULES_HPP

#include "Cell.hpp"
#include "CellState.hpp"

class Rules {
public:
    virtual ~Rules() {}

    // Méthode pure virtuelle : calcule l'état suivant d'une cellule
    virtual CellState* computeNextState(const Cell& cell, int aliveNeighbors) const = 0;
};

#endif
