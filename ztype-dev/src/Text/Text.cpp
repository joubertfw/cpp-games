#include "Text.h"
#include "../Object/Object.h"
#include "../Render/Render.h"
#include <GL/freeglut.h>

void Text::BasicText()
{
    glRasterPos3f(m_posX, m_posY, m_posZ);
    glutBitmapString(GLUT_BITMAP_HELVETICA_18, m_title);
}

void Text::draw(void (Text::*function)())
{
    glTranslatef(m_posX, m_posY, m_posZ);
    glColor3f(m_colorR, m_colorG, m_colorB);
    (this->*function)();
    m_posX += m_velX;
    m_posY += m_velY;
    m_posZ += m_velZ;
}


Text::Text(float posX, float posY, float posZ, const char* text)
{
    m_posX = posX;
    m_posY = posY;
    m_posZ = posZ;
    m_velX = .02f;
    m_velY = .02f;
    m_velZ = .02f;
    m_title = reinterpret_cast<const unsigned char *>(text);
}