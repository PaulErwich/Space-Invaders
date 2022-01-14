#include "GamePlay.h"

GamePlay::GamePlay(STATE state_id, sf::RenderWindow& game_window) :
  GameStateBase(state_id, game_window)
{
}

GamePlay::~GamePlay() {}

STATE GamePlay::input(sf::Event event)
{
  return game_state_id;
}

STATE GamePlay::update(float dt)
{
  return game_state_id;
}

void GamePlay::render()
{
  GameStateBase::render();
}
