#include <GL/freeglut.h>
#include "Render.h"
#include "../Object/Object.h"
#include "../Primitive/Primitive.h"
#include "../Text/Text.h"

Object *obj = new Object(100.0f, 100.0f, 0.0f, 100.0f, 100.0f, 100.0f);
Object *cube = new Object(500.0f, 500.0f, 0.0f, 100.0f, 100.0f, 100.0f);
Object *text = new Object(200, 200, 100.0f);
Object *grid = new Object(0, 0, 0);

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
