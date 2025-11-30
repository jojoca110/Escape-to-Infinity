#include <iostream>
#include <string>
#include <GL/glut.h>
#include "Game.h"

using namespace std;

////////////////////////// CONSTANTES ///////////////////////////

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int WINDOW_POSITION_X = 300;
const int WINDOW_POSITION_Y = 400;
const char TITLE[] = "PARTE 3";
bool fullScreenMode = false;


const GLclampf RED = 0.0f;
const GLclampf GREEN = 0.0f;
const GLclampf BLUE = 0.0f;
const GLclampf ALPHA = 1.0f;

///////////////////// FUNCIONES AUXILIARES //////////////////////

void writeLine(string text)
{
    cout << text << endl;
}

//////////////////////// USANDO GAME ////////////////////////////

Game game;


/////////////////////// FUNCIONES OPENGL ////////////////////////

void initGraphics()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glClearColor(RED, GREEN, BLUE, ALPHA);
    game.Init();
}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    game.Render();

    glutSwapBuffers();
}

void reshape(GLsizei width, GLsizei height)
{
    if (height == 0) height = 1;
    GLfloat aspectRatio = (GLfloat)width / (GLfloat)height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0f, aspectRatio, 1.0f, 200.0f);
    glMatrixMode(GL_MODELVIEW);
}

void idle()
{
    game.Update();
    glutPostRedisplay();
}

void keyPressed(unsigned char key, int px, int py)
{
    game.ProcessKeyPressed(key, px, py);
    
    glutPostRedisplay();
}


void specialKey(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_F11:
        fullScreenMode = !fullScreenMode;
        if (fullScreenMode)
        {
            glutFullScreen();
        }
        else
        {
            glutReshapeWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
            glutPositionWindow(WINDOW_POSITION_X, WINDOW_POSITION_Y);
        }
        break;
    }
}

//////////////////////////// MAIN ///////////////////////////////

int main(int argc, char** argv)
{
    glutInit(&argc, argv);                                          // Inicializa GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);      // double buffer, modo RGBA, depth buffer
    glutInitWindowSize(800, 600);                                   // tamaño inicail de la ventana
    glutInitWindowPosition(100, 100);                               // posicion inicial de la ventana
    glutCreateWindow(TITLE);                                        // crea una ventana con el título dado

    writeLine("Registrando funciones de tratamiento de eventos");
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyPressed);
    glutSpecialFunc(specialKey);
    glutDisplayFunc(display);                                       // tratamiento del evento de repintado de la ventana
    glutIdleFunc(idle);

    writeLine("Iniciando gráficos...");                             // Iniciamos OpenGL
    initGraphics();

    writeLine("Iniciando bucle infinito...");
    glutMainLoop();
}


