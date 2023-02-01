#include "Primitive.h"
#include "../Object/Object.h"
#include "../Render/Render.h"
#include <GL/freeglut.h>

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

void Primitive::setQuad(float posX, float posY, float posZ, float sizeX, float sizeY, float sizeZ)
{
    glBegin(GL_POLYGON);
        glColor3f(m_colorR, m_colorG, m_colorB);
        glVertex3f(posX, posY, posZ);
        glVertex3f(posX + sizeX, posY, posZ);
        glVertex3f(posX + sizeX, posY + sizeY, posZ);

        glVertex3f(posX, posY + sizeY, 0.0);
    glEnd();
}

void Primitive::Cube()
{

}

void Primitive::setColor(float r, float g, float b)
{
    m_colorR = r;
    m_colorG = g;
    m_colorB = b;
}

void Primitive::Line(float xScale, float xOfsset, float yOfsset, float initialColor, float endColor)
{
    float yScale = 1.0;
    glColor3f(initialColor, initialColor, initialColor);
    glVertex3f(-xScale + xOfsset, yScale + yOfsset, 0.0);
    glVertex3f(-xScale + xOfsset, -yScale + yOfsset, 0.0);
    glColor3f(endColor, endColor, endColor);
    glVertex3f(xScale + xOfsset, -yScale + yOfsset, 0.0);
    glVertex3f(xScale + xOfsset, yScale + yOfsset, 0.0); 
}

void Primitive::Triangle(float xScale, float yScale, float xOfsset, float yOfsset, float initialColor, float endColor)
{
    glColor3f(initialColor, initialColor, initialColor);
    glVertex3f(xScale + xOfsset, -yScale + yOfsset, 0.0); 
    glColor3f(endColor, endColor, endColor);
    glVertex3f(-xScale + xOfsset, -yScale + yOfsset, 0.0); 
    glVertex3f(-xScale + xOfsset, yScale + yOfsset, 0.0); 
}

void Primitive::Triangle(float xScale, float yScale, float xOfsset, float yOfsset)
{
    glVertex3f(xScale + xOfsset, -yScale + yOfsset, 0.0); 
    glVertex3f(-xScale + xOfsset, -yScale + yOfsset, 0.0); 
    glVertex3f(-xScale + xOfsset, yScale + yOfsset, 0.0); 
}

void Primitive::Trapeze(float xScale, float yScale, float xOfsset, float yOfsset, float initialColor, float endColor, float angulation)
{
    glColor3f(initialColor, initialColor, initialColor);
    glVertex3f(-xScale + xOfsset + angulation, yScale + yOfsset, 0.0);
    glVertex3f(-xScale + xOfsset, -yScale + yOfsset, 0.0); 
    glColor3f(endColor, endColor, endColor);
    glVertex3f(xScale + xOfsset, -yScale + yOfsset, 0.0);
    glVertex3f(xScale + xOfsset - angulation, yScale + yOfsset, 0.0); 
}

void Primitive::draw(Primitive Primitive::*function())
{
    function();
}


Primitive::Primitive(float posX, float posY, float sizeX, float sizeY)
{
    m_posX = posX;
    m_posY = posY;
    m_sizeX = sizeX;
    m_sizeY = sizeY;
}

Primitive::Primitive(float posX, float posY, float posZ, float sizeX, float sizeY, float sizeZ)
{
    m_posX = posX;
    m_posY = posY;
    m_posZ = posZ;
    m_sizeX = sizeX;
    m_sizeY = sizeY;
    m_sizeZ = sizeZ;
}