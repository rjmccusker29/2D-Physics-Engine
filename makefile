all: compile link

compile:
	g++ -c main.cpp -Isrc/include
	g++ -c Engine.cpp -Isrc/include
	g++ -c Vobject.cpp -Isrc/include
	g++ -c Drawer.cpp -Isrc/include

link:
	g++ main.o Engine.o Vobject.o Drawer.o -o main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system
