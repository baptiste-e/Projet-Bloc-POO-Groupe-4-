#ifndef ALIVESTATE_HPP
#define ALIVESTATE_HPP

#include "CellState.hpp"
//On inclut la Classe CellStates pour l'hérédité.

class AliveState : public CellState {
public:
    bool isAlive() const override { return true; }
// Comme nous avons déclaré une constante = 0, nous faisons une constante override pour la remplacer.
    // On déclare juste la fonction, sans le code (le ; remplace les {}).
    CellState* nextState(int aliveNeighbors) const override;
// On déclare que la cellule passe à un nouvel état.
};

#endif
