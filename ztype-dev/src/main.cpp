#include <stdlib.h>
#include <stdio.h>
#include <GL/freeglut.h>
#include "Game/Game.h"

#pragma region Defines

  #define WIN_SIZE_X 800
  #define WIN_SIZE_Y 800

#pragma endregion



int main(int argc, char** argv)
{
  Game *game;
  Game *game2;
  glutInit(&argc, argv);

  game = new Game(WIN_SIZE_X, WIN_SIZE_Y);
  // game2 = new Game(WIN_SIZE_X, WIN_SIZE_Y);

  game->Render();
  // game2->Render();

  return EXIT_SUCCESS;
}
