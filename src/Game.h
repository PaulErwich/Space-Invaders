//
// Created by MLG Erwich on 14/01/2022.
//
#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameStates/GameStateBase.h"
#include "GameStates/GameMenu.h"

using std::cout;
using std::endl;

#ifndef SPACE_INVADERS_GAME_H
#define SPACE_INVADERS_GAME_H


class Game
{
public:
    Game(sf::RenderWindow& game_window);
    ~Game();
    void input(sf::Event event);
    void update(float dt);
    void render();

private:
    sf::RenderWindow& window;
    GameStateBase *current_state;
    GameMenu *game_menu;

};


#endif //SPACE_INVADERS_GAME_H
