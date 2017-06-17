#ifndef GUARD_SRC_INCLUDE_MAIN_EMPLOYEE_H_
#define GUARD_SRC_INCLUDE_MAIN_EMPLOYEE_H_

#include <string>
#include <cstddef>

#include "boost/serialization/strong_typedef.hpp"

namespace callcentre
{

class Employee
{
public:

  /* public asliases */
  BOOST_STRONG_TYPEDEF(std::size_t, Id);
  BOOST_STRONG_TYPEDEF(std::size_t, Experience);

  /* public data members */
  enum class State
  {
    FREE,
    BUSY,
    ON_BREAK,
    SIGNED_OFF
  };

  enum class Type
  {
    RESPONDENT,
    MANGER,
    DIRECTOR
  };

  /* structors */
  Employee() = default;
  Employee( const std::string& name
          , const Id& id
          , const Experience& experience
          );
  Employee(const Employee&) = default;
  Employee& operator=(const Employee&) = default;
  Employee&& operator=(Employee&&) = default;
  virtual ~Employee() = default;

  /* etters */
  std::string name() const;
  Id id() const;
  Experience experience() const;
  void experience(const Experience& experience);
  Employee::State state() const = 0;
  void state(const Employee::State& state_);
  virtual Employee::Type type() const = 0;

private:
  /* data members */
  const std::string m_name;
  const Id m_id;
  Experience m_experience;
  Employee::State m_state;

}; // ! class Employee

}// ! namespace callcentre

#endif
