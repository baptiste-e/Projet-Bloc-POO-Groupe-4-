#include "SFMLRenderer.hpp"

// Le constructeur reste le même
SFMLRenderer::SFMLRenderer(int width, int height, int cs)
: window(sf::VideoMode(width, height), "Game of Life"), cellSize(cs) {}

void SFMLRenderer::display(const Grid& grid) {
    // 1. GESTION DES ÉVÉNEMENTS (Indispensable pour que la fenêtre ne gèle pas)
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }

    // Si la fenêtre a été fermée, on ne dessine plus
    if (!window.isOpen()) return;


    // 2. DESSIN
    sf::RectangleShape cell(sf::Vector2f(cellSize - 1, cellSize - 1));
    window.clear(); // On efface tout en noir

    for (int i = 0; i < grid.getRows(); ++i) {
        for (int j = 0; j < grid.getCols(); ++j) {
            if (grid.getCell(i, j).isAlive()) {
                cell.setPosition(j * cellSize, i * cellSize); // Attention : x=colonne, y=ligne
                cell.setFillColor(sf::Color::White);
                window.draw(cell);
            }
        }
    }

    window.display(); // On affiche le résultat
}