#ifndef SINGLETON_HXX
#define SINGLETON_HXX

namespace Core
{
  template<typename T> class Singleton
  {
  public:
    static T*   getInstance();
    static void destroyInstance();

  protected:
    Singleton()                     {}
    Singleton(const T&)             {}
    Singleton& operator=(const T&)  {}
    ~Singleton()                    {}

    static T*   m_instance;
  };
}

#include "singleton.inc"

#endif // SINGLETON_HXX
