#pragma once
#include <string>

using namespace std;

class Text
{
    protected:

    public:
        void BasicText();

        void setColor(float, float, float);
        void setVelocity(float, float, float);

        void draw(void (Text::*function)());
        Text (float, float, float, string);
        bool keyboard(unsigned char, int, int);
        bool checkKey(char key);
        string m_title; 

    // private:
        float m_posX, m_posY, m_posZ, m_sizeX, m_sizeY, m_sizeZ;
        float m_colorR, m_colorG, m_colorB;
        float m_velX, m_velY, m_velZ;
        int m_textPos;
};
