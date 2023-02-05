#pragma once

class Text
{
    protected:

    public:
        void BasicText();

        void setColor(float, float, float);

        void draw(void (Text::*function)());
        Text (float, float, float, char*);
    private:
        float m_posX, m_posY, m_posZ, m_sizeX, m_sizeY, m_sizeZ;
        float m_colorR = 0.0f, m_colorG = 0.0f, m_colorB = 255.0f;
        const unsigned char* m_title; 
};
