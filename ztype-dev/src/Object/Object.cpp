#include "../Primitive/Primitive.h"
#include "Object.h"
#include <string>

using namespace std;

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

bool Object::keyboard(unsigned char key, int mouseX, int mouseY)
{
    return m_text->keyboard(key, mouseX, mouseY);
}

Object::Object(float posX, float posY, float sizeX, float sizeY)
{
    m_primitive = new Primitive(posX, posY, sizeX, sizeY);
    m_text = new Text(posX, posY, 0.0f, *new string("default"));
}

Object::Object(float posX, float posY, float posZ)
{
    m_primitive = new Primitive(posX, posY, posZ);
    m_text = new Text(posX, posY, posZ, *new string("default"));
}

Object::Object(float posX, float posY, float posZ, float sizeX, float sizeY, float sizeZ)
{
    m_primitive = new Primitive(posX, posY, posZ, sizeX, sizeY, sizeZ);
    m_text = new Text(posX, posY, 0.0f, *new string("default"));
}

Object::Object(float posX, float posY, float posZ, string text)
{
    m_text = new Text(posX, posY, posZ, text);
}

bool Object::checkKey(char key)
{
    return m_text->checkKey(key);
}