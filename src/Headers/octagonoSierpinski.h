#ifndef octagonoSierpinski_h
#define octagonoSierpinski_h

#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
#include <chrono>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include "renderer.h"

class OctagonoSierpinski
{
public:
    OctagonoSierpinski();
    void setNumberOfIterations(int newNumberOfIterations);
    int getNumberOfIterations() const;
    bool invertido;
    
   
    void setBoundingBox(float x1, float y1, float x2, float y2);
    sf::RectangleShape getBoundingBox() const;
    
    void setColor(const sf::Color& newColor);
    sf::Color getColor() const;
    
    
    
    void drawOctagonoSierpinski(const sf::Vector2f &reference_point,
                               const sf::Vector2f &centro,
                               double radius,
                               double ang_actual,
                               double incremento_ang,
                               int iteration, sf::RenderWindow &window);
    
    
    void Render(sf::RenderWindow& window);
    
private:
    sf::RectangleShape m_boundingBox;
    int m_numberOfIterations;
    sf::Color m_color;
};


#endif /* octagonoSierpinski_h */
