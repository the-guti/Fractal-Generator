//Librerias y Dependencias
#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>   //Medicion de tiempo
#include <fstream>  //Crear y escribir en archivos
#include <GLUT/glut.h>
//Headers
#include "Headers/renderer.h"
#include "Headers/alfombraSierpinski.h"
#include "Headers/trianguloSierpinski.h"
#include "Headers/copoKoch.h"
#include "Headers/pentagonoSierpinski.h"
#include "Headers/cuadradoSierpinski.h"
#include "Headers/hexagonoSierpinski.h"
#include "Headers/heptagonoSierpinski.h"
#include "Headers/octagonoSierpinski.h"
#include "Headers/nonagonoSierpinski.h"
#include "Headers/decagonoSierpinski.h"

#define WIDTH 720
#define HEIGHT 720

GLdouble size_cube;
GLint iteration_cubo = 0;
GLfloat c_x = 0.00;
GLfloat c_y = 0.00;
GLfloat c_z = 0.00;


static int r_x = 0, r_y = 0, r_z = 0;
long cont = 0;

void init(void){
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    
    GLfloat ambient[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat position[] = { 2.0, 2.0, 3.0, 0.0 };
    GLfloat lmodel_ambient[] = { 0.4, 0.4, 0.4, 1.0 };
    GLfloat local_view[] = { 0.0 };
    
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
    glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, local_view);
}


void print_cube(GLdouble size, GLdouble cx, GLdouble cy, GLdouble cz, GLfloat nep_dif[],GLfloat nep_emission[]){
    glPushMatrix();
    glTranslatef(cx, cy, cz);
    glMaterialfv(GL_FRONT, GL_AMBIENT, nep_dif);
    glMaterialfv(GL_FRONT, GL_EMISSION, nep_emission);
    glutSolidCube(size);
    glPopMatrix();
}


