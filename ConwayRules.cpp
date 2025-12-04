#include "ConwayRules.hpp"
#include "Cell.hpp" // Important pour accéder à cell.getState()

CellState* ConwayRules::computeNextState(const Cell& cell, int aliveNeighbors) const {
    // MODIFICATION MAJEURE :
    // On ne décide plus ici. On demande à l'état actuel de calculer son propre futur.
    // Si l'état est "Alive", il appliquera les règles de vie.
    // Si l'état est "Obstacle", il appliquera la règle d'immortalité.
    return cell.getState()->nextState(aliveNeighbors);
}