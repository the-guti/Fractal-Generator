#ifndef TRIANGULOSIERPINSKI_H
#define TRIANGULOSIERPINSKI_H
#include <SFML/Graphics.hpp>
#include <cmath>
#include "renderer.h"

class TrianguloSierpinski{
private:
    int iterations,x,y,width, height;
public:
    TrianguloSierpinski(sf::RenderWindow& window, int it, int x, int y, int width, int height);
    
  void drawTrianguloSierpinski(sf::RenderWindow &window, const sf::Vector2f &top, const sf::Vector2f &left, const sf::Vector2f &right,int currentIteration);
};
#endif
