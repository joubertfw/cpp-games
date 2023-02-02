#pragma once

class Primitive
{
    protected:

    public:
        void Quad();
        void Cube();        
        // void Quad(float xScale, float yScale, float xOfsset, float yOfsset, float initialColor, float endColor);
        void Trapeze(float xScale, float yScale, float xOfsset, float yOfsset, float initialColor, float endColor, float angulation);
        void Triangle(float xScale, float yScale, float xOfsset, float yOfsset, float initialColor, float endColor);
        void Line(float xScale, float xOfsset, float yOfsset, float initialColor, float endColor);
        void Triangle(float xScale, float yScale, float xOfsset, float yOfsset);

        void setColor(float, float, float);

        void draw(Primitive Primitive::*());

        Primitive(float, float, float, float);
        Primitive(float, float, float, float, float, float, float);
        Primitive(float, float, float, float, float, float);
        Primitive(float, float, float);
    private:
        float m_posX, m_posY, m_posZ, m_sizeX, m_sizeY, m_sizeZ;
        float m_colorR = 0.0f, m_colorG = 0.0f, m_colorB = 255.0f;
        void setQuad(float, float, float, float, float, float, int);
};
