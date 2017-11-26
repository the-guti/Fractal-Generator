#ifndef TRIANGULOSIERPINSKI_H
#define TRIANGULOSIERPINSKI_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "renderer.h"

class SierpinskiTriangle{
private:
    int iterations,x,y,width, height;
public:
  SierpinskiTriangle(sf::RenderWindow& window, int it, int x, int y, int width, int height);
    
  void drawSierpinskiTriangle(sf::RenderWindow &window, const sf::Vector2f &top, const sf::Vector2f &left, const sf::Vector2f &right,int currentIteration);
    
};
#endif
