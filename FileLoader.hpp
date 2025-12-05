#ifndef FILELOADER_HPP
#define FILELOADER_HPP

#include <string>
#include "Grid.hpp" // on inclut Grid.hpp pour définir le dimensionnement de notre grille

class FileLoader {
public:
    Grid load(const std::string& path);
};

#endif
