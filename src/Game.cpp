//
// Created by MLG Erwich on 14/01/2022.
//

#include "Game.h"

Game::Game(sf::RenderWindow &game_window) : window(game_window)
{
  current_state = nullptr;
  game_menu = new GameMenu(STATE::GAME_MENU, game_window);
}

Game::~Game()
{
  delete game_menu;
}

void Game::input(sf::Event event)
{

}

void Game::update(float dt) {

}

void Game::render()
{
    game_menu->render();
}

