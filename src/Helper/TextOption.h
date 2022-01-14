//
// Created by MLG Erwich on 14/01/2022.
//

#include <SFML/Graphics.hpp>
#include "Helper.h"

#ifndef SPACE_INVADERS_TEXTOPTION_H
#define SPACE_INVADERS_TEXTOPTION_H

class TextOption
{
 public:
  TextOption(const std::string& string, sf::Font& font, int char_size, float x, float y, bool selection);
  sf::Text getText();
  void setSelected(bool select);
  void update();
 private:
  bool selected;
  sf::Text text;
  const sf::Color col_default = sf::Color::White;
  const sf::Color col_selected = sf::Color::Red;
};

#endif // SPACE_INVADERS_TEXTOPTION_H
