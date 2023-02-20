#pragma once
#include "../Primitive/Primitive.h"
#include "../Text/Text.h"
#include <string>

using namespace std;

class Object
{
    public:
        void draw(void (Primitive::*)());
        void draw(void (Text::*)());
        bool setPosition(float, float);
        bool setSize(float, float);
        void setColor(float, float, float);
        bool checkKey(char key);

        bool keyboard(unsigned char, int, int);

        Object(float, float, float, float);
        Object(float, float, float, float, float, float);
        Object(float, float, float, string);
        Object(float, float, float, float, float, float, float);
        Object(float, float, float);
        float m_posX, m_posY, m_sizeX, m_sizeY;
        bool operator<(const Object& b);
        Text *m_text;
        void setVelocity(float, float, float);

    private:
        Primitive *m_primitive;
        float m_colorR, m_colorG, m_colorB;
};