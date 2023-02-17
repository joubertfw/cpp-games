#pragma once

class Text
{
    protected:

    public:
        void BasicText();

        void setColor(float, float, float);

        void draw(void (Text::*function)());
        Text (float, float, float, const char*);
        void keyboard(unsigned char, int, int);

    private:
        float m_posX, m_posY, m_posZ, m_sizeX, m_sizeY, m_sizeZ;
        float m_colorR, m_colorG, m_colorB;
        float m_velX, m_velY, m_velZ;
        const unsigned char* m_title; 
        int m_textPos;
};
