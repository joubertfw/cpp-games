#pragma once
#include "../Primitive/Primitive.h"

class Object
{
    public:
        Primitive Object;
        void Draw();
    private:
        int posX, posY, sizeX, sizeY, color;
};