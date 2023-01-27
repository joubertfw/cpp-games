#include <stdlib.h>
#include <GL/glut.h>
#include "Callbacks.h"

/* Main method */
int main(int argc, char** argv)
{
  glutInit(&argc, argv);

  /* Create a single window with a keyboard and display callback */
  glutCreateWindow("GLUT Test");
  glutKeyboardFunc(&keyboard);
  glutDisplayFunc(&display);

  /* Run the GLUT event loop */
  glutMainLoop();

  return EXIT_SUCCESS;
}