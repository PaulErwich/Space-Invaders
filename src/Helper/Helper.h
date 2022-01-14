//
// Created by MLG Erwich on 14/01/2022.
//

#include <SFML/Graphics.hpp>

#ifndef SPACE_INVADERS_HELPER_H
#define SPACE_INVADERS_HELPER_H

class Helper
{
 public:
  static void SFMLText(sf::Text& text, const std::string& string, sf::Font& font, int char_size, sf::Color color, float x, float y);
};

#endif // SPACE_INVADERS_HELPER_H
