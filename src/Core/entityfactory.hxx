#ifndef ENTITYFACTORY_HXX
#define ENTITYFACTORY_HXX
#include "Core/singleton.hxx"
#include "Entities/entity.hxx"
#include <string>
#include <map>
#include "log.hxx"

namespace Core
{
  class EntityFactory : public Singleton<EntityFactory>
  {
  public:
    friend class Singleton<EntityFactory>;

    ~EntityFactory();
    template<typename T>
    void learn(const std::string& name);

    Entities::Entity* give(const std::string& name);

  private:
    std::map<std::string, Entities::Entity*> m_prototypes;
  };

  template<typename T>
  void EntityFactory::learn(const std::string& name)
  {
    if (m_prototypes.find(name) == m_prototypes.end())
      {
        m_prototypes[name] = (new T());
      }
    else
      {
        log::putln(log::error, "EntityFactory is unable to learn " + name);
      }
  }
}

#endif // ENTITYFACTORY_HXX
