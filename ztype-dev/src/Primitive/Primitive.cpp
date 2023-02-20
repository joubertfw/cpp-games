#include "Primitive.h"
#include "../Object/Object.h"
#include "../Game/Game.h"
#include <GL/freeglut.h>

int i = 0;

void Primitive::Quad()
{    
    glBegin(GL_POLYGON);
        glColor3f(m_colorR, m_colorG, m_colorB);
        glVertex3f(m_posX, m_posY, 0.0);
        glVertex3f(m_posX + m_sizeX, m_posY, 0.0);
        glVertex3f(m_posX + m_sizeX, m_posY + m_sizeY, 0.0);
        glVertex3f(m_posX, m_posY + m_sizeY, 0.0);
    glEnd();
}

void Primitive::Cube()
{
    i++;
    // glTranslatef((m_posX + m_sizeX)/2, (m_posY + m_sizeY)/2, 0.0f);
    
    Line();
    glRotatef(i/10, m_posX, 0.0, 0.0);
    glBegin(GL_QUADS);        
        // glColor3f(m_colorR, m_colorG, m_colorB);

        // Top face (y = m_posY)
        glColor3f(0.0f, 1.0f, 0.0f);     // Green
        glVertex3f(0.0f, 0.0f, m_sizeZ);
        glVertex3f(m_sizeX, 0.0f, m_sizeZ);
        glVertex3f(m_sizeX, 0.0f,  0.0f);
        glVertex3f(0.0f, 0.0f,  0.0f);
    
        // Bottom face (y = m_sizeY)
        glColor3f(1.0f, 0.5f, 0.0f);     // Orange
        glVertex3f(0.0f, m_sizeY,  0.0f);
        glVertex3f(m_sizeX, m_sizeY,  0.0f);
        glVertex3f(m_sizeX, m_sizeY, m_sizeZ);
        glVertex3f(0.0f, m_sizeY, m_sizeZ);
    
        // Front face  (z = 0.0f)
        glColor3f(1.0f, 0.0f, 0.0f);     // Red
        glVertex3f(0.0f,  0.0f, 0.0f);
        glVertex3f(m_sizeX,  0.0f, 0.0f);
        glVertex3f(m_sizeX, m_sizeY, 0.0f);
        glVertex3f(0.0f, m_sizeY, 0.0f);
    
        // Back face (z = m_sizeZ)
        glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
        glVertex3f(0.0f, m_sizeY, m_sizeZ);
        glVertex3f(m_sizeX, m_sizeY, m_sizeZ);
        glVertex3f(m_sizeX, 0.0f, m_sizeZ);
        glVertex3f(0.0f, 0.0f, m_sizeZ);
    
        // Left face (x = -1.0f)
        glColor3f(0.0f, 0.0f, 1.0f);     // Blue
        glVertex3f(m_sizeX, 0.0f, 0.0f);
        glVertex3f(m_sizeX, 0.0f, m_sizeZ);
        glVertex3f(m_sizeX, m_sizeY, m_sizeZ);
        glVertex3f(m_sizeX, m_sizeY,  0.0f);
    
        // Right face (x = 1.0f)
        glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
        glVertex3f(0.0f, 0.0f, m_sizeZ);
        glVertex3f(0.0f, 0.0f,  0.0f);
        glVertex3f(0.0f, m_sizeY,  0.0f);
        glVertex3f(0.0f, m_sizeY, m_sizeZ);

    glEnd();
}

void Primitive::setColor(float r, float g, float b)
{
    m_colorR = r;
    m_colorG = g;
    m_colorB = b;
}

void Primitive::Grid()
{
    glColor3f(0, 0.2, 0.2);
    for (int i = 0; i < 10000; i+= 10)
    {
        glBegin(GL_LINES);
            glVertex3f(i, 0, 0);
            glVertex3f(i, 20000, 0);
        glEnd();
    }
    for (int i = 0; i < 10000; i+= 10)
    {
        glBegin(GL_LINES);
            glVertex3f(0, i, 0);
            glVertex3f(20000, i, 0);
        glEnd();
    }
}

void Primitive::Line()
{
    glColor3f(255, 255, 255);

    glBegin(GL_LINES);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(m_sizeX, m_sizeY, m_sizeZ);
    glEnd();
}

void Primitive::setVelocity(float x, float y, float z)
{
    m_velX = x;
    m_velY = y;
    m_velZ = z;
}

void Primitive::Triangle()
{
    glBegin(GL_POLYGON);
        glColor3f(m_colorR, m_colorG, m_colorB);
        glVertex3f(0.0f, 0.0f, 0.0); 
        glVertex3f((m_sizeX/2.0f), m_sizeY, 0.0); 
        glVertex3f(m_sizeX, 0.0f, 0.0); 
    glEnd();
}

void Primitive::draw(void (Primitive::*function)())
{
    glPushMatrix();
        glColor3f(m_colorR, m_colorG, m_colorB);
        glTranslatef(m_posX, m_posY, m_posZ);
        (this->*function)();
    glPopMatrix();

    m_posX += m_velX;
    m_posY += m_velY;
    m_posZ += m_velZ;
}

void Primitive::keyboard(unsigned char key, int mouseX, int mouseY)
{
    m_velX = 0;
    switch (key)
    {
    case 'w':
        m_velX = 0.2;
        break;
    case 's':
        m_velX = -0.2;
        break;
    
    default:
        break;
    }
}


Primitive::Primitive(float posX, float posY, float sizeX, float sizeY)
{
    m_posX = posX;
    m_posY = posY;
    m_sizeX = sizeX;
    m_sizeY = sizeY;
    m_velX = m_velY = m_velZ = 0;
    m_title = reinterpret_cast<const unsigned char *>("Default title");
}

Primitive::Primitive(float posX, float posY, float posZ, float sizeX, float sizeY, float sizeZ)
{
    m_posX = posX;
    m_posY = posY;
    m_posZ = posZ;
    m_sizeX = sizeX;
    m_sizeY = sizeY;
    m_sizeZ = sizeZ;
    m_velX = m_velY = m_velZ = 0;
    m_title = reinterpret_cast<const unsigned char *>("Default title");
}

Primitive::Primitive(float posX, float posY, float posZ)
{
    m_posX = posX;
    m_posY = posY;
    m_posZ = posZ;
    m_velX = m_velY = m_velZ = 0;
    m_title = reinterpret_cast<const unsigned char *>("Default title");
}