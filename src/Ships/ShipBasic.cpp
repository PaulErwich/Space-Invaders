//
// Created by MLG Erwich on 14/01/2022.
//

#include "ShipBasic.h"

ShipBasic::ShipBasic(sf::RenderWindow& game_window, float x, float y) : window(game_window)
{
  init(x, y);
  movement = 1;
}

ShipBasic::~ShipBasic()
{

}

bool ShipBasic::init(float x, float y)
{
  if (!texture.loadFromFile("Data/Images/Alien_ship.png"))
  {
    std::cout << "Alien_ship didn't load" << std::endl;
  }

  sprite.setTexture(texture);
  sprite.scale(0.1, 0.1);
  sprite.setPosition(x * (window.getSize().x / 10) - sprite.getGlobalBounds().width / 2, y);
  return true;
}

void ShipBasic::update(float dt)
{
  /*
  sprite.move(movement * SPEED * dt, 0);

  if (sprite.getPosition().x < 0)
  {
    //sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y + sprite.getGlobalBounds().height/2);
    movement = 1;
  }
  else if (sprite.getPosition().x > window.getSize().x)
  {
    //sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y - sprite.getGlobalBounds().height/2);
    movement = -1;
  }*/
}

void ShipBasic::render()
{
  window.draw(sprite);
}