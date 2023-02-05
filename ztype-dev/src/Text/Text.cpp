#include "Text.h"
#include "../Object/Object.h"
#include "../Render/Render.h"
#include <GL/freeglut.h>

void Text::BasicText()
{
    glRasterPos2i(m_posX, m_posY);
    glColor4f(0.0f, 0.0f, 1.0f, 1.0f);

    glutBitmapString(GLUT_BITMAP_HELVETICA_18, m_title);
    glColor3f(0.0f, 0.0f, 0.0f);
}

void Text::draw(void (Text::*function)())
{
    glColor3f(m_colorR, m_colorG, m_colorB);
    (this->*function)();
}


Text::Text(float posX, float posY, float posZ, char* text)
{
    m_posX = posX;
    m_posY = posY;
    m_posZ = posZ;
    m_title = reinterpret_cast<const unsigned char *>(text);
}