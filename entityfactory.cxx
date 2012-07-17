#include "entityfactory.hxx"
#include "log.hxx"

namespace Core
{
  EntityFactory::~EntityFactory()
  {
    std::map<std::string, Entities::Entity*>::iterator it;

    for (it = m_prototypes.begin(); it != m_prototypes.end(); it++)
      {
        delete it->second;
      }

    m_prototypes.clear();
  }



  Entities::Entity*   EntityFactory::give(const std::string& name)
  {
    std::map<std::string, Entities::Entity*>::iterator it;
    bool              found;
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
      return tmp;
    else
      {
        log::putln(log::fatal, "Tried to create an unknown object!");

        throw new std::string("Tried to create an unknown object!");
      }
  }
}
