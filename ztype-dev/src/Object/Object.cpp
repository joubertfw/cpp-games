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
/*Set velocity of object.
x: velocity on x axis
y: velocity on y axis
z: velocity on z axis
*/
void Object::setVelocity(float x, float y, float z)
{
    m_primitive->setVelocity(x, y, z);
    m_text->setVelocity(x, y, z);
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
    m_primitive = new Primitive(posX, posY, posZ);
    m_text = new Text(posX, posY, posZ, text);
}

bool Object::checkKey(char key)
{
    return m_text->checkKey(key);
}

bool Object::operator<(const Object& b) 
{

    return b.m_text->m_posY < this->m_text->m_posY;
}