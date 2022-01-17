//
// Created by MLG Erwich on 14/01/2022.
//
#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameStateBase.h"
#include "../Player/Player.h"
#include "../Ships/ShipBasic.h"
#include "../Wave.h"

#ifndef SPACE_INVADERS_GAMEPLAY_H
#define SPACE_INVADERS_GAMEPLAY_H

class GamePlay : public GameStateBase
{
 public:
  GamePlay(STATE state_id, sf::RenderWindow &game_window);
  ~GamePlay();
  void bulletShipCollision(ShipBasic &collider);
  void keyReleased(sf::Event event);
  STATE input(sf::Event event) override;
  STATE update(float dt) override;
  void render() override;

 private:
  static const int MAX_BULLETS = 10;
  Player* player;
  sf::Clock fire_timer;
  Projectile *projectiles[MAX_BULLETS];
  //ShipBasic* ship;
  Wave *wave_one;
};

#endif // SPACE_INVADERS_GAMEPLAY_H
