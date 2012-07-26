#include "text.hxx"
#include "fontmanager.hxx"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <iostream>
#include "window.hxx"

namespace UI
{
  Text::Text(std::string text, Text::Type type)
  {
    m_text = new sf::Text(text);
    m_rt    = new sf::RenderTexture();

    switch (type)
      {
      case Text::Section: this->buildSection();   break;
      case Text::Title:   this->buildTitle();     break;
      case Text::Legend:  this->buildLegend();    break;
      default:            this->buildStandard();  break;
      }

    m_rt->create(m_text->getGlobalBounds().left + m_text->getGlobalBounds().width,
                 m_text->getGlobalBounds().top + m_text->getGlobalBounds().height);

    this->updateTexture();
  }



  Text::~Text()
  {
    delete m_text;
    delete m_rt;
  }



  void Text::buildStandard()
  {
    Core::FontManager* fm;

    fm = Core::FontManager::getInstance();

    m_text->setFont( fm->get(UI::Font::Standard) );
    m_text->setCharacterSize(24);
    m_text->setStyle(sf::Text::Regular);
    m_text->setColor(sf::Color::White);
  }



  void Text::buildSection()
  {
    Core::FontManager* fm;

    fm = Core::FontManager::getInstance();

    this->buildStandard();

    m_text->setFont( fm->get(UI::Font::Title) );
    m_text->setCharacterSize(30);
    m_text->setStyle(sf::Text::Bold);
    m_text->setColor(sf::Color::Red);
  }



  void Text::buildTitle()
  {
    this->buildSection();

    m_text->setCharacterSize(60);
    m_text->setColor(sf::Color(255, 127, 0));
  }



  void Text::buildLegend()
  {
    this->buildStandard();

    m_text->setCharacterSize(20);
    m_text->setStyle(sf::Text::Italic);
    m_text->setColor(sf::Color(127, 127, 127));
  }



  void Text::updateTexture()
  {
    m_rt->clear(sf::Color::Transparent);
    m_rt->draw(*m_text);
    m_rt->display();
  }
}
