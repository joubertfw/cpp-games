#include <stdlib.h>
#include <stdio.h>
#include <GL/freeglut.h>
#include "Render/Render.h"

#pragma region Defines

  #define WIN_SIZE_X 1920
  #define WIN_SIZE_Y 1080
  #define WIN_INI_SIZE_X 0
  #define WIN_INI_SIZE_Y 0
  #define WIN_NAME "ztype-dev"

#pragma endregion



int main(int argc, char** argv)
{
  Render *render;
  glutInit(&argc, argv);

  render = new Render();

  return EXIT_SUCCESS;
}