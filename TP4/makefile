# Déclaration des variables
CC = g++
CC_FLAGS = -Wall -std=c++0x
CC_EXFLAGS = # -DMAP
VAL_FLAGS = --leak-check=yes

#Noms de dossier
BINDIR = bin

# Noms de fichiers
EXEC = run
SOURCES = $(wildcard $(BINDIR)/*.cpp)
OBJECTS = $(SOURCES:$(BINDIR)/.cpp=.o)	

#Cible principale
$(EXEC) : $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC)
	
# Pour les fichiers objets
%.o: %.cpp
	$(CC) -c $(CC_FLAGS) $(CC_EXFLAGS) $< -o $@
	
#Pour effacer les fichiers exécutables
clean:
	rm -f $(EXEC) $(OBJECTS)
	
#Pour effacer les fichiers .dot
rmgraph:
	find . -name "*.dot" -type f -delete
	
#Pour valgrind
valgrind:
	valgrind $(VAL_FLAGS) ./$(EXEC)
