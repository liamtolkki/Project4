Project4: Project4Driver.o AVLTree.o
	g++ -g -ggdb Project4Driver.o AVLTree.o -o Project4

Project4Driver.o: Project4Driver.cpp
	g++ -g -ggdb -c Project4Driver.cpp

AVLTree.o: AVLTree.cpp
	g++ -g -ggdb -c AVLTree.cpp

clean:
	del /Q /F Project4.exe *.o