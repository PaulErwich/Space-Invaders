//
// Created by MLG Erwich on 14/01/2022.
//

#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameStateBase.h"
#include "../Helper/Helper.h"
#include "../Helper/TextOption.h"


#ifndef SPACE_INVADERS_GAMEMENU_H
#define SPACE_INVADERS_GAMEMENU_H

enum class MENU_OPTION {PLAY = 1, EXIT = 2};

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
  TextOption* opt_play;
  TextOption* opt_exit;
  MENU_OPTION current_option;
  bool init();
};

#endif // SPACE_INVADERS_GAMEMENU_H
