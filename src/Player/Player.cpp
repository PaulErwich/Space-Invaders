//
// Created by MLG Erwich on 14/01/2022.
//

#include "Player.h"

Player::Player(sf::RenderWindow& game_window) : window(game_window)
{
  init();
  movement = 0;


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

sf::Sprite Player::getSprite() {return sprite;}

void Player::keyReleased(sf::Event event)
{
  if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::D)
  {
    movement = 0;
  }
}

void Player::input(sf::Event event)
{
  //
  if (event.key.code == sf::Keyboard::A)
  {
    movement = -1;
  }
  if (event.key.code == sf::Keyboard::D)
  {
    movement = 1;
  }


    //projectile.enqueue(new Projectile(window, sprite.getPosition().x, sprite.getPosition().y));
}

void Player::update(float dt)
{
  /*
  for (int i = 0; i < MAX_BULLETS; i++)
  {
    projectiles[i] = projectile.getElement(i);
  }*/

//  if (!projectile.isEmpty())
  //{
  sprite.move(SPEED * movement * dt, 0);

  if (sprite.getPosition().x < 30)
  {
    movement = 0;
    sprite.setPosition(30, sprite.getPosition().y);
  }
  else if (sprite.getPosition().x + sprite.getGlobalBounds().width > window.getSize().x - 30)
  {
    movement = 0;
    sprite.setPosition(window.getSize().x - 30 - sprite.getGlobalBounds().width, sprite.getPosition().y);
  }


  //}
}

void Player::render()
{
  window.draw(sprite);

  //if (!projectile.isEmpty())
  //{
  /*
    for (int i = 0; i < MAX_BULLETS; i++)
    {
      if (projectiles[i] != nullptr)
      {
        projectiles[i]->render();
      }
    }*/
  //}

}
