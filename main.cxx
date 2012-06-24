#include <iostream>
#include "context.hxx"

using namespace std;

int main()
{
  Game::Context* context;

  context = new Game::Context();
  context->run();
  return 0;
}

