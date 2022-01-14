//
// Created by MLG Erwich on 14/01/2022.
//

#include "GameMenu.h"
GameMenu::GameMenu(STATE stateId, sf::RenderWindow& game_window) :
  GameStateBase(stateId, game_window)
{
  init();
  current_option = MENU_OPTION::PLAY;
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

  Helper::SFMLText(text, "SPACE INVADERS", font, 40, sf::Color::White,
                   window.getSize().x / 2, window.getSize().y / 4);

  opt_play = new TextOption("PLAY", font, 40, window.getSize().x / 4,
                            window.getSize().y / 2, true);
  opt_exit = new TextOption("EXIT", font, 40, window.getSize().x / 4 + window.getSize().x / 2,
                            window.getSize().y / 2, false);

  return true;
}

STATE GameMenu::input(sf::Event event)
{
  if (event.key.code == sf::Keyboard::Right)
  {
    current_option = MENU_OPTION::EXIT;
    opt_play->setSelected(false);
    opt_exit->setSelected(true);
  }
  else if (event.key.code == sf::Keyboard::Left)
  {
    current_option = MENU_OPTION::PLAY;
    opt_play->setSelected(true);
    opt_exit->setSelected(false);
  }

  if (event.key.code == sf::Keyboard::Enter)
  {
    switch(current_option)
    {
      case MENU_OPTION::PLAY:
        return STATE::GAME_PLAY;
      case MENU_OPTION::EXIT:
        return STATE::GAME_EXIT;
    }
  }
  return game_state_id;
}

STATE GameMenu::update(float dt)
{
  opt_play->update();
  opt_exit->update();
  return game_state_id;
}

void GameMenu::render()
{
  window.draw(text);
  window.draw(opt_play->getText());
  window.draw(opt_exit->getText());
}


