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

  const std::string& Employee::name() const
  {
    return m_name;
  }

  const Employee::Id& Employee::id() const
  {
    return m_id;
  }

  const Employee::Experience& Employee::experience() const
  {
    return m_experience;
  }

  void Employee::experience(const Experience& experience_)
  {
    m_experience = experience_;
  }

  const Employee::State& Employee::state() const
  {
    return m_state;
  }

  void Employee::state(const Employee::State& state_)
  {
    m_state = state_;
  }

} // ! namespace callcentre
