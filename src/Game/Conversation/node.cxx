#include "node.hxx"
#include <string>
#include <vector>

namespace Game
{
  namespace Conversation
  {
    Node::Node(unsigned int id,
               unsigned int owner_id,
               std::string text,
               bool npc,
               std::vector<Node*> targets)
    {
      m_id        = id;
      m_owner_id  = owner_id;
      m_text      = text;
      m_npc       = npc;
      m_targets   = targets;
    }



    Node::~Node()
    {
      std::vector<Node*>::iterator itr;

      for (itr = m_targets.begin(); itr != m_targets.end(); )
        {
          itr = m_targets.erase(itr);
        }
    }



    const unsigned int& Node::getId()
    {
      return m_id;
    }



    const unsigned int& Node::getOwnerId()
    {
      return m_owner_id;
    }



    const std::string& Node::getText()
    {
      return m_text;
    }



    const bool& Node::belongsToNPC()
    {
      return m_npc;
    }



    const std::vector<Node*>& Node::getTargets()
    {
      return m_targets;
    }



    void Node::addTarget(Node* target)
    {
      m_targets.push_back(target);
    }
  }
}

