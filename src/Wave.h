//
// Created by MLG Erwich on 14/01/2022.
//

#include <SFML/Graphics.hpp>
#include "Ships/ShipBasic.h"

#ifndef SPACE_INVADERS_WAVE_H
#define SPACE_INVADERS_WAVE_H

class Wave
{
 public:
  Wave(sf::RenderWindow &game_window);
  ~Wave();
  int getNumberOfShips();
  ShipBasic* getShip(int i);
  void update(float dt);
  void render();

 private:
  void init();
  sf::RenderWindow &window;
  static const int SHIPS_PER_WAVE = 9;
  ShipBasic *ship_basic[SHIPS_PER_WAVE];
  sf::Clock downward_timer;
  int horizontal_movement;
  int vertical_movement;

};

#endif // SPACE_INVADERS_WAVE_H
