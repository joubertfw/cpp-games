#include <GL/freeglut.h>
#include "Render.h"
#include "../Object/Object.h"
#include "../Primitive/Primitive.h"

Primitive *primitive = new Primitive();

void Render::Draw()
{
  // for (auto i = Objects.begin(); i != Objects.end(); ++i)
  glClearColor(0.0, 0.0, 0.0, 1);
  glClear(GL_COLOR_BUFFER_BIT);
  glRasterPos2i(50, 50);
  glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
  const unsigned char* t2 = reinterpret_cast<const unsigned char *>("text to render");

  glutBitmapString(GLUT_BITMAP_HELVETICA_18,t2);
  glClear(GL_COLOR_BUFFER_BIT);

  /* Display a red square */
  glColor3f(1.0f, 0.0f, 0.0f);

  glPushMatrix();

    glRasterPos2i(0, 0);
    glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
    const unsigned char* t = reinterpret_cast<const unsigned char *>("text to render");

    glutBitmapString(GLUT_BITMAP_HELVETICA_18,t);
    glColor3f(1.0f, 0.0f, 0.0f);

    glTranslated(0, 1, 0);
    glBegin(GL_POLYGON);
      primitive->Quad(1.5f, 1.5f, 0.0f, 0.0f);
    glEnd();

  glPopMatrix();

  glutSwapBuffers();
  glutPostRedisplay();

  glFlush();
};
