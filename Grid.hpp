#ifndef GRID_HPP
#define GRID_HPP

#include <vector>
#include "Cell.hpp"
#include "Rules.hpp"

class Grid {
private:
    int rows;
    int cols;
    std::vector<std::vector<Cell>> cells;

public:
    Grid(int r, int c);
    
    int getRows() const;
    int getCols() const;
    
    // Note: It is usually safe to keep 1-line accessors in the header 
    // IF you mark them 'inline' or put them inside the class, 
    // but moving them to .cpp is the cleanest way to fix your specific error.
    
    Cell& getCell(int x, int y);
    const Cell& getCell(int x, int y) const;
    
    int countAliveNeighbors(int x, int y) const;
    void applyRules(const Rules& rules);
    bool isEqualTo(const Grid& other) const; // Assuming this exists based on Game.cpp usage
};

#endif