//Librerias y Dependencias
#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>

//Headers
#include "Headers/renderer.h"
#include "Headers/alfombraSierpinski.h"
#include "Headers/trianguloSierpinski.h"
#include "Headers/copoKoch.h"

#define WIDTH 720
#define HEIGHT 720

//void renderingThread(sf::RenderWindow* window);

int main(){
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Juan Ventana");
    //window.setActive(false);
    /*
    sf::Thread thread(&renderingThread, &window);
    thread.launch();*/
    
    //Variables a inicializar
    int frac = 0,it = 4; //Fractal a elegir y num de it a realizar
    std::chrono::high_resolution_clock::time_point tiempoInicio,tiempoFinal;
    std::chrono::duration<double> time_span;
    bool recalculate = true;
    
    printf("----- Favor de elegir Fractal a mostrar -----\n");
    printf("   Fractales  Triangulo S= 0; Copo de Nieve Koch = 1; Alfombra S = 2; Alfombra Invertida = 3 \n");
    //std::cin >> frac;
    
    printf("Favor de introducir numero de iteraciones \n");
    //std::cin >> it;
    while (window.isOpen()){
        window.clear();//Limpia ventana antes de empezar
        
        sf::Event event;
        
        //Aqui van inputs
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)//Para que la ventana se pueda cerrar en caso de que el usuario haga click en la barra
                window.close();
            if (event.type == sf::Event::KeyPressed){
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                    window.close();
                }
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                    recalculate = true;
                    it++;
                    std::cout << it << std::endl;
                }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                    recalculate = true;
                    it--;
                    std::cout << it << std::endl;
                }
            }
        }
        if(recalculate){
            switch (frac) {
                case 0:{
                    window.setTitle("Triangulo Sierpinski");
                    tiempoInicio =  std::chrono::high_resolution_clock::now();
                    SierpinskiTriangle st(window, it,0,0, WIDTH,HEIGHT);
                    tiempoFinal =  std::chrono::high_resolution_clock::now();
                    time_span = std::chrono::duration_cast<std::chrono::duration<double> >(tiempoFinal - tiempoInicio);
                    
                    std::cout << "Tiempo de ejecucion: " << time_span.count()  << "seconds";
                    break;
                }
                case 1:{
                    window.setTitle("Copo de Nieve Koch");
                    
                    KochSnowflake ks = KochSnowflake();
                    ks.setBoundingBox(0, 0, WIDTH, HEIGHT);
                    ks.setNumberOfIterations(it);
                    ks.setColor(sf::Color::Red);
                    ks.setInverted(false);
                    ks.Render(window);
                    break;
                }
                case 2:{
                    window.setTitle("Alfombra Sierpinski");
                    SierpinskiCarpet as(window,it,WIDTH, HEIGHT);
                    break;
                }
                case 3:{//Implement "soon"
                    window.setTitle("Alfombra Invertida Sierpinski");
                    SierpinskiCarpet asI(window,it,WIDTH,HEIGHT);
                    break;
                }
                default:
                    printf("No se eligio un tamaño correcto");
                    break;
            }//END SWITCH
            recalculate = false;
            window.display();
        }//END IF
        
    }//END WHILE
    return 0;
}
/*
void renderingThread(sf::RenderWindow* window){
    // the rendering loop
    while (window->isOpen()) {
        // draw...
        window->clear();//Default color Black
        SierpinskiTriangle st(*window, 5,300,0, 300,300);
        
        // end the current frame
        window->display();
    }
}*/



