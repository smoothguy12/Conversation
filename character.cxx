#include "character.hxx"
#include "log.hxx"

namespace Entities
{
  Character::Character()
  {
    log::write(log::message, "One Game::Character new'd.");
  }

  Character::~Character()
  {
    log::write(log::message, "One Game::Character deleted.");
  }

  Entity* Character::clone()
  {
    return (new Character);
  }

  void Character::initialize()
  {
    log::write(log::message, "One Game::Character initialized.");
    m_initialized = true;
  }

  void Character::destroy()
  {
    log::write(log::message, "One Game::Character destroyed.");
    m_destroyed = true;
  }
}
