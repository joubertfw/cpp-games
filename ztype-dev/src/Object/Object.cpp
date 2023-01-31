#include "../Primitive/Primitive.h"
#include "Object.h"

void Object::draw(void (Primitive::*function)())
{
    (m_primitive->*function)();
}

Object::Object(float posX, float posY, float sizeX, float sizeY)
{
    m_primitive = new Primitive(posX, posY, sizeX, sizeY);
}