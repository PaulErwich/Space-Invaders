//
// Created by MLG Erwich on 14/01/2022.
//
#include <SFML/Graphics.hpp>

#ifndef SPACE_INVADERS_GAMESTATEBASE_H
#define SPACE_INVADERS_GAMESTATEBASE_H

enum class STATE {GAME_UNKNOWN = -1, GAME_EXIT = 0, GAME_MENU = 1, GAME_PLAY = 2, GAME_OVER = 3};

class GameStateBase
{
 public:
  GameStateBase(STATE state_id, sf::RenderWindow &game_window);
  ~GameStateBase();
  STATE getStateID();
  virtual STATE input(sf::Event event);
  virtual STATE update(float dt);
  virtual void render();
 protected:
  STATE game_state_id;
  sf::RenderWindow &window;


};


#endif //SPACE_INVADERS_GAMESTATEBASE_H
