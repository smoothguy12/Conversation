#include "model.hxx"
#include "log.hxx"
#include <string>
#include "Core/reader.hxx"
#include <jsoncpp/value.h>
#include "node.hxx"
#include <vector>

namespace Game
{
  namespace Conversation
  {
    Model::Model()
    {
      // "Abstract nodes" initialization
      m_friendly_end  = new Node(2000, 0, "FRIENDLY_END", false);
      m_hostile_end   = new Node(1999, 0, "HOSTILE_END",  false);

      // Json parsing
      Core::Reader reader("data/System/conversations.json");
      Json::Value content;
      unsigned int i;
      unsigned int j;
      std::vector<Node*>::iterator itr;
      std::vector<Node*>::iterator itn;

      content = reader.get();

      // Node initialization
      if (content.isArray())
        {
          for (i = 0; i < content.size(); i++)
            {
              Node*               node;
              unsigned int        id;
              unsigned int        owner_id;
              std::string         text;
              bool                npc;

              id        = content[i]["id"].asUInt();
              owner_id  = content[i]["owner_id"].asUInt();
              text      = content[i]["text"].asString();

              if (owner_id > 0)
                npc = true;
              else
                npc = false;

              node = new Node(id, owner_id, text, npc);
              m_nodes.push_back(node);

              /* FIXME: The following block crashes.
              log::put(log::trivial, "Initialized Node #");
              log::putln(log::trivial, id);
              log::putln(log::trivial, text);
              */
            }
        }

      // Targets binding (Nodes pointing others)
      if (content.isArray())
        {
          for (i = 0; i < content.size(); i++)
            {
              if (content[i]["targets"].isString())
                {
                  if (content[i]["targets"].asString() == "FRIENDLY_END")
                    {
                      for (itr = m_nodes.begin(); itr != m_nodes.end(); itr++)
                        {
                          if (content[i]["id"].asUInt() == (*itr)->getId())
                            {
                              (*itr)->addTarget(m_friendly_end);
                            }
                        }
                    }
                  else if (content[i]["targets"].asString() == "HOSTILE_END")
                    {
                      for (itr = m_nodes.begin(); itr != m_nodes.end(); itr++)
                        {
                          if (content[i]["id"].asUInt() == (*itr)->getId())
                            {
                              (*itr)->addTarget(m_hostile_end);
                            }
                        }
                    }
                }
              else if (content[i]["targets"].isArray())
                {
                  for (j = 0; j < content[i]["targets"][j].asUInt(); j++)
                    {
                      for (itr = m_nodes.begin(); itr != m_nodes.end(); itr++)
                        {
                          if ((*itr)->getId() == content[i]["targets"][j].asUInt())
                            {
                              for (itn = m_nodes.begin(); itn != m_nodes.end(); itn++)
                                {
                                  if (content[i]["id"].asUInt() == (*itn)->getId())
                                    {
                                      (*itn)->addTarget(*itr);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

      m_current = m_nodes[0];
      log::putln(log::message, "Initialized Game::Conversation::Model.");
    }



    Model::~Model()
    {
      std::vector<Node*>::iterator itr;

      delete m_friendly_end;
      delete m_hostile_end;

      for (itr = m_nodes.begin(); itr != m_nodes.end(); )
       {
          delete *itr;
          itr = m_nodes.erase(itr);
        }

      log::putln(log::message, "Destoryed Game::Conversation::Model.");
    }



    void Model::process(Node* node)
    {
    }



    Node* Model::getNode()
    {
      return m_current;
    }
  }
}
