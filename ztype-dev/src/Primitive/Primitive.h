#pragma once

class Primitive
{
    protected:

    public:
        void Quad();
        void Cube();
        void Triangle();
        void Grid();
        void Line();

        void setColor(float, float, float);

        void draw(void (Primitive::*function)());

        void keyboard(unsigned char, int, int);

        Primitive(float, float, float, float);
        Primitive(float, float, float, float, float, float, float);
        Primitive(float, float, float, float, float, float);
        Primitive(float, float, float);
        Primitive (float, float, float, char*);
    private:
        float m_posX, m_posY, m_posZ, m_sizeX, m_sizeY, m_sizeZ;
        float m_velX, m_velY, m_velZ;
        float m_colorR = 0.0f, m_colorG = 0.0f, m_colorB = 255.0f;
        const unsigned char* m_title; 
};
