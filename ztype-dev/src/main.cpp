#include <stdlib.h>
#include <stdio.h>
#include <GL/freeglut.h>
#include "Render/Render.h"

#pragma region Defines

  #define WIN_SIZE_X 1920
  #define WIN_SIZE_Y 1080
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
void init();

int main(int argc, char** argv)
{
  render = new Render();
  
  glutInit(&argc, argv);

  init();
  glutMainLoop();

  return EXIT_SUCCESS;
}

void display()
{
  render->Draw();
}

void keyboard(unsigned char key, int mouseX, int mouseY)
{
  switch (key){
		case 'w':
			glClearColor(1.0, 0.0, 0.0, 0.0);
			break;
		case 'r': 
			glClearColor(0.0, 1.0, 0.0, 0.0);
		break;
		default:
         break;
	}
  glutPostRedisplay();
}

void init()
{
  glutInitWindowSize(WIN_SIZE_X, WIN_SIZE_Y);
  glutCreateWindow(WIN_NAME);  
  glOrtho(WIN_INI_SIZE_X, WIN_SIZE_X, WIN_INI_SIZE_Y, WIN_SIZE_Y, -1000.0, 1000.0);
  glutFullScreen();

  
  glutDisplayFunc(&display);
  glutKeyboardFunc(&keyboard);


  glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
  glClearDepth(1000.0f);                   // Set background depth to farthest
  glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
  glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
  glShadeModel(GL_SMOOTH);   // Enable smooth shading
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}