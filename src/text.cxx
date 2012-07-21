#include "text.hxx"
#include "fontmanager.hxx"
#include <SFML/Graphics/Font.hpp>

namespace UI
{
  Text::Text(std::string text, Text::Type type, sf::Vector2f pos)
  {
    m_text = new sf::Text();

    switch (type)
      {
      case Text::Section: this->buildSection();   break;
      case Text::Title:   this->buildTitle();     break;
      case Text::Legend:  this->buildLegend();    break;
      default:            this->buildStandard();  break;
      }

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

    m_text->setFont( fm->get(UI::Font::Standard) );
    m_text->setColor(sf::Color::White);
    m_text->setStyle(sf::Text::Regular);
    m_text->setCharacterSize(24);
  }



  void Text::buildSection()
  {
    Core::FontManager* fm;

    fm = Core::FontManager::getInstance();
    this->buildStandard();
    m_text->setFont( fm->get(UI::Font::Title) );
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



  sf::Vector2u Text::getSize()
  {
    sf::FloatRect rect;
    sf::Vector2u  size;

    rect    = m_text->getGlobalBounds();
    size.x  = (rect.left + rect.width);
    size.y  = (rect.top + rect.height);

    return size;
  }



  void Text::move(float x, float y)
  {
    m_text->move(sf::Vector2f(x, y));
  }
}
