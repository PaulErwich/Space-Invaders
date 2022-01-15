//
// Created by MLG Erwich on 14/01/2022.
//

#include "Player.h"

Player::Player(sf::RenderWindow& game_window) : window(game_window)
{
  init();
}

Player::~Player()
{

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

void Player::input(sf::Event event)
{
  if (event.key.code == sf::Keyboard::Space)
  {
    projectile[0] = new Projectile(window, sprite.getPosition().x, sprite.getPosition().y);
  }
}

void Player::update(float dt)
{

}

void Player::render()
{
  window.draw(sprite);
}
