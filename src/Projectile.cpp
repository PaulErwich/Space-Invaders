//
// Created by MLG Erwich on 14/01/2022.
//

#include "Projectile.h"

Projectile::Projectile(sf::RenderWindow& game_window, float x, float y) : window(game_window)
{
  number_of_projectiles++;
  projectile_number = number_of_projectiles;
  init(x, y);
}

Projectile::~Projectile()
{
  number_of_projectiles--;
}

bool Projectile::init(float x, float y)
{
  if (!texture.loadFromFile("Data/Images/Projectile.png"))
  {
    std::cout << "Failed to load projectile" << std::endl;
    return false;
  }
  sprite.setTexture(texture);
  sprite.rotate(-90);
  sprite.setScale(0.02, 0.02);
  sprite.setPosition(x - sprite.getGlobalBounds().width / 2, y + sprite.getGlobalBounds().height);

  return true;
}

int Projectile::getNumberOfProjectiles()
{
  return number_of_projectiles;
}

sf::Sprite Projectile::getSprite()
{
  return sprite;
}

void Projectile::update(float dt)
{
  //std::cout << sprite.getPosition().y << " " << projectile_number << std::endl;
  sprite.move(0, -100 * dt);
}

void Projectile::render()
{
  window.draw(sprite);
}