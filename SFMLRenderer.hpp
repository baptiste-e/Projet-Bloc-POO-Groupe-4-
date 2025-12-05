#ifndef SFMLRENDERER_HPP
#define SFMLRENDERER_HPP

#include <SFML/Graphics.hpp>
#include "IRenderer.hpp"

class SFMLRenderer : public IRenderer { // Classe SFMLRenderer qui va servir à avoir un rendu graphique du jeu de la vie
private:
    sf::RenderWindow window; // Attribut privé pour la page graphique du jeu de la vie
    int cellSize; // Attribut privé pour la taille des cellules en pixel

public:
    SFMLRenderer(int width, int height, int cellSize = 10);
    void display(const Grid& grid) override;
};

#endif
