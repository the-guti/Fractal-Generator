#ifndef RENDERER_H
#define RENDERER_H
#include <SFML/Graphics.hpp>

void drawTriangle(const sf::Vector2f &top, const sf::Vector2f &left, const sf::Vector2f &right, const sf::Color &color,  sf::RenderWindow &window);
//Regresa la figura para el slow, para ponerlo en el vector
sf::ConvexShape regresaDibujoTriangulo(const sf::Vector2f &top, const sf::Vector2f &left, const sf::Vector2f &right, const sf::Color &fillColor);
#endif
