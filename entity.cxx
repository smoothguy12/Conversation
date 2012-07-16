#include "entity.hxx"

namespace Entities
{
  Entity::Entity()
  {
    m_initialized = false;
    m_destroyed   = false;
  }



  bool Entity::isInitialized()
  {
    return m_initialized;
  }



  bool Entity::isDestroyed()
  {
    return m_destroyed;
  }
}
