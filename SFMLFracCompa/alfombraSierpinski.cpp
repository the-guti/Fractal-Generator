#include "Headers/alfombraSierpinski.h"

//Constructor
AlfombraSierpinski::AlfombraSierpinski(sf::RenderWindow& window, int it, int x, int y, bool slow, bool inv){
    numIt = it; //Se asignan numero de iteraciones a realizar a la clase
    widthWin = x;
    heightWin = y;
    invertido = inv;
    this->slow = slow;
    std::vector<sf::RectangleShape> vec;
    vec.clear();
    drawAlfombraSierpinski(sf::Vector2f(0, 0),sf::Vector2f(widthWin, heightWin), 0, window);
}

void AlfombraSierpinski::drawAlfombraSierpinski(const sf::Vector2f &topLeftPoint, const sf::Vector2f &bottomRightPoint, int currentIteration, sf::RenderWindow &window){
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
            vec.push_back(rect);
            for(int i = 0;vec.size()>i ;i++){
                window.draw(vec[i]);
            }
            window.display();
        }else{
            window.draw(rect);
        }
      return;
    }
    for(int i = 0; i < 9; i++){
        if(invertido){
            // FALTA IMPLEMENTAR
        } else {
            if(i==4){//Salta el 5to cuadro porque es el vacio
                continue;//De regreso al principio loop papa
            }
            width = std::abs(bottomRightPoint.x - topLeftPoint.x)/3;
            height= std::abs(bottomRightPoint.y - topLeftPoint.y)/3;
            int ii = i % 3;
            int ij = i / 3;
            
            sf::Vector2f newTopLeft = sf::Vector2f(topLeftPoint.x + (ii*width), topLeftPoint.y + ij*height);
            sf::Vector2f newBottomRight = sf::Vector2f(topLeftPoint.x + (ii+1)*width, topLeftPoint.y + (ij+1)*height);
            drawAlfombraSierpinski(newTopLeft, newBottomRight, currentIteration+1, window);
        }
        
    }
}
