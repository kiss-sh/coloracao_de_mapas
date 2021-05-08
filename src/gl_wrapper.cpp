#include <cmath>
#include <string>
#include <GL/glut.h>
#include "gl_wrapper.hpp"
using std::string;

#define PI 3.14
char texto[30];
GLfloat win, r, g, b, raio;
GLint view_w, view_h, primitiva;

void DesenhaCirculo(GLfloat raio, int num_linhas, int posx, int posy) {
  int i;
  GLfloat angulo;
  angulo = (GLfloat)(2 * PI) / num_linhas;

  glBegin(GL_POLYGON);
  for (i = 1; i <= num_linhas; i++) {
    glVertex2f(posx + cos(i * angulo) * raio, posy + sin(i * angulo) * raio);
  }
  glEnd();
}

void Desenha(void) {
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glClear(GL_COLOR_BUFFER_BIT);

  // Define a cor corrente
  glColor3f(r, g, b);
  DesenhaCirculo(10, 100, 100, 100);

  // Exibe a posição do mouse na janela
  glColor3f(1.0f, 1.0f, 1.0f);
  //DesenhaTexto(texto);
  glutSwapBuffers();
}

void wrapper::display() {
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glClear(GL_COLOR_BUFFER_BIT);

  // apaga as informacoes de cor da renderizacao anterior
  glClearColor(0.0f, 1.0f, 1.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  DesenhaCirculo(10, 100, 100, 100);
  glFlush();
}

void Inicializa(void) {
  // Define a cor de fundo da janela de visualização como preta
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  win = 150.0f;
  //primitiva = QUADRADO;
  r = 0.0f;
  g = 1.0f;
  b = 1.0f;
}

void AlteraTamanhoJanela(GLsizei w, GLsizei h) {
  // Especifica as dimensões da Viewport
  glViewport(0, 0, w, h);
  view_w = w;
  view_h = h;

  // Inicializa o sistema de coordenadas
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-win, win, -win, win);
}

void wrapper::open_window(int width, int height, char window_name[]) {

  int argc = 1; char *argv[1] = {(char*)"opengl"}; // glut requer esses parametros
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // define os metodos de renderizacao
  glutInitWindowSize(width, height);
  glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-640)/2, // posiciona a janela
                       (glutGet(GLUT_SCREEN_HEIGHT)-480)/2); // no centro da tela
  glutInitWindowPosition(10,10);
  glutCreateWindow(window_name);
  glutDisplayFunc(Desenha);
  glutReshapeFunc(AlteraTamanhoJanela);
  Inicializa();
  glutMainLoop();
}
