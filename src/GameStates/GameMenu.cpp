//
// Created by MLG Erwich on 14/01/2022.
//

#include "GameMenu.h"
GameMenu::GameMenu(STATE stateId, sf::RenderWindow& game_window) :
  GameStateBase(stateId, game_window)
{
  init();
}
GameMenu::~GameMenu()
{

}

bool GameMenu::init()
{
  if (!font.loadFromFile("Data/Font/OpenSans-Bold.ttf"))
  {
    std::cout << "Font didn't load" << std::endl;
    return false;
  }

  text.setFont(font);
  text.setString("Space Invaders");
  text.setFillColor(sf::Color::White);

  return true;
}

STATE GameMenu::input(sf::Event event)
{
  return game_state_id;
}

STATE GameMenu::update(float dt)
{
  return game_state_id;
}

void GameMenu::render()
{
  window.draw(text);
}


