# 1. Le compilateur à utiliser (g++ ou clang++)
CXX = g++

# 2. Les options de compilation
# -std=c++17 : Obligatoire pour utiliser std::filesystem et les fonctionnalités modernes
# -Wall -Wextra : Affiche tous les avertissements (très utile pour débugger)
# -g : Ajoute les informations de débogage (pour utiliser gdb ou valgrind)
# -fopenmp : ACTIVE LA PARALLÉLISATION (Point Bonus)
CXXFLAGS = -std=c++17 -Wall -Wextra -g -fopenmp

# 3. Les bibliothèques SFML à lier + OpenMP pour le linkeur
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -fopenmp

# 4. Liste automatique des fichiers sources (.cpp)
# Attention : cela prend TOUS les .cpp du dossier. Assurez-vous d'avoir supprimé main 2.cpp ou test.cpp s'ils ne sont pas utilisés.
SRCS = $(wildcard *.cpp)

# 5. Transformation des .cpp en .o (objets)
OBJS = $(SRCS:.cpp=.o)

# 6. Nom de l'exécutable final
EXEC = main

# --- RÈGLES ---

# La règle par défaut (quand on tape juste 'make')
all: $(EXEC)

# Création de l'exécutable en liant les objets
$(EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $(EXEC) $(LDFLAGS)

# Compilation de chaque fichier .cpp en .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Règle pour lancer le test unitaire rapidement
test: $(EXEC)
	./$(EXEC) test

# Nettoyage des fichiers générés
clean:
	rm -f $(OBJS) $(EXEC)
	rm -rf *_out  # Nettoie aussi les dossiers de résultats générés

# Indique que ces règles ne sont pas des fichiers réels
.PHONY: all clean test