#include <cmath>
#include <string>
#include <GL/glut.h>
#include "gl_wrapper.hpp"
using std::string;

#define PI 3.14
char texto[30];
GLfloat win, r, g, b, raio;
GLint view_w, view_h, primitiva;

void DesenhaCirculo(GLfloat raio, int posx, int posy) {
  int i;
  GLfloat angulo;
  int num_linhas = 100;
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
  DesenhaCirculo(100, 100, 100);
  glutSwapBuffers();
}

void Inicializa(void) {
  // Define a cor de fundo da janela de visualização como preta
  glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
  win = 150.0f;
  //primitiva = QUADRADO;
  r = 0.0f;
  g = 0.0f;
  b = 1.0f;
}

void AlteraTamanhoJanela(GLsizei w, GLsizei h) {
  if(h == 0) h = 1; // Evita a divisao por zero
  glViewport(0, 0, w, h); // Especifica as dimensões da Viewport

  // Inicializa o sistema de coordenadas
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  // Estabelece a janela de seleção (left, right, bottom, top)
  if (w <= h)
    gluOrtho2D (0.0f, 250.0f, 0.0f, 250.0f*h/w);
  else
    gluOrtho2D (0.0f, 250.0f*w/h, 0.0f, 250.0f);
}

void wrapper::open_window(int width, int height) {

  int argc = 1; char *argv[1] = {(char*)"opengl"}; // glut requer esses parametros
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // define os metodos de renderizacao
  glutInitWindowSize(width, height);
  glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-640)/2, // posiciona a janela
                       (glutGet(GLUT_SCREEN_HEIGHT)-480)/2); // no centro da tela
  glutInitWindowPosition(10,10);
  glutCreateWindow("teste");
  glutDisplayFunc(Desenha);
  glutReshapeFunc(AlteraTamanhoJanela);
  Inicializa();
  glutMainLoop();
}
