#pragma once
#include "../Primitive/Primitive.h"
#include "../Text/Text.h"

class Object
{
    public:
        void draw(void (Primitive::*)());
        void draw(void (Text::*)());
        bool setPosition(float, float);
        bool setSize(float, float);
        void setColor(float, float, float);

        Object(float, float, float, float);
        Object(float, float, float, float, float, float);
        Object(float, float, float, float, float, float, float);
        Object(float, float, float);
        
    private:
        Primitive *m_primitive;
        Text *m_text;
        float m_posX, m_posY, m_sizeX, m_sizeY;
        float m_colorR, m_colorG, m_colorB;
};