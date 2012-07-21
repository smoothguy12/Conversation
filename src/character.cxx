#include "character.hxx"
#include "log.hxx"

namespace Entities
{
  Character::Character()
  {
    log::putln(log::message, "One Game::Character new'd.");
  }



  Character::~Character()
  {
    log::putln(log::message, "One Game::Character deleted.");
  }



  Entity* Character::clone()
  {
    return new Character;
  }



  void Character::initialize()
  {
    m_initialized = true;

    log::putln(log::message, "One Game::Character initialized.");
  }



  void Character::destroy()
  {
    m_destroyed = true;

    log::putln(log::message, "One Game::Character destroyed.");
  }
}
