//
// Created by MLG Erwich on 14/01/2022.
//

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "../Projectile.h"
#include "../Queue.h"
#include "../Ships/ShipBasic.h"

#ifndef SPACE_INVADERS_PLAYER_H
#define SPACE_INVADERS_PLAYER_H

//

class Player
{
 public:
  Player(sf::RenderWindow& game_window);
  ~Player();
  void bulletShipCollision(ShipBasic &collider);
  void input(sf::Event event);
  void update(float dt, ShipBasic &collider);
  void render();
 private:
  bool init();
  sf::RenderWindow &window;
  sf::Texture texture;
  sf::Sprite sprite;
  sf::Clock fire_timer;
  int movement;
  const int SPEED = 300;
  static const int MAX_BULLETS = 10;
  Projectile *projectiles[MAX_BULLETS];
  Queue projectile;
};

#endif // SPACE_INVADERS_PLAYER_H
