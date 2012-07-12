#include "character.hxx"
#include "log.hxx"

namespace Entities
{
  Character::Character()
  {
  }

  Character::~Character()
  {
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
    m_destroyed = true;
  }
}
