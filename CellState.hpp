#ifndef CELLSTATE_HPP
#define CELLSTATE_HPP

class CellState {
public:
    virtual ~CellState() = default;
    virtual bool isAlive() const = 0;
    virtual CellState* nextState(int aliveNeighbors) const = 0;
};

#endif