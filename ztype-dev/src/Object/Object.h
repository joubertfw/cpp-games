#pragma once
#include "../Primitive/Primitive.h"

class Object
{
    public:
        void draw(void (Primitive::*)());
        bool setPosition(float, float);
        bool setSize(float, float);

        Object(float, float, float, float);
        Object(float, float, float, float, float, float);
        Object(float, float, float, float, float, float, float);
        Object(float, float, float);
        
    private:
        Primitive *m_primitive;
        float m_posX, m_posY, m_sizeX, m_sizeY;
        float m_colorR, m_colorG, m_colorB;
};