#include "Game.h"

Game::Game(sf::RenderWindow &game_window) : window(game_window)
{
  game_menu = new GameMenu(STATE::GAME_MENU, game_window);
  game_play = new GamePlay(STATE::GAME_PLAY, game_window);
  current_state = game_menu;
}

Game::~Game()
{
  delete game_menu;
  delete game_play;
}

void Game::stateChange(STATE state_id)
{
  switch(state_id)
  {
    case STATE::GAME_MENU:
      current_state = game_menu;
      break;
    case STATE::GAME_PLAY:
      current_state = game_play;
      break;
    case STATE::GAME_OVER:
      break;
    case STATE::GAME_EXIT:
      window.close();
    default:
      std::cout << "No state selected" << std::endl;
  }
}

void Game::input(sf::Event event)
{
  stateChange(current_state->input(event));
}

void Game::update(float dt)
{
  stateChange(current_state->update(dt));
}

void Game::render()
{
  current_state->render();
}

