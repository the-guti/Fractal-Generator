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
  SierpinskiCarpet(int it);
  ~SierpinskiCarpet();

  void setBoundingBox(const sf::RectangleShape& newBoundingBox);
  void setBoundingBox(const sf::Vector2f& topLeft, const sf::Vector2f& bottomRight);
  void setBoundingBox(float x1, float y1, float x2, float y2);
  sf::RectangleShape getBoundingBox() const;
  /*
   *  Recursively calls itself for the top, left and right subtriangle and draws the final iteration
   */
  void drawSierpinskiCarpet(const sf::Vector2f &topLeftPoint, const sf::Vector2f &bottomRightPoint,
                      int iteration, sf::RenderWindow &window, bool slow);
    //Funcion de "preparación" que llama a sierpinski draw y genera sus argumentos
  void Render(sf::RenderWindow& window);

private:
    sf::RectangleShape m_boundingBox;
    int numIt;
    sf::Color m_color;
};
#endif
