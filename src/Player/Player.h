//
// Created by MLG Erwich on 14/01/2022.
//

#include <SFML/Graphics.hpp>

#ifndef SPACE_INVADERS_PLAYER_H
#define SPACE_INVADERS_PLAYER_H

class Player
{
 public:
  Player(sf::RenderWindow& game_window);
  ~Player();
  void input(sf::Event event);
  void update(float dt);
  void render();
 private:
  sf::RenderWindow &window;
  sf::Texture texture;
  sf::Sprite sprite;
  int movement;
  const int SPEED = 300;

};

#endif // SPACE_INVADERS_PLAYER_H
