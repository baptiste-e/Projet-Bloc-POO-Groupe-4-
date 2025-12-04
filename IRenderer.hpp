#ifndef IRENDERER_HPP
#define IRENDERER_HPP

#include "Grid.hpp"

class IRenderer {
public:
    virtual ~IRenderer() {}
    virtual void display(const Grid& grid) = 0;
};

#endif

