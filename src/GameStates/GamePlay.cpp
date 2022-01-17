#include "GamePlay.h"

GamePlay::GamePlay(STATE state_id, sf::RenderWindow& game_window) :
  GameStateBase(state_id, game_window)
{
  player = new Player(game_window);
  //ship = new ShipBasic(game_window);
  wave_one = new Wave(game_window);

  for (int i = 0; i < MAX_BULLETS; i++)
  {
    projectiles[i] = nullptr;
  }
}

GamePlay::~GamePlay()
{
  delete player;
  delete wave_one;
  for (int i = 0; i < MAX_BULLETS; i++)
  {
    delete projectiles[i];
  }
}

void GamePlay::bulletShipCollision(ShipBasic &collider)
{
  for (int i = 0; i < MAX_BULLETS; i++)
  {
    if (projectiles[i] != nullptr)
    {
      if (
        projectiles[i]->getSprite().getPosition().x <
          collider.sprite.getPosition().x +
            collider.sprite.getGlobalBounds().width &&
        projectiles[i]->getSprite().getPosition().x +
            projectiles[i]->getSprite().getGlobalBounds().width >
          collider.sprite.getPosition().x &&
        projectiles[i]->getSprite().getPosition().y <
          collider.sprite.getPosition().y +
            collider.sprite.getGlobalBounds().height &&
        projectiles[i]->getSprite().getPosition().y +
            projectiles[i]->getSprite().getGlobalBounds().height >
          collider.sprite.getPosition().y)
      {
        std::cout << "removed " << i << std::endl;
        delete projectiles[i];
        projectiles[i] = nullptr;
      }
      else if (projectiles[i]->getSprite().getPosition().y < 0)
      {
        std::cout << "removed " << i << std::endl;
        delete projectiles[i];
        projectiles[i] = nullptr;
      }
    }
  }
}

void GamePlay::keyReleased(sf::Event event)
{
  player->keyReleased(event);
}

STATE GamePlay::input(sf::Event event)
{
  player->input(event);

  if (event.key.code == sf::Keyboard::Space && fire_timer.getElapsedTime().asSeconds() >= 1)
  {
    for (int i = 0; i < MAX_BULLETS; i++)
    {
      if (projectiles[i] == nullptr)
      {
        std::cout << "created " << i << std::endl;
        projectiles[i] = new Projectile(
          window,
          player->getSprite().getPosition().x +
            player->getSprite().getGlobalBounds().width / 2,
          player->getSprite().getPosition().y);
        fire_timer.restart();
        break;
      }
    }
  }
  return game_state_id;
}

STATE GamePlay::update(float dt)
{
  player->update(dt);
  wave_one->update(dt);

  for (int i = 0; i < MAX_BULLETS; i++)
  {
    if (projectiles[i] != nullptr)
    {
      projectiles[i]->update(dt);
    }
  }
  for (int i = 0; i < wave_one->getNumberOfShips(); i++)
  {
    bulletShipCollision(*wave_one->getShip(i));
  }

  return game_state_id;
}

void GamePlay::render()
{
  player->render();

  wave_one->render();
  for (int i = 0; i < MAX_BULLETS; i++)
  {
    if (projectiles[i] != nullptr)
    {
      projectiles[i]->render();
    }
  }
}
