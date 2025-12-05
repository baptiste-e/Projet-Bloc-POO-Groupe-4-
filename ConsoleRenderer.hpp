#ifndef CONSOLERENDERER_HPP
#define CONSOLERENDERER_HPP

#include "IRenderer.hpp" //Hérédité entre ConsoleRenderer et IRenderer (qui est virtuelle)
#include <string>

class ConsoleRenderer : public IRenderer {
private:
    std::string outputFolder; // Le nom du dossier de sortie
    int iterationCount;       // Le numéro de l'itération actuelle

public:
    // On change le constructeur pour qu'il prenne le nom du fichier d'entrée
    ConsoleRenderer(const std::string& inputFilename);
    
    void display(const Grid& grid) override;
};

#endif
