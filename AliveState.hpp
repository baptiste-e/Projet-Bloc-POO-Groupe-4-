#ifndef ALIVESTATE_HPP
#define ALIVESTATE_HPP

#include "CellState.hpp"
// On inclut CellState.hpp pour l'hérédité.

class AliveState : public CellState { //Hérédité de la classe Cellstate vers AliveState
public:
    bool isAlive() const override { return true; }
// On a défini une constante = 0 dans CellState que l'on override pour la remplacer
    // On déclare juste la fonction, sans le code (le ; remplace les {})
    CellState* nextState(int aliveNeighbors) const override;
// Ici on int aliveNeighbors pour définir de futurs voisins potenciellement vivants, de plus on définit le nouvel état des cellules
};

#endif
