#include <stdlib.h>
#include <stdio.h>
#include <GL/freeglut.h>
#include "Game/Game.h"

#pragma region Defines

  #define WIN_SIZE_X 1920
  #define WIN_SIZE_Y 1080
  #define WIN_INI_SIZE_X 0
  #define WIN_INI_SIZE_Y 0
  #define WIN_NAME "ztype-dev"

#pragma endregion



int main(int argc, char** argv)
{
  Game *game;
  glutInit(&argc, argv);

  game = new Game(1200, 1200);

  return EXIT_SUCCESS;
}