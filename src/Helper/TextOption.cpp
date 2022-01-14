//
// Created by MLG Erwich on 14/01/2022.
//

#include "TextOption.h"

TextOption::TextOption(const std::string& string, sf::Font& font, int char_size, float x, float y, bool selection)
{
  selected = selection;
  Helper::SFMLText(text, string, font, char_size, col_default, x, y);
}

sf::Text TextOption::getText() {return text;}

void TextOption::setSelected(bool select) {selected = select;}

void TextOption::update()
{
  if (selected)
  {
    text.setFillColor(col_selected);
  }
  else
  {
    text.setFillColor(col_default);
  }
}