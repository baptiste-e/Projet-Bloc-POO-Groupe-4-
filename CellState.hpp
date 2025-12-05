#ifndef CELLSTATE_HPP
#define CELLSTATE_HPP

// Ici on initialise la classe qui va servir à définir l'état des cellules (mort ou vivant)
class CellState {
public:
    virtual ~CellState() = default; //Destructeur virtuel
    virtual bool isAlive() const = 0; // Ici on initialise la méthode isAlive qui vérifie si une cellule est vivante ou morte
    virtual CellState* nextState(int aliveNeighbors) const = 0; // Ici on initialise la méthode nextState qui va contenir le prochain état des cellules
};

#endif
