#include <GL/freeglut.h>
#include "Render.h"
#include "../Object/Object.h"
#include "../Primitive/Primitive.h"
#include "../Text/Text.h"

Object *obj = new Object(100.0f, 100.0f, 0.0f, 100.0f, 100.0f, 100.0f);
Object *cube = new Object(500.0f, 500.0f, 0.0f, 100.0f, 100.0f, 100.0f);
Object *text = new Object(200, 200, 100.0f);
Object *grid = new Object(0, 0, 0);

#pragma region Defines

  #define WIN_SIZE_X 1920
  #define WIN_SIZE_Y 1080
  #define WIN_INI_SIZE_X 0
  #define WIN_INI_SIZE_Y 0
  #define WIN_NAME "ztype-dev"

#pragma endregion

Render::Render()
{
  glutInitWindowSize(WIN_SIZE_X, WIN_SIZE_Y);
  glutCreateWindow(WIN_NAME);  
  glOrtho(WIN_INI_SIZE_X, WIN_SIZE_X, WIN_INI_SIZE_Y, WIN_SIZE_Y, -1000.0, 1000.0);
  glutFullScreen();  


  glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
  glClearDepth(1000.0f);                   // Set background depth to farthest
  glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
  glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
  glShadeModel(GL_SMOOTH);   // Enable smooth shading
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
  glutDisplayFunc(Render::Draw);
  glutKeyboardFunc(Render::Keyboard);

  glutMainLoop();
}

void Render::Draw()
{
  // for (auto i = Objects.begin(); i != Objects.end(); ++i)

  obj->setColor(130.0f, 0.0f, 0.0f);
  // glClearColor(0.0, 0.0, 0.0, 1);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);

  glPushMatrix();
    grid->draw(&Primitive::Grid);
    cube->draw(&Primitive::Cube);
    obj->draw(&Primitive::Triangle);
    text->draw(&Text::BasicText);

  glPopMatrix();

  glutSwapBuffers();
  glutPostRedisplay();

  glFlush();
};

void Render::Keyboard(unsigned char key, int mouseX, int mouseY)
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
