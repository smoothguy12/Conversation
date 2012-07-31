#include <stddef.h>

namespace Core
{
  template<typename T> T* Singleton<T>::m_instance = NULL;

  template<typename T> T* Singleton<T>::getInstance()
  {
    if (m_instance == NULL)
        m_instance = new T();
    return (m_instance);
  }

  template<typename T> void Singleton<T>::destroyInstance()
  {
      if (m_instance != NULL)
      {
          delete (m_instance);
          m_instance = NULL;
      }
  }
}