void draw_SierpinskiCube(GLdouble centro_x, GLdouble centro_y, GLdouble centro_z, GLdouble lado_n,GLfloat nep_dif[],GLfloat nep_emission[],GLint iteration){
    
    if (iteration_cubo == 0) {
        print_cube(lado_n, centro_x, centro_y, centro_z, nep_dif, nep_emission);
    }else{
        GLdouble lado = lado_n / 3;
        if (iteration == iteration_cubo - 2) {
            //CUBO POR EL FRENTE
            print_cube(lado, -lado + centro_x, lado + centro_y, lado + centro_z, nep_dif, nep_emission);
            print_cube(lado, -lado + centro_x, 0 + centro_y, lado + centro_z, nep_dif, nep_emission);
            print_cube(lado, -lado + centro_x, -lado + centro_y, lado + centro_z, nep_dif, nep_emission);
            print_cube(lado, 0 + centro_x, lado + centro_y, lado + centro_z, nep_dif, nep_emission);
            print_cube(lado, 0 + centro_x, -lado + centro_y, lado + centro_z, nep_dif, nep_emission);
            print_cube(lado, lado + centro_x, lado + centro_y, lado + centro_z, nep_dif, nep_emission);
            print_cube(lado, lado + centro_x, 0 + centro_y, lado + centro_z, nep_dif, nep_emission);
            print_cube(lado, lado + centro_x, -lado + centro_y, lado + centro_z, nep_dif, nep_emission);
            
            //CUBO EN MEDIO
            print_cube(lado, -lado + centro_x, lado + centro_y,0 + centro_z, nep_dif, nep_emission);
            print_cube(lado, -lado + centro_x, -lado + centro_y, 0 + centro_z, nep_dif, nep_emission);
            print_cube(lado, lado + centro_x, lado + centro_y, 0 + centro_z, nep_dif, nep_emission);
            print_cube(lado, lado + centro_x, -lado + centro_y, 0 + centro_z, nep_dif, nep_emission);
            
            //CUBO POR ATRÁS
            print_cube(lado, -lado + centro_x, lado + centro_y, -lado + centro_z, nep_dif, nep_emission);
            print_cube(lado, -lado + centro_x, 0 + centro_y, -lado + centro_z, nep_dif, nep_emission);
            print_cube(lado, -lado + centro_x, -lado + centro_y, -lado + centro_z, nep_dif, nep_emission);
            print_cube(lado, 0 + centro_x, lado + centro_y, -lado + centro_z, nep_dif, nep_emission);
            print_cube(lado, 0 + centro_x, -lado + centro_y, -lado + centro_z, nep_dif, nep_emission);
            print_cube(lado, lado + centro_x, lado + centro_y, -lado + centro_z, nep_dif, nep_emission);
            print_cube(lado, lado + centro_x, 0 + centro_y, -lado + centro_z, nep_dif, nep_emission);
            print_cube(lado, lado + centro_x, -lado + centro_y, -lado + centro_z, nep_dif, nep_emission);
        }else{
            draw_SierpinskiCube(-lado + centro_x, lado + centro_y, lado + centro_z, lado, nep_dif, nep_emission, iteration+1);
            draw_SierpinskiCube(-lado + centro_x, 0 + centro_y, lado + centro_z, lado, nep_dif, nep_emission, iteration+1);
            draw_SierpinskiCube(-lado + centro_x, -lado + centro_y, lado + centro_z, lado, nep_dif, nep_emission, iteration+1);
            draw_SierpinskiCube(0 + centro_x, lado + centro_y, lado + centro_z, lado, nep_dif, nep_emission, iteration+1);
            draw_SierpinskiCube(0 + centro_x, -lado + centro_y, lado + centro_z, lado, nep_dif, nep_emission, iteration+1);
            draw_SierpinskiCube(lado + centro_x, lado + centro_y, lado + centro_z, lado, nep_dif, nep_emission, iteration+1);
            draw_SierpinskiCube(lado + centro_x, 0 + centro_y, lado + centro_z, lado, nep_dif, nep_emission, iteration+1);
            draw_SierpinskiCube(lado + centro_x, -lado + centro_y, lado + centro_z, lado, nep_dif, nep_emission, iteration+1);
            
            draw_SierpinskiCube(-lado + centro_x, lado + centro_y,0 + centro_z, lado, nep_dif, nep_emission, iteration+1);
            draw_SierpinskiCube(-lado + centro_x, -lado + centro_y, 0 + centro_z, lado, nep_dif, nep_emission, iteration+1);
            draw_SierpinskiCube(lado + centro_x, lado + centro_y, 0 + centro_z, lado, nep_dif, nep_emission, iteration+1);
            draw_SierpinskiCube(lado + centro_x, -lado + centro_y, 0 + centro_z, lado, nep_dif, nep_emission, iteration+1);
            
            draw_SierpinskiCube(-lado + centro_x, lado + centro_y, -lado + centro_z, lado, nep_dif, nep_emission, iteration+1);
            draw_SierpinskiCube(-lado + centro_x, 0 + centro_y, -lado + centro_z, lado, nep_dif, nep_emission, iteration+1);
            draw_SierpinskiCube(-lado + centro_x, -lado + centro_y, -lado + centro_z, lado, nep_dif, nep_emission, iteration+1);
            draw_SierpinskiCube(0 + centro_x, lado + centro_y, -lado + centro_z, lado, nep_dif, nep_emission, iteration+1);
            draw_SierpinskiCube(0 + centro_x, -lado + centro_y, -lado + centro_z, lado, nep_dif, nep_emission, iteration+1);
            draw_SierpinskiCube(lado + centro_x, lado + centro_y, -lado + centro_z, lado, nep_dif, nep_emission, iteration+1);
            draw_SierpinskiCube(lado + centro_x, 0 + centro_y, -lado + centro_z, lado, nep_dif, nep_emission, iteration+1);
            draw_SierpinskiCube(lado + centro_x, -lado + centro_y, -lado + centro_z, lado, nep_dif, nep_emission, iteration+1);
        }
    }
    
}

void display(void)
{
    //Material cubo
    GLfloat nep_dif[] = { 0.32, 0.8, 0.87, 1.0 };
    GLfloat nep_emission[] = {0.0, 0.0, 0.54, 1.0};
    
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glRotatef ((GLfloat) r_x, 1.0, 0.0, 0.0);
    glRotatef ((GLfloat) r_y, 0.0, 1.0, 0.0);
    glRotatef ((GLfloat) r_z, 0.0, 0.0, 1.0);
    
   /*q if (!size_cube) {
        std::cout << "Tamaño del cubo: "; std::cin >> size_cube;
    }*/
    GLdouble cx = c_x, cy = c_y, cz = c_z, lado = 6;

    //GLdouble cx = c_x, cy = c_y, cz = c_z, lado = size_cube;
    
    draw_SierpinskiCube(cx, cy, cz, lado, nep_dif, nep_emission, -1);
    
    glutSwapBuffers();
}

