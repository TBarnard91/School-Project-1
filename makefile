# This is the makefile for the Film Database Project
Project1.exe: Film.o FilmDatabase.o NotFoundException.o PrecondViolatedExcep.o Menu.o Project1.o 
	g++ -std=gnu++11 -o Project1.exe Film.o FilmDatabase.o NotFoundException.o PrecondViolatedExcep.o Menu.o Project1.o 
Film.o: Film.cpp Film.h 
	g++ -std=gnu++11 -ggdb -c Film.cpp
FilmDatabase.o: FilmDatabase.cpp FilmDatabase.h BinarySearchTree.h BinaryTreeInterface.h BinaryNodeTree.h BinaryNode.h NotFoundException.h PrecondViolatedExcep.h Film.h
	g++ -std=gnu++11 -ggdb -c FilmDatabase.cpp
Menu.o: Menu.cpp Menu.h
	g++ -std=gnu++11 -ggdb -c Menu.cpp
NotFoundException.o: NotFoundException.cpp NotFoundException.h 
	g++ -std=gnu++11 -ggdb -c NotFoundException.cpp
PrecondViolatedExcep.o: PrecondViolatedExcep.cpp PrecondViolatedExcep.h 
	g++ -std=gnu++11 -ggdb -c PrecondViolatedExcep.cpp
Project1.o: Project1.cpp FilmDatabase.h BinarySearchTree.h BinaryTreeInterface.h BinaryNodeTree.h BinaryNode.h NotFoundException.h PrecondViolatedExcep.h Film.h
	g++ -std=gnu++11 -ggdb -c Project1.cpp 