#include "Headers/cuadradoSierpinski.h"


CuadradoSierpinski::CuadradoSierpinski(){}


void CuadradoSierpinski::Render(sf::RenderWindow& window) //OBTIENE UN RENDERWINDOW
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
    double aument_radius = 360 / 4 ;
    
    double angle_radians = act_radius * (M_PI/180) ;
    double increment_radians = aument_radius * (M_PI/180) ;
    
    double radius = p1.y + center.y ;
    
    drawCuadradoSierpinski(p1, center, radius, angle_radians, increment_radians, -1, window);
}

void CuadradoSierpinski::drawCuadradoSierpinski(const sf::Vector2f &reference_point,
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
        convex.setPointCount(4);
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
        //radius_2 = radius - (radius * 0.00001);
        radius_2 = radius - (radius * 0.45);
        
        sf::Vector2f center0 = sf::Vector2f(centro.x + radius_2*cos(ang_actual), centro.y - radius_2*sin(ang_actual));
        
        ang_actual += incremento_ang;
        sf::Vector2f center1 = sf::Vector2f(radius_2*cos(ang_actual) + centro.x, -(radius_2*sin(ang_actual)) + centro.y);
        
        ang_actual += incremento_ang;
        sf::Vector2f center2 = sf::Vector2f(radius_2*cos(ang_actual) + centro.x, -(radius_2*sin(ang_actual)) + centro.y);
        
        ang_actual += incremento_ang;
        sf::Vector2f center3 = sf::Vector2f(radius_2*cos(ang_actual) + centro.x, -(radius_2*sin(ang_actual)) + centro.y);
        
        ang_actual = 90.00 * (M_PI/180);
        //double radius_3 = radius * 0.49999;
        double radius_3 = radius * 0.45;
        
        sf::ConvexShape convex0,convex1, convex2, convex3, convex4;
        sf::Color color = sf::Color(reference_point.y/m_boundingBox.getSize().y*255, 0, window.getSize().x/m_boundingBox.getSize().x*255);
        
        
        convex0.setFillColor(color);
        convex1.setFillColor(color);
        convex2.setFillColor(color);
        convex3.setFillColor(color);
        
        convex0.setPointCount(4);
        convex1.setPointCount(4);
        convex2.setPointCount(4);
        convex3.setPointCount(4);
        
        //PUNTOS SUPERIORES
        const sf::Vector2f point0_0 = sf::Vector2f(radius_3*cos(ang_actual) + center0.x,center0.y - radius_3*sin(ang_actual));
        convex0.setPoint(0, point0_0);
        
        const sf::Vector2f point0_1 = sf::Vector2f(radius_3*cos(ang_actual) + center1.x,-(radius_3*sin(ang_actual)) + center1.y);
        convex1.setPoint(0, point0_1);
        const sf::Vector2f point0_2 = sf::Vector2f(radius_3*cos(ang_actual) + center2.x,-(radius_3*sin(ang_actual)) + center2.y);
        convex2.setPoint(0, point0_2);
        const sf::Vector2f point0_3 = sf::Vector2f(radius_3*cos(ang_actual) + center3.x,-(radius_3*sin(ang_actual)) + center3.y);
        convex3.setPoint(0, point0_3);
        
        ang_actual += incremento_ang;
        const sf::Vector2f point1_0 = sf::Vector2f(radius_3*cos(ang_actual) + center0.x,center0.y - radius_3*sin(ang_actual));
        convex0.setPoint(1, point1_0);
        const sf::Vector2f point1_1 = sf::Vector2f(radius_3*cos(ang_actual) + center1.x, -radius_3*sin(ang_actual) + center1.y);
        convex1.setPoint(1, point1_1);
        const sf::Vector2f point1_2 = sf::Vector2f(radius_3*cos(ang_actual) + center2.x,-(radius_3*sin(ang_actual)) + center2.y);
        convex2.setPoint(1, point1_2);
        const sf::Vector2f point1_3 = sf::Vector2f(radius_3*cos(ang_actual) + center3.x,-(radius_3*sin(ang_actual)) + center3.y);
        convex3.setPoint(1, point1_3);
        
        ang_actual += incremento_ang;
        const sf::Vector2f point2_0 = sf::Vector2f(center0.x + radius_3*cos(ang_actual), -radius_3*sin(ang_actual) + center0.y);
        convex0.setPoint(2, point2_0);
        const sf::Vector2f point2_1 = sf::Vector2f(radius_3*cos(ang_actual) + center1.x,-radius_3*sin(ang_actual) + center1.y);
        convex1.setPoint(2, point2_1);
        const sf::Vector2f point2_2 = sf::Vector2f(radius_3*cos(ang_actual) + center2.x,-(radius_3*sin(ang_actual)) + center2.y);
        convex2.setPoint(2, point2_2);
        const sf::Vector2f point2_3 = sf::Vector2f(radius_3*cos(ang_actual) + center3.x,-(radius_3*sin(ang_actual)) + center3.y);
        convex3.setPoint(2, point2_3);
        
        ang_actual += incremento_ang;
        const sf::Vector2f point3_0 = sf::Vector2f(center0.x + radius_3*cos(ang_actual), -radius_3*sin(ang_actual) + center0.y);
        convex0.setPoint(3, point3_0);
        const sf::Vector2f point3_1 = sf::Vector2f(radius_3*cos(ang_actual) + center1.x,-radius_3*sin(ang_actual) + center1.y);
        convex1.setPoint(3, point3_1);
        const sf::Vector2f point3_2 = sf::Vector2f(radius_3*cos(ang_actual) + center2.x,-(radius_3*sin(ang_actual)) + center2.y);
        convex2.setPoint(3, point3_2);
        const sf::Vector2f point3_3 = sf::Vector2f(radius_3*cos(ang_actual) + center3.x,-(radius_3*sin(ang_actual)) + center3.y);
        convex3.setPoint(3, point3_3);
        
        if(iteration == m_numberOfIterations-2)
        {
            window.draw(convex0);
            window.draw(convex1);
            window.draw(convex2);
            window.draw(convex3);
        }
        else
        {
            ang_actual = 90.00 * (M_PI/180);
            drawCuadradoSierpinski(point0_0, center0, radius_3, ang_actual, incremento_ang, iteration+1, window);
            drawCuadradoSierpinski(point0_1, center1, radius_3, ang_actual, incremento_ang, iteration+1, window);
            drawCuadradoSierpinski(point0_2, center2, radius_3, ang_actual, incremento_ang, iteration+1, window);
            drawCuadradoSierpinski(point0_3, center3, radius_3, ang_actual, incremento_ang, iteration+1, window);
        }
    }
    
}

