#ifndef OBSERVABLE_HXX
#define OBSERVABLE_HXX
#include <SFML/Window/Event.hpp>
#include "observer.hxx"
#include <map>
#include <list>

namespace Core
{
  template<typename Thing, typename Type>
  class Observable
  {
  public:
    virtual ~Observable() {}
    virtual void attach(Observer<Thing>* observer, Type eventType) = 0;
    virtual void detach(Observer<Thing>* observer) = 0;
    virtual void detach(Observer<Thing>* observer, Type eventType) = 0;

  protected:
    void internal_attach(std::map<Type, std::list<Observer<Thing>*> >& observers_list,
                         Observer<Thing>* observer,
                         Type             eventType);

    void internal_detach(std::map<Type, std::list<Observer<Thing>*> >& observers_list,
                         Observer<Thing>* observer);

    void internal_detach(std::map<Type, std::list<Observer<Thing>*> >& observers_list,
                         Observer<Thing>* observer,
                         Type             eventType);

  };

  template<typename Thing, typename Type>
  void Observable<Thing, Type>::internal_attach(std::map<Type, std::list<Observer<Thing>*> >& observers_list,
                                                Observer<Thing>* observer,
                                                Type             eventType)
  {
    typename std::map<Type, std::list<Observer<Thing>*> >::iterator  itm;
    typename std::list<Observer<Thing>*>::iterator                   itl;
    bool found;

    found = false;

    itm = observers_list.find(eventType);

    if (itm != observers_list.end())
      {
        for (itl = itm->second.begin(); itl != itm->second.end(); itl++)
          {
            if (*itl == observer)
              found = true;
          }
      }

    if (!found)
      observers_list[eventType].push_back(observer);
  }



  template<typename Thing, typename Type>
  void Observable<Thing, Type>::internal_detach(std::map<Type, std::list<Observer<Thing>*> >& observers_list,
                                                Observer<Thing>* observer)
  {
    typename std::map<Type, std::list<Observer<Thing>*> >::iterator  itm;
    typename std::list<Observer<Thing>*>::iterator                   itl;

    for (itm = observers_list.begin(); itm != observers_list.end(); itm++)
      {
        for (itl = itm->second.begin(); itl != itm->second.end(); )
          {
            if (*itl == observer)
              itl = itm->second.erase(itl);
            else
              itl++;
          }
      }
  }



  template<typename Thing, typename Type>
  void Observable<Thing, Type>::internal_detach(std::map<Type, std::list<Observer<Thing>*> >& observers_list,
                                                Observer<Thing>* observer,
                                                Type             eventType)
  {
    typename std::map<Type, std::list<Observer<Thing>*> >::iterator itm;
    typename std::list<Observer<Thing>*>::iterator itl;

    for (itm = observers_list.begin(); itm != observers_list.end(); itm++)
      {
        for (itl = itm->second.begin(); itl != itm->second.end(); )
          {
            if (*itl == observer)
              if (itm->first == eventType)
                itl = itm->second.erase(itl);
              else
                itl++;
            else
              itl++;
          }
      }
  }
}

#endif // OBSERVABLE_HXX
