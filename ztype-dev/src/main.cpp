#include <stdlib.h>
#include <stdio.h>
#include <GL/freeglut.h>

#include "Render/Render.h"

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

  /* Create a single window with a keyboard and display callback */
  glutCreateWindow("GLUT Test");
  glutDisplayFunc(&display);


  gluOrtho2D(0, 0, 600, 600);  
  /* Run the GLUT event loop */
  glutMainLoop();

  return EXIT_SUCCESS;
}

void display()
{
  render->Draw();
}