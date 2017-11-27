#include "Headers/nonagonoSierpinski.h"



NonagonoSierpinski::NonagonoSierpinski(){}


void NonagonoSierpinski::Render(sf::RenderWindow& window) //OBTIENE UN RENDERWINDOW
{   /*ESTA FUNCIÓN OBTIENE LOS PARÁMETROS PARA ENCONTRAR LAS DIMENSIONES DE LOS PUNTOS
     DEL PENTÁGONO DENTRO DEL BOUNDING BOX
     */
    sf::Vector2f bottomRightPoint = sf::Vector2f(m_boundingBox.getPosition().x + m_boundingBox.getSize().x, m_boundingBox.getPosition().y + m_boundingBox.getSize().y);
    //bottomRightPoint es el punto bajo del bounding box
    
    sf::Vector2f topLeftPoint = sf::Vector2f(m_boundingBox.getPosition());
    //bottomLeftPoint es el punto alto del bounding box (0,0)
    
    sf::Vector2f center = sf::Vector2f((bottomRightPoint.x + topLeftPoint.x)/2.0, (bottomRightPoint.y + topLeftPoint.y)/2);
    //centro del pentágono
    
    sf::Vector2f p1 = sf::Vector2f((bottomRightPoint.x + topLeftPoint.x)/2.0, topLeftPoint.y);
    
    double act_radius = 90.00 ;
    double aument_radius = 360.00 / 9 ;
    
    double angle_radians = act_radius * (M_PI/180) ;
    double increment_radians = aument_radius * (M_PI/180) ;
    
    double radius = p1.y + center.y ;
    
    drawNonagonoSierpinski(p1, center, radius, angle_radians, increment_radians, -1, window);
}

