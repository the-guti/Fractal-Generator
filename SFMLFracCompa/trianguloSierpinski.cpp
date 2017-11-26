#include "Headers/trianguloSierpinski.h"
//Constructor
SierpinskiTriangle::SierpinskiTriangle(sf::RenderWindow& window, int it, int x, int y, int width, int height){
    
    sf::Vector2f bottomRightPoint = sf::Vector2f(x + width, y + height);
    sf::Vector2f topLeftPoint = sf::Vector2f(x,y);
    
    sf::Vector2f top = sf::Vector2f((bottomRightPoint.x + topLeftPoint.x)/2.0, topLeftPoint.y);
    sf::Vector2f left = sf::Vector2f(topLeftPoint.x, bottomRightPoint.y);
    sf::Vector2f right = sf::Vector2f(bottomRightPoint.x, bottomRightPoint.y);
    
    drawSierpinskiTriangle(window, top, left, right, -1);
}

void SierpinskiTriangle::drawSierpinskiTriangle(sf::RenderWindow &window, const sf::Vector2f &top, const sf::Vector2f &left, const sf::Vector2f &right, int currentIteration){
    
    if(iterations == 0){//Caso Base
        sf::Color color = sf::Color(top.y/height*255, 0, right.x/width*255);
        drawTriangle(top, left, right, color, window);
        return;
    }else if(currentIteration == iterations-1){
        return;
    }else{
        sf::Vector2f midLeft = sf::Vector2f((left.x + top.x)/2.0, (left.y+top.y)/2.0);
        sf::Vector2f midRight = sf::Vector2f((right.x + top.x)/2.0, (right.y + top.y)/2.0);
        sf::Vector2f midBottom = sf::Vector2f((left.x+right.x)/2.0, (left.y+right.y)/2.0);

        if(currentIteration == iterations-2){
            
          sf::Color color = sf::Color(top.y/height*255, 0, midRight.x/width*255);
          drawTriangle(top, midLeft, midRight, color, window);
            
          color = sf::Color(midLeft.y/height*255, 0, midRight.x/height*255);
          drawTriangle(midLeft, left, midBottom, color, window);
            
          color = sf::Color(midRight.y/height*255, 0, midRight.x/width*255);
          drawTriangle(midRight, midBottom, right, color, window);
        }else{
            drawSierpinskiTriangle(window, top, midLeft, midRight, currentIteration+1);
            drawSierpinskiTriangle(window, midLeft, left, midBottom, currentIteration+1);
            drawSierpinskiTriangle(window, midRight, midBottom, right, currentIteration+1);
        }
      }
}
