//Librerias y Dependencias
#include <SFML/Graphics.hpp>
#include <iostream>
//Headers
#include "Headers/renderer.h"
#include "Headers/alfombraSierpinski.h"
#include "Headers/trianguloSierpinski.h"
#include "Headers/copoKoch.h"
#include "Headers/pentagonoSierpinski.h"
#include "Headers/cuadradoSierpinski.h"
#include "Headers/hexagonoSierpinski.h"
#include "Headers/heptagonoSierpinski.h"
#include "Headers/octagonoSierpinski.h"
#include "Headers/decagonoSierpinski.h"


#define WIDTH 720
#define HEIGHT 720

int main(){
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "JuanVentana");
    //sf::Vector2f previousMousePosition;// for calculating the distance between the mouse button click location and release location, for mandelbrot movement
    int frac;
    int it; //Var de fractal a elegir y Varaible de num de it a realizar
    printf("----- Elegir Fractal a mostrar -----\n\n");
    printf("\tAlfombra Sierpinski\t\t -> 0\n \tCopo de Nieve Koch\t\t -> 1\n \tCopo de Nieve Inv\t\t -> 2\n \tTriangulo de Sierpinski\t -> 3\n \tCuadrado de Sierpinski\t -> 4\n \tPentagono Sierpinski\t -> 5\n \tHexagono de Sierpinski\t -> 6\n \tHeptagono de Sierpinski\t -> 7\n \tOctagono de Sierpinski\t -> 8\n \tNonagono de Sierpinski\t -> 9\n \tDecagono de Sierpinski\t -> 10\n");
    std::cin >> frac;
    
    printf("Favor de introducir numero de iteraciones \n");
    std::cin >> it;
    while (window.isOpen()){
        window.clear();//Limpia ventana antes de empezar

        sf::Event event;
        
        //Aqui van inputs
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)//Para que la ventana se pueda cerrar en caso de que el usuario haga click en la barra
                window.close();
            if (event.type == sf::Event::KeyPressed){
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                {
                    window.close();
                }
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                {
                    it++;
                    std::cout << it << std::endl;
                }
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                {
                    it--;
                    std::cout << it << std::endl;
                }
            }
        }
        window.clear();//Default color Black
        //TrianguloSierpinski st(window, it,300,0, 300,300);
        //AlfombraSierpinski as(window,it,300, 300);
        
        switch (frac) {
            case 0:{
                window.setTitle("Alfombra Sierpinski");
                AlfombraSierpinski as(window,it,WIDTH, HEIGHT,false);
                break;
            }
            case 1:{
                window.setTitle("Copo de Nieve Koch");
                CopoKoch ck = CopoKoch();
                ck.setBoundingBox(0, 0, WIDTH, HEIGHT);
                ck.setNumberOfIterations(it);
                ck.setColor(sf::Color::Red);
                ck.setInverted(false);
                ck.Render(window);
                break;
                
            }
            case 2:{
                window.setTitle("Copo de Nieve Inv");
                CopoKoch ck = CopoKoch();
                ck.setBoundingBox(0, 0, WIDTH, HEIGHT);
                ck.setNumberOfIterations(it);
                ck.setColor(sf::Color::Red);
                ck.setInverted(true);
                ck.Render(window);
                break;
            }
            case 3:{
                window.setTitle("Triangulo Sierpinski");
                TrianguloSierpinski st(window, it,0,0, WIDTH,HEIGHT);
                break;
            }
            case 4:{
                window.setTitle("Cuadrado Sierpinski");
                CuadradoSierpinski s4 = CuadradoSierpinski();
                s4.setBoundingBox(0, 0, WIDTH, HEIGHT);
                s4.setNumberOfIterations(it);
                s4.setColor(sf::Color::Red);
                s4.Render(window);
                break;
            }
            case 5:{
                window.setTitle("Pentagono Sierpinski");
                PentagonoSierpinski s5 = PentagonoSierpinski();
                s5.setBoundingBox(0, 0, WIDTH, HEIGHT);
                s5.setNumberOfIterations(it);
                s5.setColor(sf::Color::Red);
                s5.Render(window);
                break;
            }
            case 6:{
                window.setTitle("Hexagono Sierpinski");
                HexagonoSierpinski s6 = HexagonoSierpinski();
                s6.setBoundingBox(0, 0, WIDTH, HEIGHT);
                s6.setNumberOfIterations(it);
                s6.setColor(sf::Color::Red);
                s6.Render(window);
                break;
            }
            case 7:{
                window.setTitle("Heptagono Sierpinski");
                HeptagonoSierpinski s7 = HeptagonoSierpinski();
                s7.setBoundingBox(0, 0, WIDTH, HEIGHT);
                s7.setNumberOfIterations(it);
                s7.setColor(sf::Color::Red);
                s7.Render(window);
                break;
            }
            case 8:{
                window.setTitle("Octagono Sierpinski");
                OctagonoSierpinski s8 = OctagonoSierpinski();
                s8.setBoundingBox(0, 0, WIDTH, HEIGHT);
                s8.setNumberOfIterations(it);
                s8.setColor(sf::Color::Red);
                s8.Render(window);
                break;
            }
            case 9:{
                
                break;
            }
            case 10:{
                window.setTitle("Decagono Sierpinski");
                DecagonoSierpinski s10 = DecagonoSierpinski();
                s10.setBoundingBox(0, 0, WIDTH, HEIGHT);
                s10.setNumberOfIterations(it);
                s10.setColor(sf::Color::Red);
                s10.Render(window);
                break;
            }
            default:
                printf("Seleccione un fractal aceptado");
                break;
        }//END SWITCH
        
        window.display();
    }//END WHILE
    return 0;
}




