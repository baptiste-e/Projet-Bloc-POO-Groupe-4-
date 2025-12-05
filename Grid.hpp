#ifndef GRID_HPP
#define GRID_HPP

#include <vector>
#include "Cell.hpp"
#include "Rules.hpp"

class Grid {
private:
    int rows;    //définition des lignes
    int cols;    //définition des colonnes
    std::vector<std::vector<Cell>> cells;

public:
    Grid(int r, int c);
    
    int getRows() const; 
    int getCols() const; 
    
  
    
    Cell& getCell(int x, int y); 
    const Cell& getCell(int x, int y) const; 
    
    int countAliveNeighbors(int x, int y) const;
    void applyRules(const Rules& rules);
    bool isEqualTo(const Grid& other) const;
};

#endif
