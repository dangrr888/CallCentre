#include "Employee.h"

Employee::Employee( const std::string& name
                  , const Id& id
                  , const Experience& experience_
                  )
: m_name(name)
, m_id(id)
, m_experience(experience_)
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

void Employee::experience(const Experience& experience_)
{
  m_experience = experience_;
}
