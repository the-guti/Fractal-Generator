#ifndef ALFOMBRASIERPINSKI_H
#define ALFOMBRASIERPINSKI_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <vector>

class AlfombraSierpinski{
private:
    int numIt,widthWin,heightWin;
    bool invertido,slow;
    std::vector<sf::RectangleShape> vec;

public:
    //Constructor recibe num de iteraciones, tamb de donde se va a desplegar
    AlfombraSierpinski(sf::RenderWindow &window,int it, int x, int y, bool slow, bool invertido);
    //Funcion principal, crea el fractal de forma recursiva
    void drawAlfombraSierpinski(const sf::Vector2f &topLeftPoint, const sf::Vector2f &bottomRightPoint,int iteration, sf::RenderWindow &window);
};
#endif
