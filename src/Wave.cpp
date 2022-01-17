//
// Created by MLG Erwich on 14/01/2022.
//

#include "Wave.h"
Wave::Wave(sf::RenderWindow& game_window) : window(game_window)
{
  init();
  horizontal_movement = 1;
  vertical_movement = 0;
}

Wave::~Wave()
{
  for (int i = 0; i < SHIPS_PER_WAVE; i++)
  {
    delete ship_basic[i];
  }
}

void Wave::init()
{
  for (int i = 0; i < SHIPS_PER_WAVE; i++)
  {
    ship_basic[i] = new ShipBasic(window, 1 + i, window.getSize().y / 8);
  }
}

int Wave::getNumberOfShips() {return SHIPS_PER_WAVE;}

ShipBasic* Wave::getShip(int i)
{
  return ship_basic[i];
}

void Wave::update(float dt)
{
  if (ship_basic[0]->sprite.getPosition().x < 0 ||
      ship_basic[8]->sprite.getPosition().x + ship_basic[8]->sprite.getGlobalBounds().width > window.getSize().x)
  {
    horizontal_movement = -horizontal_movement;
  }

  for (int i = 0; i < SHIPS_PER_WAVE; i++)
  {
    ship_basic[i]->sprite.move(50 * dt * horizontal_movement, 50 * dt * vertical_movement);
  }
}

void Wave::render()
{
  for (int i = 0; i < SHIPS_PER_WAVE; i++)
  {
    ship_basic[i]->render();
  }
}

