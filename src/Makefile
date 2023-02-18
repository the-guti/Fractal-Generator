exec.out: main.o trianguloSierpinski.o alfombraSierpinski.o renderer.o copoKoch.o
	g++ *.o -o exec.out -lsfml-graphics -lsfml-window -lsfml-system -std=c++11

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

copoKoch.o: copoKoch.cpp Headers/copoKoch.h
	g++ -std=c++11 -c copoKoch.cpp

alfombraSierpinski.o: alfombraSierpinski.cpp Headers/alfombraSierpinski.h
	g++ -std=c++11 -c alfombraSierpinski.cpp

trianguloSierpinski.o: trianguloSierpinski.cpp Headers/trianguloSierpinski.h
	g++ -std=c++11 -c trianguloSierpinski.cpp

renderer.o: renderer.cpp Headers/renderer.h
	g++ -std=c++11 -c renderer.cpp
