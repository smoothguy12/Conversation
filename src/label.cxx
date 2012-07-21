#include "label.hxx"
#include "fontmanager.hxx"
#include <SFML/Graphics/Font.hpp>
#include <iostream>

namespace UI
{
  Label::Label(std::string text, Text::Type type)
  {
    m_rt    = new sf::RenderTexture();
    m_text  = new sf::Text();

    switch (type)
      {
      case Text::Section: this->buildSection();   break;
      case Text::Title:   this->buildTitle();     break;
      case Text::Legend:  this->buildLegend();    break;
      default:            this->buildStandard();  break;
      }

    m_text->setString(text);

    m_rt->create(m_text->getGlobalBounds().width, m_text->getGlobalBounds().height);
    m_rt->clear(sf::Color::Blue);
    m_rt->draw(*m_text);
    m_rt->display();

    m_sprite->setTexture(m_rt->getTexture());
    m_sprite->move(sf::Vector2f(0, 0));
  }



  Label::~Label()
  {
    delete m_text;
    delete m_rt;
  }


  /*
  void Label::move(float x, float y)
  {
    m_text->move(x, y);
  }



  void Label::move(sf::Vector2f coords)
  {
    m_text->move(coords);
  }



  sf::Drawable* Label::getDrawable()
  {
    return static_cast<sf::Drawable*>(m_text);
  }



  sf::Vector2u Label::getSize()
  {
    sf::FloatRect rect;
    sf::Vector2u  size;

    rect    = m_text->getGlobalBounds();
    size.x  = (rect.left + rect.width);
    size.y  = (rect.top + rect.height);

    return size;
  }
*/



  void Label::buildStandard()
  {
    Core::FontManager* fm;

    fm = Core::FontManager::getInstance();

    m_text->setFont( fm->get(UI::Font::Standard) );
    m_text->setColor(sf::Color::White);
    m_text->setStyle(sf::Text::Regular);
    m_text->setCharacterSize(24);
  }



  void Label::buildSection()
  {
    Core::FontManager* fm;

    fm = Core::FontManager::getInstance();
    this->buildStandard();
    m_text->setFont( fm->get(UI::Font::Title) );
    m_text->setCharacterSize(30);
    m_text->setStyle(sf::Text::Bold);
  }



  void Label::buildTitle()
  {
    this->buildSection();
    m_text->setCharacterSize(60);
  }



  void Label::buildLegend()
  {
    this->buildStandard();
    m_text->setCharacterSize(20);
    m_text->setStyle(sf::Text::Italic);
  }
}
