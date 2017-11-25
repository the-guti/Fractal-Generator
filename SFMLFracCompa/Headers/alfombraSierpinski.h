#ifndef ALFOMBRASIERPINSKI_H
#define ALFOMBRASIERPINSKI_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
class SierpinskiCarpet{
private:
    int numIt,widthWin,heightWin;
public:
    //Constructor recibe num de iteraciones, tam de donde se va a desplegar
    SierpinskiCarpet(int it, int x, int y);
    ~SierpinskiCarpet();
    //Funcion principal, crea el fractal de forma recursiva
    void drawSierpinskiCarpet(const sf::Vector2f &topLeftPoint, const sf::Vector2f &bottomRightPoint,int iteration, sf::RenderWindow &window, bool slow);
    //Funcion de "preparación" que llama a sierpinski draw y genera sus argumentos
  void Render(sf::RenderWindow& window);
};
#endif
