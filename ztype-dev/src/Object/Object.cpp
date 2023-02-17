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

void Object::keyboard(unsigned char key, int mouseX, int mouseY)
{
    m_text->keyboard(key, mouseX, mouseY);
}

Object::Object(float posX, float posY, float sizeX, float sizeY)
{
    m_primitive = new Primitive(posX, posY, sizeX, sizeY);
    m_text = new Text(posX, posY, 0.0f, "default1");
}

Object::Object(float posX, float posY, float posZ)
{
    m_primitive = new Primitive(posX, posY, posZ);
    m_text = new Text(posX, posY, posZ, "default2");
}

Object::Object(float posX, float posY, float posZ, float sizeX, float sizeY, float sizeZ)
{
    m_primitive = new Primitive(posX, posY, posZ, sizeX, sizeY, sizeZ);
    m_text = new Text(posX, posY, 0.0f, "default3");
}