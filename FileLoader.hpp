#ifndef FILELOADER_HPP
#define FILELOADER_HPP

#include <string>
#include "Grid.hpp"

class FileLoader {
public:
    Grid load(const std::string& path);
};

#endif
