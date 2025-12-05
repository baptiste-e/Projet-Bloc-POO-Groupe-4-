#ifndef DEADSTATE_HPP
#define DEADSTATE_HPP

#include "CellState.hpp" //On inclut CellState pour l'hérédité 


class DeadState : public CellState { // Ici on déclare l'hérédité
public:
    bool isAlive() const override { return false; }

    // On déclare le nouvel état de la cellule, et on déclare des possibles cases voisines vivantes (aliveNeighbors)
    CellState* nextState(int aliveNeighbors) const override;
};

#endif
