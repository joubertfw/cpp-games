#include "../Primitive/Primitive.h"
#include "Object.h"

void Object::draw(void (Primitive::*function)())
{
    m_primitive->draw(function);
}

void Object::draw(void (Text::*function)())
{
    m_text->draw(function);
}

void Object::setColor(float r, float g, float b)
{
    m_primitive->setColor(r, g, b);
}

Object::Object(float posX, float posY, float sizeX, float sizeY)
{
    m_primitive = new Primitive(posX, posY, sizeX, sizeY);
    m_text = new Text(posX, posY, 0.0f, "Default text");
}

Object::Object(float posX, float posY, float posZ, float sizeX, float sizeY, float sizeZ)
{
    m_primitive = new Primitive(posX, posY, posZ, sizeX, sizeY, sizeZ);
    m_text = new Text(posX, posY, 0.0f, "Default text");
}