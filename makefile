CXX = g++
CXXFLASGS = -ggdb -Wno-deprecated

OBJETOS = main.o DOM_Tree.o Node.o Element.o

main: $(OBJETOS)
	$(CXX) -o $@ $^
	
main.o:	main.cpp
	$(CXX) $(CXXFLASGS) -c -o $@ $^
	
DOM_Tree.o: DOM_Tree.cpp DOM_Tree.h
	$(CXX) $(CXXFLASGS) -c -o $@ $<
	
Node.o: Node.cpp Node.h
	$(CXX) $(CXXFLASGS) -c -o $@ $<

Element.o: Element.cpp Element.h
	$(CXX) $(CXXFLASGS) -c -o $@ $<
