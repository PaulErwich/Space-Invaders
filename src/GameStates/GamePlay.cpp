#include "GamePlay.h"

GamePlay::GamePlay(STATE state_id, sf::RenderWindow& game_window) :
  GameStateBase(state_id, game_window)
{
  player = new Player(game_window);
  ship = new ShipBasic(game_window);
}

GamePlay::~GamePlay() {}

STATE GamePlay::input(sf::Event event)
{
  player->input(event);
  return game_state_id;
}

STATE GamePlay::update(float dt)
{
  player->update(dt, *ship);
  ship->update(dt);
  return game_state_id;
}

void GamePlay::render()
{
  player->render();
  ship->render();
}
