//
// Created by MLG Erwich on 14/01/2022.
//

#include "Player.h"

Player::Player(sf::RenderWindow& game_window) : window(game_window)
{
  init();

  for (int i = 0; i < MAX_BULLETS; i++)
  {
    projectiles[i] = nullptr;
  }
}

Player::~Player()
{
  for (int i = 0; i < MAX_BULLETS; i++)
  {
    delete projectiles[i];
  }
}

bool Player::init()
{
  if (!texture.loadFromFile("Data/Images/Player_Ship.png"))
  {
    std::cout << "Player didn't load" << std::endl;
    return false;
  }

  sprite.setTexture(texture);
  sprite.scale(0.5, 0.5);
  sprite.setPosition(window.getSize().x / 2 - sprite.getGlobalBounds().width / 2, window.getSize().y / 4 + window.getSize().y / 2);

  return true;
}

void Player::bulletShipCollision(ShipBasic& collider)
{
  for (int i = 0; i < MAX_BULLETS; i++)
  {

  }
}

void Player::input(sf::Event event)
{
  // && fire_timer.getElapsedTime().asSeconds() >= 1
  if (event.key.code == sf::Keyboard::Space)
  {
    projectile.enqueue(new Projectile(window, sprite.getPosition().x, sprite.getPosition().y));
    fire_timer.restart();
  }
}

void Player::update(float dt, ShipBasic &collider)
{
  for (int i = 0; i < MAX_BULLETS; i++)
  {
    projectiles[i] = projectile.getElement(i);
  }

  if (!projectile.isEmpty())
  {

    for (int i = 0; i < MAX_BULLETS; i++)
    {
      if (projectiles[i] != nullptr)
      {
        projectiles[i]->update(dt);

        if (projectiles[i]->getSprite().getPosition().x < collider.sprite.getPosition().x + collider.sprite.getGlobalBounds().width &&
            projectiles[i]->getSprite().getPosition().x + projectiles[i]->getSprite().getGlobalBounds().width > collider.sprite.getPosition().x &&
            projectiles[i]->getSprite().getPosition().y < collider.sprite.getPosition().y + collider.sprite.getGlobalBounds().height &&
            projectiles[i]->getSprite().getPosition().y + projectiles[i]->getSprite().getGlobalBounds().height > collider.sprite.getPosition().y)
        {
          std::cout << "WOOOOOOOOO" << std::endl;
          projectile.dequeue();
        }
        if (projectiles[i]->getSprite().getPosition().y < 0)
        {
          projectile.dequeue();
        }
      }
    }
  }
}

void Player::render()
{
  window.draw(sprite);

  if (!projectile.isEmpty())
  {
    for (int i = 0; i < MAX_BULLETS; i++)
    {
      if (projectiles[i] != nullptr)
      {
        projectiles[i]->render();
      }
    }
  }

}
