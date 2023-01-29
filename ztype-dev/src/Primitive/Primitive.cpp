#include "Primitive.h"
#include "../Object/Object.h"
#include <GL/freeglut.h>

void Primitive::Quad(float xScale, float yScale, float xOfsset, float yOfsset, float initialColor, float endColor)
{
    glColor3f(initialColor, initialColor, initialColor);
    glVertex3f(-xScale + xOfsset, yScale + yOfsset, 0.0);
    glVertex3f(-xScale + xOfsset, -yScale + yOfsset, 0.0);
    glColor3f(endColor, endColor, endColor);
    glVertex3f(xScale + xOfsset, -yScale + yOfsset, 0.0);
    glVertex3f(xScale + xOfsset, yScale + yOfsset, 0.0); 
}

void Primitive::Quad(float xScale, float yScale, float xOfsset, float yOfsset)
{    
    glVertex3f(-xScale + xOfsset, yScale + yOfsset, 0.0);
    glVertex3f(-xScale + xOfsset, -yScale + yOfsset, 0.0); 
    glVertex3f(xScale + xOfsset, -yScale + yOfsset, 0.0);
    glVertex3f(xScale + xOfsset, yScale + yOfsset, 0.0); 
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