void reshape (int w, int h)
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 40.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}


void keyboard(unsigned char key, int x_, int y_){
    switch (key) {
        case 'q':
            exit(0);
            break;
            
        case '+':
            r_x = 0;
            r_y = 0;
            r_z = 0;
            iteration_cubo += 1;
            glutPostRedisplay();
            break;
            
        case '-':
            r_x = 0;
            r_y = 0;
            r_z = 0;
            iteration_cubo -= 1;
            glutPostRedisplay();
            break;
            
        case 'X':
            r_x = 0;
            r_y = 0;
            r_z = 0;
            r_x = (r_x + 10) % 360;
            glutPostRedisplay();
            break;
            
        case 'x':
            r_x = 0;
            r_y = 0;
            r_z = 0;
            r_x = (r_x - 10) % 360;
            glutPostRedisplay();
            break;
            
        case 'Y':
            r_x = 0;
            r_y = 0;
            r_z = 0;
            r_y = (r_y + 10) % 360;
            glutPostRedisplay();
            break;
            
        case 'y':
            r_x = 0;
            r_y = 0;
            r_z = 0;
            r_y = (r_y - 10) % 360;
            glutPostRedisplay();
            break;
            
        case 'Z':
            r_x = 0;
            r_y = 0;
            r_z = 0;
            r_z = (r_z + 10) % 360;
            glutPostRedisplay();
            break;
            
        case 'z':
            r_x = 0;
            r_y = 0;
            r_z = 0;
            r_z = (r_z - 10) % 360;
            glutPostRedisplay();
            break;
            
        case 'w':
            r_x = 0;
            r_y = 0;
            r_z = 0;
            c_y += 0.05;
            glutPostRedisplay();
            break;
            
        case 's':
            r_x = 0;
            r_y = 0;
            r_z = 0;
            c_y -= 0.15;
            glutPostRedisplay();
            break;
            
        case 'a':
            r_x = 0;
            r_y = 0;
            r_z = 0;
            c_x -= 0.15;
            glutPostRedisplay();
            break;
            
        case 'd':
            r_x = 0;
            r_y = 0;
            r_z = 0;
            c_x += 0.15;
            glutPostRedisplay();
            break;
            
        case 'f':
            r_x = 0;
            r_y = 0;
            r_z = 0;
            c_z += 0.15;
            glutPostRedisplay();
            break;
            
        case 'b':
            r_x = 0;
            r_y = 0;
            r_z = 0;
            c_z -= 0.15;
            glutPostRedisplay();
            break;
            
        default:
            break;
    }
}

