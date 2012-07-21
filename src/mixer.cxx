#include "mixer.hxx"
#include "vectorreader.hxx"
#include "log.hxx"
#include <SFML/Audio/Music.hpp>

namespace Core
{
  Mixer::Mixer()
  {
    std::vector<std::string>  vector;
    VectorReader              vector_reader("data/System/musics.json");
    unsigned int              index;

    vector    = vector_reader.get();
    m_current = 0;
    m_valid   = false;

    if (!vector_reader.isValid())
      {
        log::putln(log::fatal, "Invalid musics file.");
        return ;
      }

    for (index = 0; index < vector.size(); index++)
      {
        sf::Music* music = new sf::Music();

        log::put(log::trivial, "Loading (Music) : " + vector[index] + "... ");

        if (!music->openFromFile("data/Audio/Musics/" + vector[index]))
          {
            log::putln(log::trivial, "Fail!");
          }
        else
          {
            log::putln(log::trivial, "Ok.");

            m_musics.push_back(music);
          }
      }

    if (m_musics.size() > 0)
        m_valid = true;

    log::putln(log::message, "Initialized Core::Mixer");
  }



  Mixer::~Mixer()
  {
    std::vector<sf::Music*>::iterator it;

    for (it = m_musics.begin(); it != m_musics.end(); )
      {
        delete *it;
        it = m_musics.erase(it);
      }

    log::putln(log::message, "Destroyed Core::Mixer");
  }



  void Mixer::pick(unsigned int index)
  {
    if (m_valid and index < m_musics.size())
      {
        if (m_musics[m_current]->getStatus() == sf::Music::Playing)
          m_musics[m_current]->pause();

        m_current = index;
      }
    else
      {
        log::putln(log::error, "Tried to read beyond Music list size.");
      }
  }



  void Mixer::play()
  {
    if (m_valid and m_musics[m_current]->getStatus() != sf::Music::Playing)
      {
        m_musics[m_current]->play();
      }
  }



  void Mixer::pause()
  {
    if (m_valid and m_musics[m_current]->getStatus() == sf::Music::Playing)
      {
        m_musics[m_current]->pause();
      }
  }
}
