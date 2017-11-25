#ifndef ALFOMBRASIERPINSKI_H
#define ALFOMBRASIERPINSKI_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include "renderer.h"
class SierpinskiCarpet{
public:
    //Constructor recibe num de iteraciones, tam de donde se va a desplegar
    SierpinskiCarpet(int it, int x, int y);
    ~SierpinskiCarpet();

    void setBoundingBox(float x1, float y1, float x2, float y2);
    sf::RectangleShape getBoundingBox() const;

    //Funcion principal, crea el fractal de forma recursiva
    void drawSierpinskiCarpet(const sf::Vector2f &topLeftPoint, const sf::Vector2f &bottomRightPoint,
                      int iteration, sf::RenderWindow &window, bool slow);
    //Funcion de "preparación" que llama a sierpinski draw y genera sus argumentos
  void Render(sf::RenderWindow& window);

private:
    sf::RectangleShape m_boundingBox;
    int numIt,widthWin,heightWin;
};
#endif
