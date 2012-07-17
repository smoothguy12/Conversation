#include "text.hxx"
#include "fontmanager.hxx"
#include <SFML/Graphics/Font.hpp>

namespace GUI
{
  Text::Text(std::string text, Text::Type type, sf::Vector2f pos)
  {
    m_text = new sf::Text();

    if (type == Text::Section)      this->buildSection();
    else if (type == Text::Title)   this->buildTitle();
    else if (type == Text::Legend)  this->buildLegend();
    else                            this->buildStandard();

    m_text->setString(text);
    m_text->move(pos);
  }



  Text::~Text()
  {
    delete m_text;
  }



  void Text::buildStandard()
  {
    Core::FontManager* fm;

    fm = Core::FontManager::getInstance();

    m_text->setFont( fm->get(GUI::Font::Standard) );
    m_text->setColor(sf::Color::White);
    m_text->setStyle(sf::Text::Regular);
    m_text->setCharacterSize(24);
  }



  void Text::buildSection()
  {
    Core::FontManager* fm;

    fm = Core::FontManager::getInstance();
    this->buildStandard();
    m_text->setFont( fm->get(GUI::Font::Title) );
    m_text->setCharacterSize(30);
    m_text->setStyle(sf::Text::Bold);
  }



  void Text::buildTitle()
  {
    this->buildSection();
    m_text->setCharacterSize(60);
  }



  void Text::buildLegend()
  {
    this->buildStandard();
    m_text->setCharacterSize(20);
    m_text->setStyle(sf::Text::Italic);
  }



  sf::Text* Text::get()
  {
    return m_text;
  }



  sf::Drawable* Text::getDrawable()
  {
    return static_cast<sf::Drawable*>(m_text);
  }
}
