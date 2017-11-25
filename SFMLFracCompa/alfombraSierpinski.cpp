#include "Headers/alfombraSierpinski.h"

//Constructor y Destructor
SierpinskiCarpet::SierpinskiCarpet(sf::RenderWindow& window, int it, int x, int y){
    numIt = it; //Se asignan numero de iteraciones a realizar a la clase
    widthWin = x;
    heightWin = y;
    drawSierpinskiCarpet(sf::Vector2f(0, 0),sf::Vector2f(widthWin, heightWin), 0, window, false);
}

SierpinskiCarpet::~SierpinskiCarpet(){}

void SierpinskiCarpet::drawSierpinskiCarpet(const sf::Vector2f &topLeftPoint, const sf::Vector2f &bottomRightPoint, int currentIteration, sf::RenderWindow &window, bool slow){
    float width, height;
    int R,G,B;
    if(currentIteration == numIt){
        width  = std::abs(bottomRightPoint.x - topLeftPoint.x);
        height = std::abs(bottomRightPoint.y - topLeftPoint.y);
      sf::RectangleShape rect = sf::RectangleShape(sf::Vector2f(width, height));
        
        //Color
      R = 255 - (1.0*bottomRightPoint.y)/widthWin*255;
      G = 255 - (1.0*bottomRightPoint.x)/widthWin*255;
      B = (R + G)/2;
      sf::Color color = sf::Color(R, G, B);
      rect.setFillColor(color);
        
      rect.setPosition(topLeftPoint);
        if(slow){
            window.clear();
            window.draw(rect);
            //window.setFramerateLimit(1);
            window.display();
        }else{
            window.draw(rect);
        }
      return;
    }
    for(int i = 0; i < 9; i++){
        if(i==4){//Salta el 5to cuadro porque es el vacio
            continue;//De regreso al principio loop papa
        }
        width = std::abs(bottomRightPoint.x - topLeftPoint.x)/3;
        height= std::abs(bottomRightPoint.y - topLeftPoint.y)/3;
        int ii = i % 3;
        int ij = i / 3;
        
        sf::Vector2f newTopLeft = sf::Vector2f(topLeftPoint.x + (ii*width), topLeftPoint.y + ij*height);
        sf::Vector2f newBottomRight = sf::Vector2f(topLeftPoint.x + (ii+1)*width, topLeftPoint.y + (ij+1)*height);
        drawSierpinskiCarpet(newTopLeft, newBottomRight, currentIteration+1, window, slow);
    }
}