void NonagonoSierpinski::drawNonagonoSierpinski(const sf::Vector2f &reference_point,
                                                const sf::Vector2f &centro,
                                                double radius,
                                                double ang_actual,
                                                double incremento_ang,
                                                int iteration, sf::RenderWindow &window){
    if(m_numberOfIterations == 0)
    {
        
        sf::Color color = sf::Color(reference_point.y/m_boundingBox.getSize().y*255, 0, window.getSize().x/m_boundingBox.getSize().x*255);
        
        sf::ConvexShape convex;
        convex.setFillColor(color);
        convex.setPointCount(9);
        convex.setPoint(0,reference_point);
        
        ang_actual += incremento_ang;
        const sf::Vector2f point1 = sf::Vector2f(radius * cos(ang_actual) + centro.x, -radius * sin(ang_actual) + centro.y);
        convex.setPoint(1,point1);
        
        ang_actual += incremento_ang;
        const sf::Vector2f point2 = sf::Vector2f(radius * cos(ang_actual) + centro.x, -(radius * sin(ang_actual)) + centro.y);
        convex.setPoint(2,point2);
        
        ang_actual += incremento_ang;
        const sf::Vector2f point3 = sf::Vector2f(radius * cos(ang_actual) + centro.x, -(radius * sin(ang_actual)) + centro.y);
        convex.setPoint(3,point3);
        
        ang_actual += incremento_ang;
        const sf::Vector2f point4 = sf::Vector2f(radius * cos(ang_actual) + centro.x, -(radius * sin(ang_actual)) + centro.y);
        convex.setPoint(4,point4);
        
        ang_actual += incremento_ang;
        const sf::Vector2f point5 = sf::Vector2f(radius * cos(ang_actual) + centro.x, -(radius * sin(ang_actual)) + centro.y);
        convex.setPoint(5,point5);
        
        ang_actual += incremento_ang;
        const sf::Vector2f point6 = sf::Vector2f(radius * cos(ang_actual) + centro.x, -(radius * sin(ang_actual)) + centro.y);
        convex.setPoint(6,point6);
        
        ang_actual += incremento_ang;
        const sf::Vector2f point7 = sf::Vector2f(radius * cos(ang_actual) + centro.x, -(radius * sin(ang_actual)) + centro.y);
        convex.setPoint(7,point7);
        
        ang_actual += incremento_ang;
        const sf::Vector2f point8 = sf::Vector2f(radius * cos(ang_actual) + centro.x, -(radius * sin(ang_actual)) + centro.y);
        convex.setPoint(8,point8);
        
        
        
        window.draw(convex);
        return;
    }
    else if(iteration == m_numberOfIterations-1){
        return;
    }
    else
    {
        ang_actual = 90.00 * (M_PI/180);
        double radius_2;
        
        if(invertido){
            radius_2 = radius - (radius * (0.01));
        }else{
            radius_2 = radius - (radius * (0.258));
        }
        
        
        
        sf::Vector2f center0 = sf::Vector2f(radius_2*cos(ang_actual) + centro.x, - radius_2*sin(ang_actual) + centro.y);
        
        ang_actual += incremento_ang;
        sf::Vector2f center1 = sf::Vector2f(radius_2*cos(ang_actual) + centro.x, -(radius_2*sin(ang_actual)) + centro.y);
        
        ang_actual += incremento_ang;
        sf::Vector2f center2 = sf::Vector2f(radius_2*cos(ang_actual) + centro.x, -(radius_2*sin(ang_actual)) + centro.y);
        
        ang_actual += incremento_ang;
        sf::Vector2f center3 = sf::Vector2f(radius_2*cos(ang_actual) + centro.x, -(radius_2*sin(ang_actual)) + centro.y);
        
        ang_actual += incremento_ang;
        sf::Vector2f center4 = sf::Vector2f(radius_2*cos(ang_actual) + centro.x, -(radius_2*sin(ang_actual)) + centro.y);
        
        ang_actual += incremento_ang;
        sf::Vector2f center5 = sf::Vector2f(radius_2*cos(ang_actual) + centro.x, -(radius_2*sin(ang_actual)) + centro.y);
        
        ang_actual += incremento_ang;
        sf::Vector2f center6 = sf::Vector2f(radius_2*cos(ang_actual) + centro.x, -(radius_2*sin(ang_actual)) + centro.y);
        
        ang_actual += incremento_ang;
        sf::Vector2f center7 = sf::Vector2f(radius_2*cos(ang_actual) + centro.x, -(radius_2*sin(ang_actual)) + centro.y);
        
        ang_actual += incremento_ang;
        sf::Vector2f center8 = sf::Vector2f(radius_2*cos(ang_actual) + centro.x, -(radius_2*sin(ang_actual)) + centro.y);
        
        
        
        
        ang_actual = 90.00 * (M_PI/180);
        
        double radius_3;
        
        if(invertido){
            radius_3 = radius * (0.49);
        }else{
           radius_3 = radius * (0.258);
        }
        
        
        
        
        
        
        
        sf::ConvexShape convex0,convex1, convex2, convex3, convex4, convex5, convex6, convex7, convex8;
        
        sf::Color color = sf::Color(reference_point.y/m_boundingBox.getSize().y*255, 0, window.getSize().x/m_boundingBox.getSize().x*255);
        
        convex0.setFillColor(color);
        convex1.setFillColor(color);
        convex2.setFillColor(color);
        convex3.setFillColor(color);
        convex4.setFillColor(color);
        convex5.setFillColor(color);
        convex6.setFillColor(color);
        convex7.setFillColor(color);
        convex8.setFillColor(color);
        
        convex0.setPointCount(9);
        convex1.setPointCount(9);
        convex2.setPointCount(9);
        convex3.setPointCount(9);
        convex4.setPointCount(9);
        convex5.setPointCount(9);
        convex6.setPointCount(9);
        convex7.setPointCount(9);
        convex8.setPointCount(9);
        
        
        //PUNTOS SUPERIORES
        const sf::Vector2f point0_0 = sf::Vector2f(radius_3*cos(ang_actual) + center0.x,-(radius_3*sin(ang_actual)) + center0.y);
        convex0.setPoint(0, point0_0);
        const sf::Vector2f point0_1 = sf::Vector2f(radius_3*cos(ang_actual) + center1.x,-(radius_3*sin(ang_actual)) + center1.y);
        convex1.setPoint(0, point0_1);
        const sf::Vector2f point0_2 = sf::Vector2f(radius_3*cos(ang_actual) + center2.x,-(radius_3*sin(ang_actual)) + center2.y);
        convex2.setPoint(0, point0_2);
        const sf::Vector2f point0_3 = sf::Vector2f(radius_3*cos(ang_actual) + center3.x,-(radius_3*sin(ang_actual)) + center3.y);
        convex3.setPoint(0, point0_3);
        const sf::Vector2f point0_4 = sf::Vector2f(radius_3*cos(ang_actual) + center4.x,-(radius_3*sin(ang_actual)) + center4.y);
        convex4.setPoint(0, point0_4);
        const sf::Vector2f point0_5 = sf::Vector2f(radius_3*cos(ang_actual) + center5.x,-(radius_3*sin(ang_actual)) + center5.y);
        convex5.setPoint(0, point0_5);
        const sf::Vector2f point0_6 = sf::Vector2f(radius_3*cos(ang_actual) + center6.x,-(radius_3*sin(ang_actual)) + center6.y);
        convex6.setPoint(0, point0_6);
        const sf::Vector2f point0_7 = sf::Vector2f(radius_3*cos(ang_actual) + center7.x,-(radius_3*sin(ang_actual)) + center7.y);
        convex7.setPoint(0, point0_7);
        const sf::Vector2f point0_8 = sf::Vector2f(radius_3*cos(ang_actual) + center8.x,-(radius_3*sin(ang_actual)) + center8.y);
        convex8.setPoint(0, point0_8);
        
        
        
        
        ang_actual += incremento_ang;
        const sf::Vector2f point1_0 = sf::Vector2f(radius_3*cos(ang_actual) + center0.x,-(radius_3*sin(ang_actual)) + center0.y);
        convex0.setPoint(1, point1_0);
        const sf::Vector2f point1_1 = sf::Vector2f(radius_3*cos(ang_actual) + center1.x, -radius_3*sin(ang_actual) + center1.y);
        convex1.setPoint(1, point1_1);
        const sf::Vector2f point1_2 = sf::Vector2f(radius_3*cos(ang_actual) + center2.x,-(radius_3*sin(ang_actual)) + center2.y);
        convex2.setPoint(1, point1_2);
        const sf::Vector2f point1_3 = sf::Vector2f(radius_3*cos(ang_actual) + center3.x,-(radius_3*sin(ang_actual)) + center3.y);
        convex3.setPoint(1, point1_3);
        const sf::Vector2f point1_4 = sf::Vector2f(radius_3*cos(ang_actual) + center4.x,-(radius_3*sin(ang_actual)) + center4.y);
        convex4.setPoint(1, point1_4);
        const sf::Vector2f point1_5 = sf::Vector2f(radius_3*cos(ang_actual) + center5.x,-(radius_3*sin(ang_actual)) + center5.y);
        convex5.setPoint(1, point1_5);
        const sf::Vector2f point1_6 = sf::Vector2f(radius_3*cos(ang_actual) + center6.x,-(radius_3*sin(ang_actual)) + center6.y);
        convex6.setPoint(1, point1_6);
        const sf::Vector2f point1_7 = sf::Vector2f(radius_3*cos(ang_actual) + center7.x,-(radius_3*sin(ang_actual)) + center7.y);
        convex7.setPoint(1, point1_7);
        const sf::Vector2f point1_8 = sf::Vector2f(radius_3*cos(ang_actual) + center8.x,-(radius_3*sin(ang_actual)) + center8.y);
        convex8.setPoint(1, point1_8);
        
        
        
        
        ang_actual += incremento_ang;
        const sf::Vector2f point2_0 = sf::Vector2f(radius_3*cos(ang_actual) + center0.x,-(radius_3*sin(ang_actual)) + center0.y);
        convex0.setPoint(2, point2_0);
        const sf::Vector2f point2_1 = sf::Vector2f(radius_3*cos(ang_actual) + center1.x,-radius_3*sin(ang_actual) + center1.y);
        convex1.setPoint(2, point2_1);
        const sf::Vector2f point2_2 = sf::Vector2f(radius_3*cos(ang_actual) + center2.x,-(radius_3*sin(ang_actual)) + center2.y);
        convex2.setPoint(2, point2_2);
        const sf::Vector2f point2_3 = sf::Vector2f(radius_3*cos(ang_actual) + center3.x,-(radius_3*sin(ang_actual)) + center3.y);
        convex3.setPoint(2, point2_3);
        const sf::Vector2f point2_4 = sf::Vector2f(radius_3*cos(ang_actual) + center4.x,-(radius_3*sin(ang_actual)) + center4.y);
        convex4.setPoint(2, point2_4);
        const sf::Vector2f point2_5 = sf::Vector2f(radius_3*cos(ang_actual) + center5.x,-(radius_3*sin(ang_actual)) + center5.y);
        convex5.setPoint(2, point2_5);
        const sf::Vector2f point2_6 = sf::Vector2f(radius_3*cos(ang_actual) + center6.x,-(radius_3*sin(ang_actual)) + center6.y);
        convex6.setPoint(2, point2_6);
        const sf::Vector2f point2_7 = sf::Vector2f(radius_3*cos(ang_actual) + center7.x,-(radius_3*sin(ang_actual)) + center7.y);
        convex7.setPoint(2, point2_7);
        const sf::Vector2f point2_8 = sf::Vector2f(radius_3*cos(ang_actual) + center8.x,-(radius_3*sin(ang_actual)) + center8.y);
        convex8.setPoint(2, point2_8);
        
        
        
        
        
        ang_actual += incremento_ang;
        const sf::Vector2f point3_0 = sf::Vector2f(radius_3*cos(ang_actual) + center0.x,-(radius_3*sin(ang_actual)) + center0.y);
        convex0.setPoint(3, point3_0);
        const sf::Vector2f point3_1 = sf::Vector2f(radius_3*cos(ang_actual) + center1.x,-(radius_3*sin(ang_actual)) + center1.y);
        convex1.setPoint(3, point3_1);
        const sf::Vector2f point3_2 = sf::Vector2f(radius_3*cos(ang_actual) + center2.x,-(radius_3*sin(ang_actual)) + center2.y);
        convex2.setPoint(3, point3_2);
        const sf::Vector2f point3_3 = sf::Vector2f(radius_3*cos(ang_actual) + center3.x,-(radius_3*sin(ang_actual)) + center3.y);
        convex3.setPoint(3, point3_3);
        const sf::Vector2f point3_4 = sf::Vector2f(radius_3*cos(ang_actual) + center4.x,-(radius_3*sin(ang_actual)) + center4.y);
        convex4.setPoint(3, point3_4);
        const sf::Vector2f point3_5 = sf::Vector2f(radius_3*cos(ang_actual) + center5.x,-(radius_3*sin(ang_actual)) + center5.y);
        convex5.setPoint(3, point3_5);
        const sf::Vector2f point3_6 = sf::Vector2f(radius_3*cos(ang_actual) + center6.x,-(radius_3*sin(ang_actual)) + center6.y);
        convex6.setPoint(3, point3_6);
        const sf::Vector2f point3_7 = sf::Vector2f(radius_3*cos(ang_actual) + center7.x,-(radius_3*sin(ang_actual)) + center7.y);
        convex7.setPoint(3, point3_7);
        const sf::Vector2f point3_8 = sf::Vector2f(radius_3*cos(ang_actual) + center8.x,-(radius_3*sin(ang_actual)) + center8.y);
        convex8.setPoint(3, point3_8);
        
        
        
        
        
        ang_actual += incremento_ang;
        const sf::Vector2f point4_0 = sf::Vector2f(radius_3*cos(ang_actual) + center0.x,-(radius_3*sin(ang_actual)) + center0.y);
        convex0.setPoint(4, point4_0);
        const sf::Vector2f point4_1 = sf::Vector2f(radius_3*cos(ang_actual) + center1.x,-radius_3*sin(ang_actual) + center1.y);
        convex1.setPoint(4, point4_1);
        const sf::Vector2f point4_2 = sf::Vector2f(radius_3*cos(ang_actual) + center2.x,-(radius_3*sin(ang_actual)) + center2.y);
        convex2.setPoint(4, point4_2);
        const sf::Vector2f point4_3 = sf::Vector2f(radius_3*cos(ang_actual) + center3.x,-(radius_3*sin(ang_actual)) + center3.y);
        convex3.setPoint(4, point4_3);
        const sf::Vector2f point4_4 = sf::Vector2f(radius_3*cos(ang_actual) + center4.x,-(radius_3*sin(ang_actual)) + center4.y);
        convex4.setPoint(4, point4_4);
        const sf::Vector2f point4_5 = sf::Vector2f(radius_3*cos(ang_actual) + center5.x,-(radius_3*sin(ang_actual)) + center5.y);
        convex5.setPoint(4, point4_5);
        const sf::Vector2f point4_6 = sf::Vector2f(radius_3*cos(ang_actual) + center6.x,-(radius_3*sin(ang_actual)) + center6.y);
        convex6.setPoint(4, point4_6);
        const sf::Vector2f point4_7 = sf::Vector2f(radius_3*cos(ang_actual) + center7.x,-(radius_3*sin(ang_actual)) + center7.y);
        convex7.setPoint(4, point4_7);
        const sf::Vector2f point4_8 = sf::Vector2f(radius_3*cos(ang_actual) + center8.x,-(radius_3*sin(ang_actual)) + center8.y);
        convex8.setPoint(4, point4_8);
        
        
        
        
        ang_actual += incremento_ang;
        const sf::Vector2f point5_0 = sf::Vector2f(radius_3*cos(ang_actual) + center0.x,-(radius_3*sin(ang_actual)) + center0.y);
        convex0.setPoint(5, point5_0);
        const sf::Vector2f point5_1 = sf::Vector2f(radius_3*cos(ang_actual) + center1.x,-(radius_3*sin(ang_actual)) + center1.y);
        convex1.setPoint(5, point5_1);
        const sf::Vector2f point5_2 = sf::Vector2f(radius_3*cos(ang_actual) + center2.x,-(radius_3*sin(ang_actual)) + center2.y);
        convex2.setPoint(5, point5_2);
        const sf::Vector2f point5_3 = sf::Vector2f(radius_3*cos(ang_actual) + center3.x,-(radius_3*sin(ang_actual)) + center3.y);
        convex3.setPoint(5, point5_3);
        const sf::Vector2f point5_4 = sf::Vector2f(radius_3*cos(ang_actual) + center4.x,-(radius_3*sin(ang_actual)) + center4.y);
        convex4.setPoint(5, point5_4);
        const sf::Vector2f point5_5 = sf::Vector2f(radius_3*cos(ang_actual) + center5.x,-(radius_3*sin(ang_actual)) + center5.y);
        convex5.setPoint(5, point5_5);
        const sf::Vector2f point5_6 = sf::Vector2f(radius_3*cos(ang_actual) + center6.x,-(radius_3*sin(ang_actual)) + center6.y);
        convex6.setPoint(5, point5_6);
        const sf::Vector2f point5_7 = sf::Vector2f(radius_3*cos(ang_actual) + center7.x,-(radius_3*sin(ang_actual)) + center7.y);
        convex7.setPoint(5, point5_7);
        const sf::Vector2f point5_8 = sf::Vector2f(radius_3*cos(ang_actual) + center8.x,-(radius_3*sin(ang_actual)) + center8.y);
        convex8.setPoint(5, point5_8);
        
        
        
        
        ang_actual += incremento_ang;
        const sf::Vector2f point6_0 = sf::Vector2f(radius_3*cos(ang_actual) + center0.x,-(radius_3*sin(ang_actual)) + center0.y);
        convex0.setPoint(6, point6_0);
        const sf::Vector2f point6_1 = sf::Vector2f(radius_3*cos(ang_actual) + center1.x,-(radius_3*sin(ang_actual)) + center1.y);
        convex1.setPoint(6, point6_1);
        const sf::Vector2f point6_2 = sf::Vector2f(radius_3*cos(ang_actual) + center2.x,-(radius_3*sin(ang_actual)) + center2.y);
        convex2.setPoint(6, point6_2);
        const sf::Vector2f point6_3 = sf::Vector2f(radius_3*cos(ang_actual) + center3.x,-(radius_3*sin(ang_actual)) + center3.y);
        convex3.setPoint(6, point6_3);
        const sf::Vector2f point6_4 = sf::Vector2f(radius_3*cos(ang_actual) + center4.x,-(radius_3*sin(ang_actual)) + center4.y);
        convex4.setPoint(6, point6_4);
        const sf::Vector2f point6_5 = sf::Vector2f(radius_3*cos(ang_actual) + center5.x,-(radius_3*sin(ang_actual)) + center5.y);
        convex5.setPoint(6, point6_5);
        const sf::Vector2f point6_6 = sf::Vector2f(radius_3*cos(ang_actual) + center6.x,-(radius_3*sin(ang_actual)) + center6.y);
        convex6.setPoint(6, point6_6);
        const sf::Vector2f point6_7 = sf::Vector2f(radius_3*cos(ang_actual) + center7.x,-(radius_3*sin(ang_actual)) + center7.y);
        convex7.setPoint(6, point6_7);
        const sf::Vector2f point6_8 = sf::Vector2f(radius_3*cos(ang_actual) + center8.x,-(radius_3*sin(ang_actual)) + center8.y);
        convex8.setPoint(6, point6_8);
        
        
        
        ang_actual += incremento_ang;
        const sf::Vector2f point7_0 = sf::Vector2f(radius_3*cos(ang_actual) + center0.x,-(radius_3*sin(ang_actual)) + center0.y);
        convex0.setPoint(7, point7_0);
        const sf::Vector2f point7_1 = sf::Vector2f(radius_3*cos(ang_actual) + center1.x,-(radius_3*sin(ang_actual)) + center1.y);
        convex1.setPoint(7, point7_1);
        const sf::Vector2f point7_2 = sf::Vector2f(radius_3*cos(ang_actual) + center2.x,-(radius_3*sin(ang_actual)) + center2.y);
        convex2.setPoint(7, point7_2);
        const sf::Vector2f point7_3 = sf::Vector2f(radius_3*cos(ang_actual) + center3.x,-(radius_3*sin(ang_actual)) + center3.y);
        convex3.setPoint(7, point7_3);
        const sf::Vector2f point7_4 = sf::Vector2f(radius_3*cos(ang_actual) + center4.x,-(radius_3*sin(ang_actual)) + center4.y);
        convex4.setPoint(7, point7_4);
        const sf::Vector2f point7_5 = sf::Vector2f(radius_3*cos(ang_actual) + center5.x,-(radius_3*sin(ang_actual)) + center5.y);
        convex5.setPoint(7, point7_5);
        const sf::Vector2f point7_6 = sf::Vector2f(radius_3*cos(ang_actual) + center6.x,-(radius_3*sin(ang_actual)) + center6.y);
        convex6.setPoint(7, point7_6);
        const sf::Vector2f point7_7 = sf::Vector2f(radius_3*cos(ang_actual) + center7.x,-(radius_3*sin(ang_actual)) + center7.y);
        convex7.setPoint(7, point7_7);
        const sf::Vector2f point7_8 = sf::Vector2f(radius_3*cos(ang_actual) + center8.x,-(radius_3*sin(ang_actual)) + center8.y);
        convex8.setPoint(7, point7_8);
        
        
        
        
        
        ang_actual += incremento_ang;
        const sf::Vector2f point8_0 = sf::Vector2f(radius_3*cos(ang_actual) + center0.x,-(radius_3*sin(ang_actual)) + center0.y);
        convex0.setPoint(8, point8_0);
        const sf::Vector2f point8_1 = sf::Vector2f(radius_3*cos(ang_actual) + center1.x,-(radius_3*sin(ang_actual)) + center1.y);
        convex1.setPoint(8, point8_1);
        const sf::Vector2f point8_2 = sf::Vector2f(radius_3*cos(ang_actual) + center2.x,-(radius_3*sin(ang_actual)) + center2.y);
        convex2.setPoint(8, point8_2);
        const sf::Vector2f point8_3 = sf::Vector2f(radius_3*cos(ang_actual) + center3.x,-(radius_3*sin(ang_actual)) + center3.y);
        convex3.setPoint(8, point8_3);
        const sf::Vector2f point8_4 = sf::Vector2f(radius_3*cos(ang_actual) + center4.x,-(radius_3*sin(ang_actual)) + center4.y);
        convex4.setPoint(8, point8_4);
        const sf::Vector2f point8_5 = sf::Vector2f(radius_3*cos(ang_actual) + center5.x,-(radius_3*sin(ang_actual)) + center5.y);
        convex5.setPoint(8, point8_5);
        const sf::Vector2f point8_6 = sf::Vector2f(radius_3*cos(ang_actual) + center6.x,-(radius_3*sin(ang_actual)) + center6.y);
        convex6.setPoint(8, point8_6);
        const sf::Vector2f point8_7 = sf::Vector2f(radius_3*cos(ang_actual) + center7.x,-(radius_3*sin(ang_actual)) + center7.y);
        convex7.setPoint(8, point8_7);
        const sf::Vector2f point8_8 = sf::Vector2f(radius_3*cos(ang_actual) + center8.x,-(radius_3*sin(ang_actual)) + center8.y);
        convex8.setPoint(8, point8_8);
        
        
        
        
        
        
        
        
        
        
        
        if(iteration == m_numberOfIterations-2)
        {
            window.draw(convex0);
            window.draw(convex1);
            window.draw(convex2);
            window.draw(convex3);
            window.draw(convex4);
            window.draw(convex5);
            window.draw(convex6);
            window.draw(convex7);
            window.draw(convex8);
            //window.draw(convex9);
            
        }
        else
        {
            ang_actual = 90.00 * (M_PI/180);
            drawNonagonoSierpinski(point0_0, center0, radius_3, ang_actual, incremento_ang, iteration+1, window);
            drawNonagonoSierpinski(point0_1, center1, radius_3, ang_actual, incremento_ang, iteration+1, window);
            drawNonagonoSierpinski(point0_2, center2, radius_3, ang_actual, incremento_ang, iteration+1, window);
            drawNonagonoSierpinski(point0_3, center3, radius_3, ang_actual, incremento_ang, iteration+1, window);
            drawNonagonoSierpinski(point0_4, center4, radius_3, ang_actual, incremento_ang, iteration+1, window);
            drawNonagonoSierpinski(point0_5, center5, radius_3, ang_actual, incremento_ang, iteration+1, window);
            drawNonagonoSierpinski(point0_6, center6, radius_3, ang_actual, incremento_ang, iteration+1, window);
            drawNonagonoSierpinski(point0_7, center7, radius_3, ang_actual, incremento_ang, iteration+1, window);
            drawNonagonoSierpinski(point0_8, center8, radius_3, ang_actual, incremento_ang, iteration+1, window);
            
            
        }
    }
    
}

