Project4: Project4Driver.o AVLTree.o Node.o
	g++ -g -ggdb Project4Driver.o AVLTree.o Node.o -o Project4

Project4Driver.o: Project4Driver.cpp
	g++ -g -ggdb -c Project4Driver.cpp

AVLTree.o: AVLTree.cpp
	g++ -g -ggdb -c AVLTree.cpp

Node.o: Node.cpp
	g++ -g -ggdb -c Node.cpp

clean:
	del /Q /F Project4.exe *.o