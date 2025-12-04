#ifndef SFMLRENDERER_HPP
#define SFMLRENDERER_HPP

#include <SFML/Graphics.hpp>
#include "IRenderer.hpp"

class SFMLRenderer : public IRenderer {
private:
    sf::RenderWindow window;
    int cellSize;

public:
    SFMLRenderer(int width, int height, int cellSize = 10);
    void display(const Grid& grid) override;
};

#endif
