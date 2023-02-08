#pragma once
#include <vector>

using namespace std;

class Render
{
    public:
        vector<int> Objects;
        static void Draw();
        static void Keyboard(unsigned char key, int mouseX, int mouseY);
        Render();
};
