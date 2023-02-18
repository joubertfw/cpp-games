#pragma once
#include <vector>

using namespace std;

class Game
{
    public:
        vector<int> Objects;
        static void Draw();
        static void Keyboard(unsigned char, int, int);
        void AllocateTexts();
        void Render();
        Game();
        int windowId;
        Game(int, int);
};
