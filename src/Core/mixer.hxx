#ifndef MIXER_HXX
#define MIXER_HXX
#include "singleton.hxx"
#include <vector>
#include <SFML/Audio/Music.hpp>

namespace Core
{
  class Mixer : public Singleton<Mixer>
  {
  public:
    friend class Singleton<Mixer>;
    void pick(unsigned int index);
    void play();
    void pause();

  private:
    Mixer();
    ~Mixer();

    std::vector<sf::Music*> m_musics;
    unsigned int            m_current;
    bool                    m_valid;
  };
}

#endif // MIXER_HXX
