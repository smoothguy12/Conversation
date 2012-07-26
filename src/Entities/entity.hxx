#ifndef ENTITY_HXX
#define ENTITY_HXX

namespace Entities
{
  class Entity
  {
  public:
    Entity();
    virtual ~Entity() {}
    virtual Entity* clone() = 0;
    virtual void initialize() = 0;
    virtual void destroy() = 0;
    bool isInitialized();
    bool isDestroyed();

  protected:
    bool m_initialized;
    bool m_destroyed;
  };
}

#endif // ENTITY_HXX
