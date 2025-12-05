#ifndef CONWAYRULES_HPP
#define CONWAYRULES_HPP

#include "Rules.hpp"
#include "AliveState.hpp"
#include "DeadState.hpp"

class ConwayRules : public Rules { // Ici on initialise la classe qui va servir à implémenter les règles de Conway en utilisant les attributs et méthodes publiques de la classe Rules
public:
    virtual CellState* computeNextState(const Cell& cell, int aliveNeighbors) const override; // Ici on appelle la méthode computeNextState qui va appeler le getter d'état des cellules
};

#endif
