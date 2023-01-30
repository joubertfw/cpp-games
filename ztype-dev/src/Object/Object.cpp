#include "../Primitive/Primitive.h"
#include "Object.h"

void Object::draw(int Primitive::*function(float x, float y, float xs, float ys))
{
    function(this->m_posX, this->m_posY, this->m_sizeX, this->m_sizeY);
}

void Object::draw(int Primitive::*function(float x, float y, float xs))
{
    function(this->m_posX, this->m_posY, this->m_sizeX);
} 

