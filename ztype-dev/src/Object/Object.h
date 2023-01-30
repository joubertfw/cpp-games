#pragma once
#include "../Primitive/Primitive.h"

class Object
{
    public:
        Primitive Object;
        void draw(int Primitive::*(float, float, float, float));
        void draw(int Primitive::*(float, float, float));
        bool setPosition(float, float);
        bool setSize(float, float);
    private:
        float m_posX, m_posY, m_sizeX, m_sizeY;
        float m_colorR, m_colorG, m_colorB;
};