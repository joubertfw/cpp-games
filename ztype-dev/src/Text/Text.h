#pragma once

class Text
{
    protected:

    public:
        void BasicText();

        void setColor(float, float, float);

        void draw(void (Text::*function)());
        Text (float, float, float, const char*);
    private:
        float m_posX, m_posY, m_posZ, m_sizeX, m_sizeY, m_sizeZ;
        float m_colorR = 255.0f, m_colorG = 255.0f, m_colorB = 255.0f;
        float m_velX, m_velY, m_velZ;
        const unsigned char* m_title; 
};
