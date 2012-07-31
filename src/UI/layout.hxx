#ifndef LAYOUT_HXX
#define LAYOUT_HXX
#include "Core/singleton.hxx"
#include "Core/mapreader.hxx"
#include <string>
#include "widget.hxx"
#include <map>
#include <SFML/Graphics/Color.hpp>

namespace UI
{
  class Layout : public Core::Singleton<Layout>
  {
  public:
    friend class Core::Singleton<Layout>;
    void loadColors(std::string fileName);

    const sf::Color& getColor(std::string name);

  protected:
    Layout();
    ~Layout();

    bool                              m_has_colors;
    bool                              m_initialized;
    std::map<std::string, sf::Color>  m_colors;
  };
}

#endif // LAYOUT_HXX
