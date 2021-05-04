#include <GL/freeglut_std.h>
#include <string>
#include <GL/glut.h>
#include "gl_wrapper.hpp"
using std::string;

void wrapper::display() {

  // apaga as informacoes de cor da renderizacao anterior
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  glFlush();
}

void wrapper::open_window(int width, int height, char window_name[]) {

  int argc = 1; char *argv[1] = {(char*)"opengl"}; // glut requer esses parametros
  glutInit(&argc, argv);

  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // define os metodos de renderizacao

  glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-640)/2, // posiciona a janela
                       (glutGet(GLUT_SCREEN_HEIGHT)-480)/2); // no centro da tela

  glutInitWindowSize(width, height);
  glutCreateWindow(window_name);

  glutDisplayFunc(wrapper::display);
  glutMainLoop();
}
