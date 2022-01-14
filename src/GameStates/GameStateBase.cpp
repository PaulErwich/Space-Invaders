//
// Created by MLG Erwich on 14/01/2022.
//

#include "GameStateBase.h"
GameStateBase::GameStateBase(STATE state_id, sf::RenderWindow& game_window) : window(game_window)
{
  game_state_id = state_id;
}

GameStateBase::~GameStateBase()
{

}

STATE GameStateBase::getStateID() {return game_state_id;}

STATE GameStateBase::input(sf::Event event)
{
  return game_state_id;
}

STATE GameStateBase::update(float dt)
{
  return game_state_id;
}

void GameStateBase::render()
{

}
