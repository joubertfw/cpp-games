#include <GL/freeglut.h>
#include "Game.h"
#include "../Object/Object.h"
#include "../Primitive/Primitive.h"
#include "../Text/Text.h"
#include <vector>

Object *obj = new Object(100.0f, 100.0f, 0.0f, 100.0f, 100.0f, 100.0f);
Object *cube = new Object(500.0f, 500.0f, 0.0f, 100.0f, 100.0f, 100.0f);
Object *text = new Object(200, 200, 100.0f);
Object *text2 = new Object(200, 200, 100.0f);
Object *grid = new Object(0, 0, 0);

std::vector<Object> texts;

Game *instance;


#pragma region Defines

  #define WIN_SIZE_X 1920
  #define WIN_SIZE_Y 1080
  #define WIN_INI_SIZE_X 0
  #define WIN_INI_SIZE_Y 0
  #define WIN_Z_RANGE_MAX 1000
  #define WIN_Z_RANGE_MIN -1000
  #define WIN_NAME "ztype-dev"

#pragma endregion

Game::Game()
{
  glutInitWindowSize(WIN_SIZE_X, WIN_SIZE_Y);
  this->windowId = glutCreateWindow(WIN_NAME);
  glOrtho(WIN_INI_SIZE_X, WIN_SIZE_X, WIN_INI_SIZE_Y, WIN_SIZE_Y, WIN_Z_RANGE_MIN, WIN_Z_RANGE_MAX);
  glutFullScreen();  


  glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
  glClearDepth(1000.0f);                   // Set background depth to farthest
  glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
  glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
  glShadeModel(GL_SMOOTH);   // Enable smooth shading
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
  glutDisplayFunc(Game::Draw);
  glutKeyboardFunc(Game::Keyboard);

  this->AllocateTexts();

  instance = this;

  glutMainLoop();
}

Game::Game(int winSizeX, int winSizeY)
{
  glutInitWindowSize(winSizeX, winSizeY);
  this->windowId = glutCreateWindow(WIN_NAME);
  glOrtho(WIN_INI_SIZE_X, winSizeX, winSizeY, WIN_INI_SIZE_Y, -1000.0, 1000.0);
  glutFullScreen();

  glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
  glClearDepth(1000.0f);                   // Set background depth to farthest
  glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
  glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
  glShadeModel(GL_SMOOTH);   // Enable smooth shading
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
  glutDisplayFunc(Game::Draw);
  glutKeyboardFunc(Game::Keyboard);

  this->AllocateTexts();

  instance = this;

}

void Game::Render()
{
  glutMainLoop();
}

void Game::Draw()
{

  obj->setColor(130.0f, 0.0f, 0.0f);
  // glClearColor(0.0, 0.0, 0.0, 1);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);

  glPushMatrix();
    grid->draw(&Primitive::Grid);
    // cube->draw(&Primitive::Cube);
    // obj->draw(&Primitive::Triangle);
    // text->draw(&Text::BasicText);
    // text2->draw(&Text::BasicText);

    for (auto vtext = texts.begin(); vtext != texts.end(); ++vtext)
    {
      vtext->draw(&Text::BasicText);
    }

  glPopMatrix();

  glutSwapBuffers();
  glutPostRedisplay();

  glFlush();
};

void Game::Keyboard(unsigned char key, int mouseX, int mouseY)
{
  if(texts.front().keyboard(key, mouseX, mouseY))
  {
    texts.erase(texts.begin());
  }

  glutPostRedisplay();
}


void Game::AllocateTexts()
{
  texts.push_back(*new Object(200, 0, 0, "EXAMPLE"));
  texts.push_back(*new Object(400, -100, 0, "TEXT"));
  texts.push_back(*new Object(600, -200, 0, "TESTING"));
  texts.push_back(*new Object(800, -300, 0, "HELLO WORLD"));
  texts.push_back(*new Object(800, 0, 0, "HI THERE"));
  texts.push_back(*new Object(600, -100, 0, "SUP BRO"));
}