
# Makefile de cola

# Variables
CC = g++
EXE = 
PRINCIPAL= 
BOR= $(PRINCIPAL).cpp DOM_Tree.o Node.o Element.o
# Programa Principal
all: Element.o Node.o DOM_Tree.o
	$(CC)  Element.o Node.o DOM_Tree.o $(PRINCIPAL).cpp -o $(EXE)

# Librerías
DOM_Tree.o: DOM_Tree.cpp DOM_Tree.h
	$(CXX) $(CXXFLASGS) -c -o $@ $<
	
Node.o: Node.cpp Node.h
	$(CXX) $(CXXFLASGS) -c -o $@ $<

Element.o: Element.cpp Element.h
	$(CXX) $(CXXFLASGS) -c -o $@ $<


# Borrar los Archivos Objeto y el Ejecutable
clean:
	rm -rf *.o $(BOR)