// Getters/Setters

void CuadradoSierpinski::setNumberOfIterations(int newNumberOfIterations)
{
    m_numberOfIterations = newNumberOfIterations; //DA EL NÚMERO DE ITERACIONES
}

int CuadradoSierpinski::getNumberOfIterations() const
{
    return m_numberOfIterations; //OBTIENE EL NÚMERO DE ITERACIONES ***** BUSCAR DONDE SE USA
}

void CuadradoSierpinski::setBoundingBox(float x1, float y1, float x2, float y2)
{   //x1 y1 son los puntos de la esquina superior izquierda y x2 y2 de la esquina inferior derecha
    
    m_boundingBox = sf::RectangleShape();           //CONSTRUCTOR m_boundingBox
    m_boundingBox.setPosition(sf::Vector2f(x1, y1));//PONE LA POSICIÓN DEL bounding box
    m_boundingBox.setSize(sf::Vector2f(x2 - x1, y2 - y1)); //DEFINE EL TAMAÑO DEL BOUNDING BOX
}



sf::RectangleShape CuadradoSierpinski::getBoundingBox() const
{
    return m_boundingBox;                   //REGRESA EL BOUNDING BOX
}

void CuadradoSierpinski::setColor(const sf::Color& newColor) //DA EL COLOR PRINCIPAL ** VER SI SE USA OTRA VEZ
{
    m_color = sf::Color(newColor);
}

sf::Color CuadradoSierpinski::getColor() const //OBTIENE EL COLOR *** VER DONDE SE USA
{
    return m_color;
}

