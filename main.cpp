#include <iostream>
#include <string>
#include "Game.hpp"
#include "ConwayRules.hpp"
#include "ConsoleRenderer.hpp"
#include "SFMLRenderer.hpp"
#include "FileLoader.hpp"

// Fonction de test unitaire
void runUnitTest() {
    std::cout << "--- DEMARRAGE DU TEST UNITAIRE ---" << std::endl;

    ConwayRules rules;
    ConsoleRenderer renderer("test_ignore"); 
    Game game(rules, renderer, 1); 

    try {
        game.loadFromFile("test_start.txt");
        game.run();

        FileLoader loader;
        Grid expected = loader.load("test_end.txt");

        if (game.getGrid().isEqualTo(expected)) {
            std::cout << "SUCCES : Le resultat correspond a l'attendu !" << std::endl;
        } else {
            std::cout << "ECHEC : Le resultat est different." << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Erreur pendant le test : " << e.what() << std::endl;
        std::cerr << "Verifiez que 'test_start.txt' et 'test_end.txt' existent." << std::endl;
    }
    std::cout << "----------------------------------" << std::endl;
}

int main(int argc, char** argv) {
    // 1. Gestion du mode TEST
    if (argc >= 2 && std::string(argv[1]) == "test") {
        runUnitTest();
        return 0;
    }

    // 2. Vérification des arguments
    if (argc < 2) {
        std::cout << "Usage : ./main fichier.txt [console/sfml]\n";
        std::cout << "Test  : ./main test\n";
        return 1;
    }

    std::string mode = "console";
    if (argc >= 3)
        mode = argv[2];

    ConwayRules rules;

    try {
        if (mode == "console") {
            std::cout << "[INFO] Mode Console active." << std::endl;
            ConsoleRenderer renderer(argv[1]); 
            Game game(rules, renderer, 50);
            
            std::cout << "[INFO] Chargement du fichier " << argv[1] << "..." << std::endl;
            game.loadFromFile(argv[1]);
            
            std::cout << "[INFO] Lancement de la simulation..." << std::endl;
            game.run();
        }
        else {
            std::cout << "[INFO] Mode SFML (Graphique) active." << std::endl;
            
            // On augmente un peu la taille de la fenetre pour y voir clair
            SFMLRenderer renderer(1000, 1000, 20); // 1000x1000 pixels, cases de 20px
            
            // On met plus d'itérations pour avoir le temps de voir
            Game game(rules, renderer, 200); 
            
            std::cout << "[DEBUG] Chargement du fichier..." << std::endl;
            game.loadFromFile(argv[1]); // <-- Si ça plante ici, c'est le fichier ou Cell.hpp
            
            std::cout << "[DEBUG] Lancement de la boucle de jeu..." << std::endl;
            game.run();
        }
    } catch (const std::exception& e) {
        std::cerr << "[ERREUR CRITIQUE] : " << e.what() << std::endl;
        return 1;
    }

    std::cout << "Simulation terminee. Appuyez sur Entree pour quitter..." << std::endl;
    // Cette ligne empêche la fenêtre de se fermer tout de suite !
    std::cin.get(); 

    return 0;
}
