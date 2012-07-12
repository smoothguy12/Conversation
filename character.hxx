#ifndef CHARACTER_HXX
#define CHARACTER_HXX
#include "entity.hxx"

namespace Entities
{
  class Character : public Entity
  {
  public:
    Character();
    ~Character();
    Entity* clone();
    void initialize();
    void destroy();
  };
}

#endif // CHARACTER_HXX
