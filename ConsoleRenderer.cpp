#include "ConsoleRenderer.hpp"
#include <fstream>
#include <iostream>
#include <filesystem> // Nécessaire pour créer des dossiers (C++17)

namespace fs = std::filesystem;

// Constructeur
ConsoleRenderer::ConsoleRenderer(const std::string& inputFilename) {
    iterationCount = 0;

    // On crée le nom du dossier : "monfichier.txt_out"
    outputFolder = inputFilename + "_out";

    // On crée le dossier s'il n'existe pas déjà
    if (!fs::exists(outputFolder)) {
        fs::create_directory(outputFolder);
    }
}

// Méthode display : au lieu d'afficher, on écrit dans un fichier
void ConsoleRenderer::display(const Grid& grid) {
    // 1. On construit le nom du fichier : "monfichier.txt_out/iter_0.txt"
    std::string filename = outputFolder + "/iter_" + std::to_string(iterationCount) + ".txt";

    // 2. On ouvre le fichier en écriture
    std::ofstream file(filename);

    if (file.is_open()) {
        // 3. On écrit les dimensions (Lignes Colonnes)
        file << grid.getRows() << " " << grid.getCols() << "\n";

        // 4. On parcourt la grille pour écrire 0 ou 1
        for (int i = 0; i < grid.getRows(); ++i) {
            for (int j = 0; j < grid.getCols(); ++j) {
                if (grid.getCell(i, j).isAlive()) {
                    file << "1 "; // Cellule vivante
                } else {
                    file << "0 "; // Cellule morte
                }
            }
            file << "\n"; // Retour à la ligne à la fin de chaque rangée
        }
        
        // Petit message dans la console pour dire que ça a marché
        std::cout << "Fichier genere : " << filename << std::endl;
    } else {
        std::cerr << "Erreur : Impossible d'ecrire le fichier " << filename << std::endl;
    }

    // 5. On augmente le compteur pour la prochaine fois
    iterationCount++;
}