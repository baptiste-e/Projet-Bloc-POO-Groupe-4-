#ifndef CONWAYRULES_HPP
#define CONWAYRULES_HPP

#include "Rules.hpp"
#include "AliveState.hpp"
#include "DeadState.hpp"

class ConwayRules : public Rules {
public:
    virtual CellState* computeNextState(const Cell& cell, int aliveNeighbors) const override;
};

#endif
