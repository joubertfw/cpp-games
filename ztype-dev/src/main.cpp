#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include "Callbacks.h"
#include "Primitives/Primitives.h"

int time = 0;

void timer(int v)
{
  printf("%d", v);
  v++;
  glutTimerFunc(1000, timer, v);
}

int main(int argc, char** argv)
{
  glutInit(&argc, argv);

  /* Create a single window with a keyboard and display callback */
  glutCreateWindow("GLUT Test");
  glutKeyboardFunc(&keyboard);
  glutDisplayFunc(&display);

  glutTimerFunc(1000, timer, time);

  gluOrtho2D(0, 0, 200, 200);  
  /* Run the GLUT event loop */
  glutMainLoop();

  return EXIT_SUCCESS;
}