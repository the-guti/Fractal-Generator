//Librerias y Dependencias
#include <SFML/Graphics.hpp>
#include <iostream>
//Headers
#include "Headers/renderer.h"
#include "Headers/alfombraSierpinski.h"
#include "Headers/trianguloSierpinski.h"
#include "Headers/copoKoch.h"

#define WIDTH 720
#define HEIGHT 720

int main(){
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "JuanVentana");
    //sf::Vector2f previousMousePosition;// for calculating the distance between the mouse button click location and release location, for mandelbrot movement
    int frac = 2,it = 4; //Var de fractal a elegir y Varaible de num de it a realizar
    printf("----- Favor de elegir Fractal a mostrar -----\n");
    printf("   Fractales  Triangulo S= 0; Copo de Nieve Koch = 1; Alfombra S = 2; Alfombra Invertida = 3 \n");

    //std::cin >> frac;
    
    printf("Favor de introducir numero de iteraciones \n");
    //std::cin >> it;
    window.clear();
    while (window.isOpen()){
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
        switch (frac) {
            case 0:{
                window.setTitle("Triangulo Sierpinski");
                SierpinskiTriangle st = SierpinskiTriangle();
                st.setBoundingBox(0, 0, WIDTH, HEIGHT);
                st.setNumberOfIterations(it);
                st.Render(window);
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

                SierpinskiCarpet sc = SierpinskiCarpet(it,WIDTH,HEIGHT);
                //sc.setBoundingBox(0, 0, WIDTH, HEIGHT);
                sc.Render(window);
                break;
            }
            case 3:{//Implement
                window.setTitle("Alfombra Invertida Sierpinski");
                
                SierpinskiCarpet sc = SierpinskiCarpet(it,WIDTH,HEIGHT);
                sc.Render(window);
                break;
            }
            default:
                
                break;
        }//END SWITCH
        window.display();
    }//END WHILE
    return 0;
}




