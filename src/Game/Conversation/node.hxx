#ifndef NODE_HXX
#define NODE_HXX
#include <string>
#include <vector>

namespace Game
{
  namespace Conversation
  {
    class Node
    {
    public:
      Node(unsigned int       id,
           unsigned int       owner_id,
           std::string        text,
           bool               npc,
           std::vector<Node*> targets = std::vector<Node*>());
      ~Node();
      const unsigned int&       getId();
      const unsigned int&       getOwnerId();
      const std::string&        getText();
      const bool&               belongsToNPC();
      const std::vector<Node*>& getTargets();
      void addTarget(Node* target);

    protected:
      unsigned int              m_id;
      unsigned int              m_owner_id;
      std::string               m_text;
      bool                      m_npc;
      std::vector<Node*>        m_targets;
    };

  }
}

#endif // NODE_HXX
