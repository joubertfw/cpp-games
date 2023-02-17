#include "Text.h"
#include "../Object/Object.h"
#include "../Game/Game.h"
#include <GL/freeglut.h>
#include <string>

void Text::BasicText()
{
    glColor3f(m_colorR, 0, m_colorB);
    glRasterPos2f(m_posX, m_posY);
    int wd = 0;
    for (int i = 0; i < this->m_textPos; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, m_title[i]);
        wd += glutBitmapWidth(GLUT_BITMAP_HELVETICA_18, int(m_title[i]));
    }
    glColor3f(0, 0, m_colorB);
    glRasterPos2f(m_posX + wd, m_posY);
    // glColor3f(255, 255, 255);
    for (int i = this->m_textPos; i < sizeof(m_title); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, m_title[i]);
    }
}

void Text::draw(void (Text::*function)())
{
    glTranslatef(m_posX, m_posY, m_posZ);
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
    m_textPos = 0;
    m_title = reinterpret_cast<const unsigned char *>(text);
}

void Text::keyboard(unsigned char key, int mouseX, int mouseY)
{
    if(key == m_title[this->m_textPos])
    {
        this->m_textPos++;
    }
}