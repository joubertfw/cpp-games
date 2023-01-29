#include <GL/glut.h>
#include "Render.h"
#include "../Object/Object.h"

void Render::Draw()
{
    // for (auto i = Objects.begin(); i != Objects.end(); ++i)
      glClearColor(0.0, 0.0, 0.0, 1);
  glClear(GL_COLOR_BUFFER_BIT);

  /* Display a red square */
  glColor3f(1.0f, 0.0f, 0.0f);

  glPushMatrix();

    glTranslated(0, 1, 0);
    glBegin(GL_POLYGON);
      glVertex2f(-0.5f, -0.5f);
      glVertex2f( 0.5f, -0.5f);
      glVertex2f( 0.5f,  0.5f);
      glVertex2f(-0.5f,  0.5f);
    glEnd();

  glPopMatrix();

  glutSwapBuffers();
  glutPostRedisplay();

  glFlush();
};
