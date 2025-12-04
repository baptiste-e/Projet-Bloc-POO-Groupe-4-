#include "Grid.hpp"
#include "Cell.hpp"

// Constructeur
Grid::Grid(int r, int c) : rows(r), cols(c) {
    cells.resize(rows, std::vector<Cell>(cols));
}

int Grid::getRows() const { return rows; }
int Grid::getCols() const { return cols; }
Cell& Grid::getCell(int x, int y) { return cells[x][y]; }
const Cell& Grid::getCell(int x, int y) const { return cells[x][y]; }

// Compte les voisins vivants (Logique complète + Tore)
int Grid::countAliveNeighbors(int x, int y) const {
    int aliveCount = 0;
    
    // CORRECTION : J'ai supprimé la deuxième déclaration "int aliveCount = 0;" qui était en trop.

    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue;

            // Formule mathématique du tore : (x + i + rows) % rows
            // Cela relie le bord gauche au bord droit, et haut avec bas
            int nx = (x + i + rows) % rows; 
            int ny = (y + j + cols) % cols;

            // On accède directement à la cellule voisine (qui est forcément valide grâce au modulo)
            if (cells[nx][ny].isAlive()) {
                aliveCount++;
            }
        }
    }
    return aliveCount;
}

// Applique les règles pour passer à l'état suivant (Parallélisé)
void Grid::applyRules(const Rules& rules) {
    // 1. On calcule les futurs états de toutes les cellules
    std::vector<std::vector<CellState*>> nextStates(rows, std::vector<CellState*>(cols));

    // MODIFICATION BONUS : Parallélisation avec OpenMP
    // Cette ligne divise le travail de la boucle sur tous les cœurs de votre processeur
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // Note : countAliveNeighbors est "thread-safe" car elle est 'const' (lecture seule)
            int neighbors = countAliveNeighbors(i, j);
            nextStates[i][j] = rules.computeNextState(cells[i][j], neighbors);
        }
    }

    // 2. On applique les nouveaux états
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // Mise à jour de l'état
            cells[i][j].setState(nextStates[i][j]);
        }
    }
}

// Compare deux grilles (Nécessaire pour isStable et les Tests Unitaires)
bool Grid::isEqualTo(const Grid& other) const {
    if (rows != other.rows || cols != other.cols) return false;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (cells[i][j].isAlive() != other.cells[i][j].isAlive()) {
                return false;
            }
        }
    }
    return true;
}