#ifndef GUARD_SRC_INCLUDE_MAIN_EMPLOYEE_H_
#define GUARD_SRC_INCLUDE_MAIN_EMPLOYEE_H_

#include <string>
#include <cstddef>

#include <boost/serialization/strong_typedef.hpp>

namespace callcentre
{

class Employee
{
public:
  BOOST_STRONG_TYPEDEF(std::size_t, Id);
  BOOST_STRONG_TYPEDEF(std::size_t, Experience);

  Employee() = default;
  Employee( const std::string& name_
          , const Id& id_
          , const Experience& experience_
          );

  std::string name() const;
  Id id() const;
  Experience experience() const;
  void experience(const Experience& experience_);

private:
  const std::string m_name;
  const Id m_id;
  Experience m_experience;

}; // ! class Employee

}// ! namespace callcentre

#endif
