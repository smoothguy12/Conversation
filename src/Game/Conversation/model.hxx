#ifndef MODEL_HXX
#define MODEL_HXX
#include "node.hxx"
#include <vector>
#include <string>

namespace Game
{
  namespace Conversation
  {
    class Model
    {
    public:
      Model();
      ~Model();
      void                process(Node* node);
      Node*               getNode();

    protected:
      Node*               m_current;
      std::vector<Node*>  m_nodes;
      Node*               m_friendly_end;
      Node*               m_hostile_end;
    };
  }
}

#endif // MODEL_HXX