int main(int argc, char** argv){
    int frac = 3,it = 4,op=3; //Fractal a elegir y num de it a realizar
    std::chrono::high_resolution_clock::time_point tiempoInicio,tiempoFinal;
    std::chrono::duration<double> time_span;
    bool recalculate = true;
    std::ofstream archivoSalida;
    
    printf("----- Elegir Dimension -----\n\n");
    printf("\t2D\t\t -> 2\n \t3D\t\t -> 3\n");
    std::cin >> op;
    if(op==3){
        glutInit(&argc, argv);
        glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
        glutInitWindowSize (1000, 1000);
        glutInitWindowPosition (10, 10);
        glutCreateWindow (argv[0]);
        init();
        glutKeyboardFunc(keyboard);
        glutDisplayFunc(display);
        glutReshapeFunc(reshape);
        glutMainLoop();
    }else{
        printf("\n\n----- Elegir Fractal a mostrar -----\n\n");
        printf("\tAlfombra Sierpinski\t\t -> 0\n \tCopo de Nieve Koch\t\t -> 1\n \tCopo de Nieve Inv\t\t -> 2\n \tTriangulo de Sierpinski\t -> 3\n \tCuadrado de Sierpinski\t -> 4\n \tPentagono Sierpinski\t -> 5\n \tHexagono de Sierpinski\t -> 6\n \tHeptagono de Sierpinski\t -> 7\n \tOctagono de Sierpinski\t -> 8\n \tNonagono de Sierpinski\t -> 9\n \tDecagono de Sierpinski\t -> 10\n");
        std::cin >> frac;
        
        printf("Favor de introducir numero de iteraciones \n");
        std::cin >> it;
        
        sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Juan Ventana");
        window.clear();
        window.setActive(false);
        sf::RenderWindow window2(sf::VideoMode(WIDTH, HEIGHT), "Maria Ventana");
        window2.clear();
        window2.setVisible(false);
        window2.setActive(false);

        while (window.isOpen()){
            window.clear();//Limpia ventana antes de empezar
            window2.clear();
            sf::Event event;
            
            //Aqui van inputs
            while (window.pollEvent(event)){
                if (event.type == sf::Event::Closed)//Para que la ventana se pueda cerrar en caso de que el usuario haga click en la barra
                    window.close();
                if (event.type == sf::Event::KeyPressed){
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                        window.close();
                    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                        recalculate = true;
                        it++;
                        printf("%i  ",it);
                    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                        recalculate = true;
                        it--;
                        printf("%i  ",it);
                    }
                }
            }
            if(recalculate){
                window.setActive(false);
                window2.setActive(true);
                TrianguloSierpinski st(window2, it,0,0, WIDTH,HEIGHT, false);//variable bool es de paso a paso
                window2.setTitle("Triangulo");
                window2.display();
                window2.setActive(false);
                window.setActive(true);
                switch (frac) {
                    case 0:{
                        window.setTitle("Alfombra Sierpinski");
                        tiempoInicio =  std::chrono::high_resolution_clock::now();
                        AlfombraSierpinski as(window,it,WIDTH, HEIGHT,false,false);
                        tiempoFinal =  std::chrono::high_resolution_clock::now();
                        time_span = std::chrono::duration_cast<std::chrono::duration<double>>((tiempoFinal - tiempoInicio)*1000);
                        
                        archivoSalida.open("AlfombraSierpinskiEstadisticas.csv",std::ios_base::app);
                        if (archivoSalida.is_open()){
                            archivoSalida << it;
                            archivoSalida << ",";
                            archivoSalida << time_span.count();
                            archivoSalida << "\n";
                            archivoSalida.close();
                        }
                        std::cout << "Tiempo de ejecucion: " << time_span.count()  << " milisegundos\n";
                        break;
                    }
                    case 1:{
                        window.setTitle("Copo de Nieve Koch");
                        tiempoInicio =  std::chrono::high_resolution_clock::now();
                        CopoKoch ck = CopoKoch();
                        ck.setBoundingBox(0, 0, WIDTH, HEIGHT);
                        ck.setNumberOfIterations(it);
                        ck.setColor(sf::Color::Red);
                        ck.setInverted(false);
                        ck.Render(window);
                        tiempoFinal =  std::chrono::high_resolution_clock::now();
                        time_span = std::chrono::duration_cast<std::chrono::duration<double>>((tiempoFinal - tiempoInicio)*1000);
                        
                        archivoSalida.open("CopoKochEstadisticas.csv",std::ios_base::app);
                        if (archivoSalida.is_open()){
                            archivoSalida << it;
                            archivoSalida << ",";
                            archivoSalida << time_span.count();
                            archivoSalida << "\n";
                            archivoSalida.close();
                        }
                        std::cout << "Tiempo de ejecucion: " << time_span.count()  << " milisegundos\n";
                        break;
                    }
                    case 2:{
                        window.setTitle("Copo de Nieve Inv");
                        tiempoInicio =  std::chrono::high_resolution_clock::now();
                        
                        CopoKoch ck = CopoKoch();
                        ck.setBoundingBox(0, 0, WIDTH, HEIGHT);
                        ck.setNumberOfIterations(it);
                        ck.setColor(sf::Color::Red);
                        ck.setInverted(true);
                        ck.Render(window);
                        
                        tiempoFinal =  std::chrono::high_resolution_clock::now();
                        time_span = std::chrono::duration_cast<std::chrono::duration<double>>((tiempoFinal - tiempoInicio)*1000);
                        
                        archivoSalida.open("CopoDeNieveInv.csv",std::ios_base::app);
                        if (archivoSalida.is_open()){
                            archivoSalida << it;
                            archivoSalida << ",";
                            archivoSalida << time_span.count();
                            archivoSalida << "\n";
                            archivoSalida.close();
                        }
                        std::cout << "Tiempo de ejecucion: " << time_span.count()  << " milisegundos\n";
                        break;
                    }
                    case 3:{
                        window.setTitle("Triangulo Sierpinski");
                        tiempoInicio =  std::chrono::high_resolution_clock::now();
                        TrianguloSierpinski st(window, it,0,0, WIDTH,HEIGHT, false);//variable bool es de paso a paso
                        tiempoFinal =  std::chrono::high_resolution_clock::now();
                        time_span = std::chrono::duration_cast<std::chrono::duration<double>>((tiempoFinal - tiempoInicio)*1000);
                        
                        archivoSalida.open("TrianguloSierpinskiEstadisticas.csv",std::ios_base::app);
                        if (archivoSalida.is_open()){
                            archivoSalida << it;
                            archivoSalida << ",";
                            archivoSalida << time_span.count();
                            archivoSalida << "\n";
                            archivoSalida.close();
                        }
                        std::cout << "Tiempo de ejecucion: " << time_span.count()  << " milisegundos\n";
                        break;
                    }
                    case 33:{
                        
                        break;
                    }
                    case 4:{
                        window.setTitle("Cuadrado Sierpinski");
                        tiempoInicio =  std::chrono::high_resolution_clock::now();
                        CuadradoSierpinski s4 = CuadradoSierpinski();
                        s4.invertido = false;
                        s4.setBoundingBox(0, 0, WIDTH, HEIGHT);
                        s4.setNumberOfIterations(it);
                        s4.setColor(sf::Color::Red);
                        s4.Render(window);
                        tiempoFinal =  std::chrono::high_resolution_clock::now();
                        time_span = std::chrono::duration_cast<std::chrono::duration<double>>((tiempoFinal - tiempoInicio)*1000);
                        
                        archivoSalida.open("CuadradoSierpinskiEstadisticas.csv",std::ios_base::app);
                        if (archivoSalida.is_open()){
                            archivoSalida << it;
                            archivoSalida << ",";
                            archivoSalida << time_span.count();
                            archivoSalida << "\n";
                            archivoSalida.close();
                        }
                        std::cout << "Tiempo de ejecucion: " << time_span.count()  << " milisegundos\n";
                        break;
                    }
                    case 44:{
                        window.setTitle("Cuadrado Sierpinski Invertido");
                        tiempoInicio =  std::chrono::high_resolution_clock::now();
                        CuadradoSierpinski s4 = CuadradoSierpinski();
                        s4.invertido = true;
                        s4.setBoundingBox(0, 0, WIDTH, HEIGHT);
                        s4.setNumberOfIterations(it);
                        s4.setColor(sf::Color::Red);
                        s4.Render(window);
                        tiempoFinal =  std::chrono::high_resolution_clock::now();
                        time_span = std::chrono::duration_cast<std::chrono::duration<double>>((tiempoFinal - tiempoInicio)*1000);
                        
                        archivoSalida.open("CuadradoSierpinskiInvEstadisticas.csv",std::ios_base::app);
                        if (archivoSalida.is_open()){
                            archivoSalida << it;
                            archivoSalida << ",";
                            archivoSalida << time_span.count();
                            archivoSalida << "\n";
                            archivoSalida.close();
                        }
                        std::cout << "Tiempo de ejecucion: " << time_span.count()  << " milisegundos\n";
                        break;
                    }
                    case 5:{
                        window.setTitle("Pentagono Sierpinski");
                        tiempoInicio =  std::chrono::high_resolution_clock::now();
                        PentagonoSierpinski s5 = PentagonoSierpinski();
                        s5.invertido = false;
                        s5.setBoundingBox(0, 0, WIDTH, HEIGHT);
                        s5.setNumberOfIterations(it);
                        s5.setColor(sf::Color::Red);
                        s5.Render(window);
                        tiempoFinal =  std::chrono::high_resolution_clock::now();
                        time_span = std::chrono::duration_cast<std::chrono::duration<double>>((tiempoFinal - tiempoInicio)*1000);
                        
                        archivoSalida.open("PentagonoSierpinskiEstadisticas.csv",std::ios_base::app);
                        if (archivoSalida.is_open()){
                            archivoSalida << it;
                            archivoSalida << ",";
                            archivoSalida << time_span.count();
                            archivoSalida << "\n";
                            archivoSalida.close();
                        }
                        std::cout << "Tiempo de ejecucion: " << time_span.count()  << " milisegundos\n";
                        break;
                    }
                    case 55:{
                        window.setTitle("Pentagono Sierpinski Invertido");
                        tiempoInicio =  std::chrono::high_resolution_clock::now();
                        PentagonoSierpinski s5 = PentagonoSierpinski();
                        s5.invertido = true;
                        s5.setBoundingBox(0, 0, WIDTH, HEIGHT);
                        s5.setNumberOfIterations(it);
                        s5.setColor(sf::Color::Red);
                        s5.Render(window);
                        tiempoFinal =  std::chrono::high_resolution_clock::now();
                        time_span = std::chrono::duration_cast<std::chrono::duration<double>>((tiempoFinal - tiempoInicio)*1000);
                        
                        archivoSalida.open("PentagonoSierpinskiInvEstadisticas.csv",std::ios_base::app);
                        if (archivoSalida.is_open()){
                            archivoSalida << it;
                            archivoSalida << ",";
                            archivoSalida << time_span.count();
                            archivoSalida << "\n";
                            archivoSalida.close();
                        }
                        std::cout << "Tiempo de ejecucion: " << time_span.count()  << " milisegundos\n";
                        break;
                    }
                    case 6:{
                        window.setTitle("Hexagono Sierpinski");
                        tiempoInicio =  std::chrono::high_resolution_clock::now();
                        HexagonoSierpinski s6 = HexagonoSierpinski();
                        s6.invertido = false;
                        s6.setBoundingBox(0, 0, WIDTH, HEIGHT);
                        s6.setNumberOfIterations(it);
                        s6.setColor(sf::Color::Red);
                        s6.Render(window);
                        tiempoFinal =  std::chrono::high_resolution_clock::now();
                        time_span = std::chrono::duration_cast<std::chrono::duration<double>>((tiempoFinal - tiempoInicio)*1000);
                        
                        archivoSalida.open("HexagonoSierpinskiEstadisticas.csv",std::ios_base::app);
                        if (archivoSalida.is_open()){
                            archivoSalida << it;
                            archivoSalida << ",";
                            archivoSalida << time_span.count();
                            archivoSalida << "\n";
                            archivoSalida.close();
                        }
                        std::cout << "Tiempo de ejecucion: " << time_span.count()  << " milisegundos\n";
                        break;
                    }
                    case 66:{
                        window.setTitle("Hexagono Sierpinski Invertido");
                        tiempoInicio =  std::chrono::high_resolution_clock::now();
                        HexagonoSierpinski s6 = HexagonoSierpinski();
                        s6.invertido = true;
                        s6.setBoundingBox(0, 0, WIDTH, HEIGHT);
                        s6.setNumberOfIterations(it);
                        s6.setColor(sf::Color::Red);
                        s6.Render(window);
                        tiempoFinal =  std::chrono::high_resolution_clock::now();
                        time_span = std::chrono::duration_cast<std::chrono::duration<double>>((tiempoFinal - tiempoInicio)*1000);
                        
                        archivoSalida.open("HexagonoSierpinskiInvEstadisticas.csv",std::ios_base::app);
                        if (archivoSalida.is_open()){
                            archivoSalida << it;
                            archivoSalida << ",";
                            archivoSalida << time_span.count();
                            archivoSalida << "\n";
                            archivoSalida.close();
                        }
                        std::cout << "Tiempo de ejecucion: " << time_span.count()  << " milisegundos\n";
                        break;
                    }
                    case 7:{
                        window.setTitle("Heptagono Sierpinski");
                        tiempoInicio =  std::chrono::high_resolution_clock::now();
                        HeptagonoSierpinski s7 = HeptagonoSierpinski();
                        s7.invertido = false;
                        s7.setBoundingBox(0, 0, WIDTH, HEIGHT);
                        s7.setNumberOfIterations(it);
                        s7.setColor(sf::Color::Red);
                        s7.Render(window);
                        tiempoFinal =  std::chrono::high_resolution_clock::now();
                        time_span = std::chrono::duration_cast<std::chrono::duration<double>>((tiempoFinal - tiempoInicio)*1000);
                        
                        archivoSalida.open("HeptagonoSierpinskiEstadisticas.csv",std::ios_base::app);
                        if (archivoSalida.is_open()){
                            archivoSalida << it;
                            archivoSalida << ",";
                            archivoSalida << time_span.count();
                            archivoSalida << "\n";
                            archivoSalida.close();
                        }
                        std::cout << "Tiempo de ejecucion: " << time_span.count()  << " milisegundos\n";
                        break;
                    }
                    case 77:{
                        window.setTitle("Heptagono Sierpinski Inverso");
                        tiempoInicio =  std::chrono::high_resolution_clock::now();
                        HeptagonoSierpinski s7 = HeptagonoSierpinski();
                        s7.invertido = true;
                        s7.setBoundingBox(0, 0, WIDTH, HEIGHT);
                        s7.setNumberOfIterations(it);
                        s7.setColor(sf::Color::Red);
                        s7.Render(window);
                        tiempoFinal =  std::chrono::high_resolution_clock::now();
                        time_span = std::chrono::duration_cast<std::chrono::duration<double>>((tiempoFinal - tiempoInicio)*1000);
                        
                        archivoSalida.open("HeptagonoSierpinskiInvEstadisticas.csv",std::ios_base::app);
                        if (archivoSalida.is_open()){
                            archivoSalida << it;
                            archivoSalida << ",";
                            archivoSalida << time_span.count();
                            archivoSalida << "\n";
                            archivoSalida.close();
                        }
                        std::cout << "Tiempo de ejecucion: " << time_span.count()  << " milisegundos\n";
                        break;
                    }
                    case 8:{
                        window.setTitle("Octagono Sierpinski");
                        tiempoInicio =  std::chrono::high_resolution_clock::now();
                        OctagonoSierpinski s8 = OctagonoSierpinski();
                        s8.invertido = false;
                        s8.setBoundingBox(0, 0, WIDTH, HEIGHT);
                        s8.setNumberOfIterations(it);
                        s8.setColor(sf::Color::Red);
                        s8.Render(window);
                        tiempoFinal =  std::chrono::high_resolution_clock::now();
                        time_span = std::chrono::duration_cast<std::chrono::duration<double>>((tiempoFinal - tiempoInicio)*1000);
                        
                        archivoSalida.open("OctagonoSierpinskiEstadisticas.csv",std::ios_base::app);
                        if (archivoSalida.is_open()){
                            archivoSalida << it;
                            archivoSalida << ",";
                            archivoSalida << time_span.count();
                            archivoSalida << "\n";
                            archivoSalida.close();
                        }
                        std::cout << "Tiempo de ejecucion: " << time_span.count()  << " milisegundos\n";
                        break;
                    }
                    case 88:{
                        window.setTitle("Octagono Sierpinski Invertido");
                        tiempoInicio =  std::chrono::high_resolution_clock::now();
                        OctagonoSierpinski s8 = OctagonoSierpinski();
                        s8.invertido = true;
                        s8.setBoundingBox(0, 0, WIDTH, HEIGHT);
                        s8.setNumberOfIterations(it);
                        s8.setColor(sf::Color::Red);
                        s8.Render(window);
                        tiempoFinal =  std::chrono::high_resolution_clock::now();
                        time_span = std::chrono::duration_cast<std::chrono::duration<double>>((tiempoFinal - tiempoInicio)*1000);
                        
                        archivoSalida.open("OctagonoSierpinskiInvEstadisticas.csv",std::ios_base::app);
                        if (archivoSalida.is_open()){
                            archivoSalida << it;
                            archivoSalida << ",";
                            archivoSalida << time_span.count();
                            archivoSalida << "\n";
                            archivoSalida.close();
                        }
                        std::cout << "Tiempo de ejecucion: " << time_span.count()  << " milisegundos\n";
                        break;
                    }
                    case 9:{
                        window.setTitle("Nonagono Sierpinski");
                        tiempoInicio =  std::chrono::high_resolution_clock::now();
                        NonagonoSierpinski s9 = NonagonoSierpinski();
                        s9.invertido = false;
                        s9.setBoundingBox(0, 0, WIDTH, HEIGHT);
                        s9.setNumberOfIterations(it);
                        s9.setColor(sf::Color::Red);
                        s9.Render(window);
                        tiempoFinal =  std::chrono::high_resolution_clock::now();
                        time_span = std::chrono::duration_cast<std::chrono::duration<double>>((tiempoFinal - tiempoInicio)*1000);
                        
                        archivoSalida.open("NonagonoSierpinskiEstadisticas.csv",std::ios_base::app);
                        if (archivoSalida.is_open()){
                            archivoSalida << it;
                            archivoSalida << ",";
                            archivoSalida << time_span.count();
                            archivoSalida << "\n";
                            archivoSalida.close();
                        }
                        std::cout << "Tiempo de ejecucion: " << time_span.count()  << " milisegundos\n";
                        break;
                    }
                    case 99:{
                        window.setTitle("Nonagono Sierpinski Invertido");
                        tiempoInicio =  std::chrono::high_resolution_clock::now();
                        NonagonoSierpinski s9 = NonagonoSierpinski();
                        s9.invertido = true;
                        s9.setBoundingBox(0, 0, WIDTH, HEIGHT);
                        s9.setNumberOfIterations(it);
                        s9.setColor(sf::Color::Red);
                        s9.Render(window);
                        tiempoFinal =  std::chrono::high_resolution_clock::now();
                        time_span = std::chrono::duration_cast<std::chrono::duration<double>>((tiempoFinal - tiempoInicio)*1000);
                        
                        archivoSalida.open("NonagonoSierpinskiInvEstadisticas.csv",std::ios_base::app);
                        if (archivoSalida.is_open()){
                            archivoSalida << it;
                            archivoSalida << ",";
                            archivoSalida << time_span.count();
                            archivoSalida << "\n";
                            archivoSalida.close();
                        }
                        std::cout << "Tiempo de ejecucion: " << time_span.count()  << " milisegundos\n";
                        break;
                    }
                    case 10:{
                        window.setTitle("Decagono Sierpinski");
                        tiempoInicio =  std::chrono::high_resolution_clock::now();
                        DecagonoSierpinski s10 = DecagonoSierpinski();
                        s10.invertido = false;
                        s10.setBoundingBox(0, 0, WIDTH, HEIGHT);
                        s10.setNumberOfIterations(it);
                        s10.setColor(sf::Color::Red);
                        s10.Render(window);
                        tiempoFinal =  std::chrono::high_resolution_clock::now();
                        time_span = std::chrono::duration_cast<std::chrono::duration<double>>((tiempoFinal - tiempoInicio)*1000);
                        
                        archivoSalida.open("DecagonoSierpinskiEstadisticas.csv",std::ios_base::app);
                        if (archivoSalida.is_open()){
                            archivoSalida << it;
                            archivoSalida << ",";
                            archivoSalida << time_span.count();
                            archivoSalida << "\n";
                            archivoSalida.close();
                        }
                        std::cout << "Tiempo de ejecucion: " << time_span.count()  << " milisegundos\n";
                        break;
                    }
                    case 1010:{
                        window.setTitle("Decagono Sierpinski Inv");
                        tiempoInicio =  std::chrono::high_resolution_clock::now();
                        DecagonoSierpinski s10 = DecagonoSierpinski();
                        s10.invertido = true;
                        s10.setBoundingBox(0, 0, WIDTH, HEIGHT);
                        s10.setNumberOfIterations(it);
                        s10.setColor(sf::Color::Red);
                        s10.Render(window);
                        tiempoFinal =  std::chrono::high_resolution_clock::now();
                        time_span = std::chrono::duration_cast<std::chrono::duration<double>>((tiempoFinal - tiempoInicio)*1000);
                        
                        archivoSalida.open("DecagonoSierpinskiInvEstadisticas.csv",std::ios_base::app);
                        if (archivoSalida.is_open()){
                            archivoSalida << it;
                            archivoSalida << ",";
                            archivoSalida << time_span.count();
                            archivoSalida << "\n";
                            archivoSalida.close();
                        }
                        std::cout << "Tiempo de ejecucion: " << time_span.count()  << " milisegundos\n";
                        break;
                    }
                    default:
                        printf("Seleccione un fractal aceptado");
                        break;
                }//END SWITCH//
                recalculate = false;
                window.display();
            }//END IF RECALCULATE
            
        }//END WHILE
    }//END IF 2D 3D
    return 0;
}





