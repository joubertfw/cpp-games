#pragma once

class Primitive
{
    void Quad(float xScale, float yScale, float xOfsset, float yOfsset, float initialColor, float endColor);
    void Quad(float xScale, float yScale, float xOfsset, float yOfsset);
    void Trapeze(float xScale, float yScale, float xOfsset, float yOfsset, float initialColor, float endColor, float angulation);
    void Triangle(float xScale, float yScale, float xOfsset, float yOfsset, float initialColor, float endColor);
    void Line(float xScale, float xOfsset, float yOfsset, float initialColor, float endColor);
    void Triangle(float xScale, float yScale, float xOfsset, float yOfsset);
};
