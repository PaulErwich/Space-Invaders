//
// Created by MLG Erwich on 14/01/2022.
//

#include <SFML/Graphics.hpp>
#include <iostream>

#ifndef SPACE_INVADERS_SHIPBASIC_H
#define SPACE_INVADERS_SHIPBASIC_H

class ShipBasic
{
 public:
  ShipBasic(sf::RenderWindow& game_window);
  ~ShipBasic();
  void update(float dt);
  void render();
  sf::Sprite sprite;
 private:
  bool init();
  sf::RenderWindow &window;
  sf::Texture texture;

  int movement;
  const int SPEED = 150;
};

#endif // SPACE_INVADERS_SHIPBASIC_H
