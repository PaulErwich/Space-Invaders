//
// Created by MLG Erwich on 14/01/2022.
//
#include <SFML/Graphics.hpp>
#include "GameStateBase.h"

#ifndef SPACE_INVADERS_GAMEPLAY_H
#define SPACE_INVADERS_GAMEPLAY_H

class GamePlay : public GameStateBase
{
 public:
  GamePlay(STATE state_id, sf::RenderWindow &game_window);
  ~GamePlay();
  STATE input(sf::Event event) override;
  STATE update(float dt) override;
  void render() override;

 private:

};

#endif // SPACE_INVADERS_GAMEPLAY_H