// Getters/Setters

void NonagonoSierpinski::setNumberOfIterations(int newNumberOfIterations)
{
    m_numberOfIterations = newNumberOfIterations; //DA EL NÚMERO DE ITERACIONES
}

int NonagonoSierpinski::getNumberOfIterations() const
{
    return m_numberOfIterations; //OBTIENE EL NÚMERO DE ITERACIONES ***** BUSCAR DONDE SE USA
}

void NonagonoSierpinski::setBoundingBox(float x1, float y1, float x2, float y2)
{   //x1 y1 son los puntos de la esquina superior izquierda y x2 y2 de la esquina inferior derecha
    
    m_boundingBox = sf::RectangleShape();           //CONSTRUCTOR m_boundingBox
    m_boundingBox.setPosition(sf::Vector2f(x1, y1));//PONE LA POSICIÓN DEL bounding box
    m_boundingBox.setSize(sf::Vector2f(x2 - x1, y2 - y1)); //DEFINE EL TAMAÑO DEL BOUNDING BOX
}



sf::RectangleShape NonagonoSierpinski::getBoundingBox() const
{
    return m_boundingBox;                   //REGRESA EL BOUNDING BOX
}

void NonagonoSierpinski::setColor(const sf::Color& newColor) //DA EL COLOR PRINCIPAL ** VER SI SE USA OTRA VEZ
{
    m_color = sf::Color(newColor);
}

sf::Color NonagonoSierpinski::getColor() const //OBTIENE EL COLOR *** VER DONDE SE USA
{
    return m_color;
}


