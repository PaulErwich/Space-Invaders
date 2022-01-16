//
// Created by MLG Erwich on 14/01/2022.
//

#include <SFML/Graphics.hpp>
#include <iostream>

#ifndef SPACE_INVADERS_PROJECTILE_H
#define SPACE_INVADERS_PROJECTILE_H

class Projectile
{
 public:
  Projectile(sf::RenderWindow& game_window, float x, float y);
  ~Projectile();
  static int getNumberOfProjectiles();
  sf::Sprite getSprite();
  void update(float dt);
  void render();

 private:
  bool init(float x, float y);
  sf::RenderWindow& window;
  sf::Texture texture;
  sf::Sprite sprite;
  static int number_of_projectiles;
  int projectile_number;
};

#endif // SPACE_INVADERS_PROJECTILE_H
