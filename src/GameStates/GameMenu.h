//
// Created by MLG Erwich on 14/01/2022.
//

#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameStateBase.h"


#ifndef SPACE_INVADERS_GAMEMENU_H
#define SPACE_INVADERS_GAMEMENU_H

class GameMenu : public GameStateBase
{
 public:
  GameMenu(STATE stateId, sf::RenderWindow& game_window);
  ~GameMenu();
  STATE input(sf::Event event) override;
  STATE update(float dt) override;
  void render() override;

 private:
  sf::Font font;
  sf::Text text;
  bool init();
};

#endif // SPACE_INVADERS_GAMEMENU_H
