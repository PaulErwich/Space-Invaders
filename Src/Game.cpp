//
// Created by MLG Erwich on 14/01/2022.
//

#include "Game.h"

Game::Game(sf::RenderWindow &game_window) : window(game_window)
{

}

Game::~Game() {

}

bool Game::init()
{
    if (!font.loadFromFile("Data/Font/OpenSans-Bold.ttf"))
    {
        cout << "Failed to load font" << endl;
        return false;
    }

    text.setFont(font);
    text.setString("Space Invaders");
    text.setFillColor(sf::Color::White);
    return true;
}

void Game::input(sf::Event event)
{

}

void Game::update(float dt) {

}

void Game::render()
{
    window.draw(text);
}

