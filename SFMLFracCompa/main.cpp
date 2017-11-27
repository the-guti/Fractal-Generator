//Librerias y Dependencias
#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>   //Medicion de tiempo
#include <fstream>  //Crear y escribir en archivos
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
#include "Headers/nonagonoSierpinski.h"
#include "Headers/decagonoSierpinski.h"
//

#define WIDTH 720
#define HEIGHT 720

int main(){
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "");
    
    //Variables a inicializar
    int frac = 3,it = 4; //Fractal a elegir y num de it a realizar
    std::chrono::high_resolution_clock::time_point tiempoInicio,tiempoFinal;
    std::chrono::duration<double> time_span;
    bool recalculate = true;
    std::ofstream archivoSalida;

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
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                    window.close();
                }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                    recalculate = true;
                    it++;
                    printf("%i  ",it);
                }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                    recalculate = true;
                    it--;
                    printf("%i  ",it);
                }
            }
        }
        if(recalculate){
            switch (frac) {
                case 0:{
                    window.setTitle("Alfombra Sierpinski");
                    tiempoInicio =  std::chrono::high_resolution_clock::now();
                    AlfombraSierpinski as(window,it,WIDTH, HEIGHT,false,false);
                    tiempoFinal =  std::chrono::high_resolution_clock::now();
                    time_span = std::chrono::duration_cast<std::chrono::duration<double>>((tiempoFinal - tiempoInicio)*1000);
                    
                    archivoSalida.open("AlfombraSierpinskiEstadisticas.csv",std::ios_base::app);
                    if (archivoSalida.is_open()){
                        archivoSalida << it;
                        archivoSalida << ",";
                        archivoSalida << time_span.count();
                        archivoSalida << "\n";
                        archivoSalida.close();
                    }
                    std::cout << "Tiempo de ejecucion: " << time_span.count()  << " milisegundos\n";
                    break;
                }
                case 1:{
                    window.setTitle("Copo de Nieve Koch");
                    tiempoInicio =  std::chrono::high_resolution_clock::now();
                    CopoKoch ck = CopoKoch();
                    ck.setBoundingBox(0, 0, WIDTH, HEIGHT);
                    ck.setNumberOfIterations(it);
                    ck.setColor(sf::Color::Red);
                    ck.setInverted(false);
                    ck.Render(window);
                    tiempoFinal =  std::chrono::high_resolution_clock::now();
                    time_span = std::chrono::duration_cast<std::chrono::duration<double>>((tiempoFinal - tiempoInicio)*1000);
                    
                    archivoSalida.open("CopoKochEstadisticas.csv",std::ios_base::app);
                    if (archivoSalida.is_open()){
                        archivoSalida << it;
                        archivoSalida << ",";
                        archivoSalida << time_span.count();
                        archivoSalida << "\n";
                        archivoSalida.close();
                    }
                    std::cout << "Tiempo de ejecucion: " << time_span.count()  << " milisegundos\n";
                    break;
                }
                case 2:{
                    window.setTitle("Copo de Nieve Inv");
                    tiempoInicio =  std::chrono::high_resolution_clock::now();
                    
                    CopoKoch ck = CopoKoch();
                    ck.setBoundingBox(0, 0, WIDTH, HEIGHT);
                    ck.setNumberOfIterations(it);
                    ck.setColor(sf::Color::Red);
                    ck.setInverted(true);
                    ck.Render(window);
                    
                    tiempoFinal =  std::chrono::high_resolution_clock::now();
                    time_span = std::chrono::duration_cast<std::chrono::duration<double>>((tiempoFinal - tiempoInicio)*1000);
                    
                    archivoSalida.open("CopoDeNieveInv.csv",std::ios_base::app);
                    if (archivoSalida.is_open()){
                        archivoSalida << it;
                        archivoSalida << ",";
                        archivoSalida << time_span.count();
                        archivoSalida << "\n";
                        archivoSalida.close();
                    }
                    std::cout << "Tiempo de ejecucion: " << time_span.count()  << " milisegundos\n";
                    break;
                }
                case 3:{
                    window.setTitle("Triangulo Sierpinski");
                    tiempoInicio =  std::chrono::high_resolution_clock::now();
                    TrianguloSierpinski st(window, it,0,0, WIDTH,HEIGHT);
                    tiempoFinal =  std::chrono::high_resolution_clock::now();
                    time_span = std::chrono::duration_cast<std::chrono::duration<double>>((tiempoFinal - tiempoInicio)*1000);
                    
                    archivoSalida.open("TrianguloSierpinskiEstadisticas.csv",std::ios_base::app);
                    if (archivoSalida.is_open()){
                        archivoSalida << it;
                        archivoSalida << ",";
                        archivoSalida << time_span.count();
                        archivoSalida << "\n";
                        archivoSalida.close();
                    }
                    std::cout << "Tiempo de ejecucion: " << time_span.count()  << " milisegundos\n";
                    break;
                }
                case 33:{
                    
                    break;
                }
                case 4:{
                    window.setTitle("Cuadrado Sierpinski");
                    tiempoInicio =  std::chrono::high_resolution_clock::now();
                    CuadradoSierpinski s4 = CuadradoSierpinski();
                    s4.invertido = false;
                    s4.setBoundingBox(0, 0, WIDTH, HEIGHT);
                    s4.setNumberOfIterations(it);
                    s4.setColor(sf::Color::Red);
                    s4.Render(window);
                    tiempoFinal =  std::chrono::high_resolution_clock::now();
                    time_span = std::chrono::duration_cast<std::chrono::duration<double>>((tiempoFinal - tiempoInicio)*1000);
                    
                    archivoSalida.open("CuadradoSierpinskiEstadisticas.csv",std::ios_base::app);
                    if (archivoSalida.is_open()){
                        archivoSalida << it;
                        archivoSalida << ",";
                        archivoSalida << time_span.count();
                        archivoSalida << "\n";
                        archivoSalida.close();
                    }
                    std::cout << "Tiempo de ejecucion: " << time_span.count()  << " milisegundos\n";
                    break;
                }
                case 44:{
                    window.setTitle("Cuadrado Sierpinski Invertido");
                    tiempoInicio =  std::chrono::high_resolution_clock::now();
                    CuadradoSierpinski s4 = CuadradoSierpinski();
                    s4.invertido = true;
                    s4.setBoundingBox(0, 0, WIDTH, HEIGHT);
                    s4.setNumberOfIterations(it);
                    s4.setColor(sf::Color::Red);
                    s4.Render(window);
                    tiempoFinal =  std::chrono::high_resolution_clock::now();
                    time_span = std::chrono::duration_cast<std::chrono::duration<double>>((tiempoFinal - tiempoInicio)*1000);
                    
                    archivoSalida.open("CuadradoSierpinskiInvEstadisticas.csv",std::ios_base::app);
                    if (archivoSalida.is_open()){
                        archivoSalida << it;
                        archivoSalida << ",";
                        archivoSalida << time_span.count();
                        archivoSalida << "\n";
                        archivoSalida.close();
                    }
                    std::cout << "Tiempo de ejecucion: " << time_span.count()  << " milisegundos\n";
                    break;
                }
                case 5:{
                    window.setTitle("Pentagono Sierpinski");
                    tiempoInicio =  std::chrono::high_resolution_clock::now();
                    PentagonoSierpinski s5 = PentagonoSierpinski();
                    s5.invertido = false;
                    s5.setBoundingBox(0, 0, WIDTH, HEIGHT);
                    s5.setNumberOfIterations(it);
                    s5.setColor(sf::Color::Red);
                    s5.Render(window);
                    tiempoFinal =  std::chrono::high_resolution_clock::now();
                    time_span = std::chrono::duration_cast<std::chrono::duration<double>>((tiempoFinal - tiempoInicio)*1000);
                    
                    archivoSalida.open("PentagonoSierpinskiEstadisticas.csv",std::ios_base::app);
                    if (archivoSalida.is_open()){
                        archivoSalida << it;
                        archivoSalida << ",";
                        archivoSalida << time_span.count();
                        archivoSalida << "\n";
                        archivoSalida.close();
                    }
                    std::cout << "Tiempo de ejecucion: " << time_span.count()  << " milisegundos\n";
                    break;
                }
                case 55:{
                    window.setTitle("Pentagono Sierpinski Invertido");
                    tiempoInicio =  std::chrono::high_resolution_clock::now();
                    PentagonoSierpinski s5 = PentagonoSierpinski();
                    s5.invertido = true;
                    s5.setBoundingBox(0, 0, WIDTH, HEIGHT);
                    s5.setNumberOfIterations(it);
                    s5.setColor(sf::Color::Red);
                    s5.Render(window);
                    tiempoFinal =  std::chrono::high_resolution_clock::now();
                    time_span = std::chrono::duration_cast<std::chrono::duration<double>>((tiempoFinal - tiempoInicio)*1000);
                    
                    archivoSalida.open("PentagonoSierpinskiInvEstadisticas.csv",std::ios_base::app);
                    if (archivoSalida.is_open()){
                        archivoSalida << it;
                        archivoSalida << ",";
                        archivoSalida << time_span.count();
                        archivoSalida << "\n";
                        archivoSalida.close();
                    }
                    std::cout << "Tiempo de ejecucion: " << time_span.count()  << " milisegundos\n";
                    break;
                }
                case 6:{
                    window.setTitle("Hexagono Sierpinski");
                    tiempoInicio =  std::chrono::high_resolution_clock::now();
                    HexagonoSierpinski s6 = HexagonoSierpinski();
                    s6.invertido = false;
                    s6.setBoundingBox(0, 0, WIDTH, HEIGHT);
                    s6.setNumberOfIterations(it);
                    s6.setColor(sf::Color::Red);
                    s6.Render(window);
                    tiempoFinal =  std::chrono::high_resolution_clock::now();
                    time_span = std::chrono::duration_cast<std::chrono::duration<double>>((tiempoFinal - tiempoInicio)*1000);
                    
                    archivoSalida.open("HexagonoSierpinskiEstadisticas.csv",std::ios_base::app);
                    if (archivoSalida.is_open()){
                        archivoSalida << it;
                        archivoSalida << ",";
                        archivoSalida << time_span.count();
                        archivoSalida << "\n";
                        archivoSalida.close();
                    }
                    std::cout << "Tiempo de ejecucion: " << time_span.count()  << " milisegundos\n";
                    break;
                }
                case 66:{
                    window.setTitle("Hexagono Sierpinski Invertido");
                    tiempoInicio =  std::chrono::high_resolution_clock::now();
                    HexagonoSierpinski s6 = HexagonoSierpinski();
                    s6.invertido = true;
                    s6.setBoundingBox(0, 0, WIDTH, HEIGHT);
                    s6.setNumberOfIterations(it);
                    s6.setColor(sf::Color::Red);
                    s6.Render(window);
                    tiempoFinal =  std::chrono::high_resolution_clock::now();
                    time_span = std::chrono::duration_cast<std::chrono::duration<double>>((tiempoFinal - tiempoInicio)*1000);
                    
                    archivoSalida.open("HexagonoSierpinskiInvEstadisticas.csv",std::ios_base::app);
                    if (archivoSalida.is_open()){
                        archivoSalida << it;
                        archivoSalida << ",";
                        archivoSalida << time_span.count();
                        archivoSalida << "\n";
                        archivoSalida.close();
                    }
                    std::cout << "Tiempo de ejecucion: " << time_span.count()  << " milisegundos\n";
                    break;
                }
                case 7:{
                    window.setTitle("Heptagono Sierpinski");
                    tiempoInicio =  std::chrono::high_resolution_clock::now();
                    HeptagonoSierpinski s7 = HeptagonoSierpinski();
                    s7.invertido = false;
                    s7.setBoundingBox(0, 0, WIDTH, HEIGHT);
                    s7.setNumberOfIterations(it);
                    s7.setColor(sf::Color::Red);
                    s7.Render(window);
                    tiempoFinal =  std::chrono::high_resolution_clock::now();
                    time_span = std::chrono::duration_cast<std::chrono::duration<double>>((tiempoFinal - tiempoInicio)*1000);
                    
                    archivoSalida.open("HeptagonoSierpinskiEstadisticas.csv",std::ios_base::app);
                    if (archivoSalida.is_open()){
                        archivoSalida << it;
                        archivoSalida << ",";
                        archivoSalida << time_span.count();
                        archivoSalida << "\n";
                        archivoSalida.close();
                    }
                    std::cout << "Tiempo de ejecucion: " << time_span.count()  << " milisegundos\n";
                    break;
                }
                case 77:{
                    window.setTitle("Heptagono Sierpinski Inverso");
                    tiempoInicio =  std::chrono::high_resolution_clock::now();
                    HeptagonoSierpinski s7 = HeptagonoSierpinski();
                    s7.invertido = true;
                    s7.setBoundingBox(0, 0, WIDTH, HEIGHT);
                    s7.setNumberOfIterations(it);
                    s7.setColor(sf::Color::Red);
                    s7.Render(window);
                    tiempoFinal =  std::chrono::high_resolution_clock::now();
                    time_span = std::chrono::duration_cast<std::chrono::duration<double>>((tiempoFinal - tiempoInicio)*1000);
                    
                    archivoSalida.open("HeptagonoSierpinskiInvEstadisticas.csv",std::ios_base::app);
                    if (archivoSalida.is_open()){
                        archivoSalida << it;
                        archivoSalida << ",";
                        archivoSalida << time_span.count();
                        archivoSalida << "\n";
                        archivoSalida.close();
                    }
                    std::cout << "Tiempo de ejecucion: " << time_span.count()  << " milisegundos\n";
                    break;
                }
                case 8:{
                    window.setTitle("Octagono Sierpinski");
                    tiempoInicio =  std::chrono::high_resolution_clock::now();
                    OctagonoSierpinski s8 = OctagonoSierpinski();
                    s8.setBoundingBox(0, 0, WIDTH, HEIGHT);
                    s8.setNumberOfIterations(it);
                    s8.setColor(sf::Color::Red);
                    s8.Render(window);
                    tiempoFinal =  std::chrono::high_resolution_clock::now();
                    time_span = std::chrono::duration_cast<std::chrono::duration<double>>((tiempoFinal - tiempoInicio)*1000);
                    
                    archivoSalida.open("OctagonoSierpinskiEstadisticas.csv",std::ios_base::app);
                    if (archivoSalida.is_open()){
                        archivoSalida << it;
                        archivoSalida << ",";
                        archivoSalida << time_span.count();
                        archivoSalida << "\n";
                        archivoSalida.close();
                    }
                    std::cout << "Tiempo de ejecucion: " << time_span.count()  << " milisegundos\n";
                    break;
                }
                case 9:{
                    window.setTitle("Nonagono Sierpinski");
                    tiempoInicio =  std::chrono::high_resolution_clock::now();
                    NonagonoSierpinski s9 = NonagonoSierpinski();
                    s9.setBoundingBox(0, 0, WIDTH, HEIGHT);
                    s9.setNumberOfIterations(it);
                    s9.setColor(sf::Color::Red);
                    s9.Render(window);
                    tiempoFinal =  std::chrono::high_resolution_clock::now();
                    time_span = std::chrono::duration_cast<std::chrono::duration<double>>((tiempoFinal - tiempoInicio)*1000);
                    
                    archivoSalida.open("NonagonoSierpinskiEstadisticas.csv",std::ios_base::app);
                    if (archivoSalida.is_open()){
                        archivoSalida << it;
                        archivoSalida << ",";
                        archivoSalida << time_span.count();
                        archivoSalida << "\n";
                        archivoSalida.close();
                    }
                    std::cout << "Tiempo de ejecucion: " << time_span.count()  << " milisegundos\n";
                    break;
                }
                case 10:{
                    window.setTitle("Decagono Sierpinski");
                    tiempoInicio =  std::chrono::high_resolution_clock::now();
                    DecagonoSierpinski s10 = DecagonoSierpinski();
                    s10.setBoundingBox(0, 0, WIDTH, HEIGHT);
                    s10.setNumberOfIterations(it);
                    s10.setColor(sf::Color::Red);
                    s10.Render(window);
                    tiempoFinal =  std::chrono::high_resolution_clock::now();
                    time_span = std::chrono::duration_cast<std::chrono::duration<double>>((tiempoFinal - tiempoInicio)*1000);
                    
                    archivoSalida.open("DecagonoSierpinskiEstadisticas.csv",std::ios_base::app);
                    if (archivoSalida.is_open()){
                        archivoSalida << it;
                        archivoSalida << ",";
                        archivoSalida << time_span.count();
                        archivoSalida << "\n";
                        archivoSalida.close();
                    }
                    std::cout << "Tiempo de ejecucion: " << time_span.count()  << " milisegundos\n";
                    break;
                }
                default:
                    printf("Seleccione un fractal aceptado");
                    break;
            }//END SWITCH
            recalculate = false;
            window.display();
        }//END IF RECALCULATE
    }//END WHILE
    return 0;
}




