#include <stdlib.h>
#include <stdio.h>
#include <GL/freeglut.h>
#include "Render/Render.h"

#pragma region Defines

  #define WIN_SIZE_X 800
  #define WIN_SIZE_Y 600
  #define WIN_INI_SIZE_X 0
  #define WIN_INI_SIZE_Y 0
  #define WIN_NAME "ztype-dev"

#pragma endregion

// int time = 0;

// void timer(int v)
// {
//   printf("%d", v);
//   v++;
//   glutTimerFunc(1000, timer, v);
// }


Render *render;

void display();

int main(int argc, char** argv)
{
  render = new Render();
  
  glutInit(&argc, argv);

  glutInitWindowSize(WIN_SIZE_X, WIN_SIZE_Y);
  glutCreateWindow(WIN_NAME);
  gluOrtho2D(WIN_INI_SIZE_X, WIN_SIZE_X, WIN_INI_SIZE_Y, WIN_SIZE_Y);
  glutFullScreen();

  glutDisplayFunc(&display);
  glutMainLoop();

  return EXIT_SUCCESS;
}

void display()
{
  render->Draw();
}