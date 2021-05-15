#include <GL/gl.h>
#include <cmath>
#include <string>
#include <GL/glut.h>
#include <vector>
#include "gl_wrapper.hpp"
using std::string;
using std::vector;

#define PI 3.14

vector<VerticePosition*> global_var_vertices;
vector<ArestaPosition*> global_var_arestas;

void DesenhaCirculo(GLfloat raio, int posx, int posy) {
  GLfloat angulo;
  int num_linhas = 100;
  angulo = (GLfloat)(2 * PI) / num_linhas;

  glBegin(GL_POLYGON);
  for (int i = 1; i <= num_linhas; i++) {
    glVertex2f(posx + cos(i * angulo) * raio, posy + sin(i * angulo) * raio);
  }
  glEnd();
}

void desenhaTexto(const char* text, int length, int x, int y) {
  double* matrix = new double[16];
  glGetDoublev(GL_PROJECTION_MATRIX, matrix);
  glOrtho(0, 800, 0, 600, -5, 5);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glPushMatrix();
  glLoadIdentity();
  glRasterPos2i(x, y);
  for (int i=0; i < length; i++) {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, (int)text[i]);
  }
  glPopMatrix();
  glMatrixMode(GL_PROJECTION);
  glLoadMatrixd(matrix);
  glMatrixMode(GL_MODELVIEW);
}

void desenhaVertice(int x, int y, string text) {
// circulo externo
  glColor3f(0.0f, 0.0f, 0.0f);
  DesenhaCirculo(20, x, y);

  // circulo interno
  glColor3f(1.0f, 1.0f, 1.0f);
  DesenhaCirculo(16, x, y);

  glColor3f(0.0f, 0.0f, 0.0f);

  // texto dentro do vertive
  const char *str = text.c_str();
  desenhaTexto(str, text.size(), x-4, y-2);
}

void desenhaAresta(int x_begin, int y_begin, int x_end, int y_end) {
  int raio = 20;

  glLineWidth(25.0f);
  glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(x_begin, y_begin);
    glVertex2f(x_end, y_end);
  glEnd();
}

void Desenha(void) {
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glClear(GL_COLOR_BUFFER_BIT);

  for (int i = 0; i < global_var_arestas.size(); i++) {
    desenhaAresta(global_var_arestas[i]->x_begin,
                  global_var_arestas[i]->y_begin,
                  global_var_arestas[i]->x_end,
                  global_var_arestas[i]->y_end);
  }

  for (int i = 0; i < global_var_vertices.size(); i++) {
    desenhaVertice(global_var_vertices[i]->x,
                   global_var_vertices[i]->y,
                   global_var_vertices[i]->nome);
  }


  glutSwapBuffers();
  glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // cor de fundo da janela
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

void open_window(int width, int height) {

  int argc = 1; char *argv[1] = {(char*)"opengl"}; // glut requer esses parametros
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // define os metodos de renderizacao
  glutInitWindowSize(width, height);
  glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-640)/2, // posiciona a janela
                       (glutGet(GLUT_SCREEN_HEIGHT)-480)/2); // no centro da tela
  glutCreateWindow("teste");
  glutDisplayFunc(Desenha);
  glutReshapeFunc(AlteraTamanhoJanela);
  glutMainLoop();
}
