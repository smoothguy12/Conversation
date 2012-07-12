#include "entityfactory.hxx"
#include "log.hxx"

namespace Core
{
  Entities::Entity*   EntityFactory::give(const std::string& name)
  {
    std::map<std::string, Entities::Entity*>::iterator it;
    bool found;
    Entities::Entity* tmp;

    found = false;

    for (it = m_prototypes.begin(); it != m_prototypes.end(); it++)
      {
        if (it->first == name)
          {
            found = true;
            tmp   = it->second->clone();
            break;
          }
      }

    if (found)
      return (tmp);
    else
      log::write(log::error, "Tried to create unknown object!");
    // TODO: Raise exception
  }
}
