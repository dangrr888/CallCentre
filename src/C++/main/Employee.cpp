#include "Employee.h"

namespace callcentre
{

  Employee::Employee( const std::string& name
                    , const Id& id
                    , const Experience& experience
                    )
  : m_name(name)
  , m_id(id)
  , m_experience(experience)
  , m_state(State::FREE)
  {}

  std::string Employee::name() const
  {
    return m_name;
  }

  Employee::Id Employee::id() const
  {
    return m_id;
  }

  Employee::Experience Employee::experience() const
  {
    return m_experience;
  }

  void Employee::experience(const Experience& experience)
  {
    m_experience = experience;
  }

  Employee::State Employee::state() const
  {
    return m_state;
  }

} // ! namespace callcentre
