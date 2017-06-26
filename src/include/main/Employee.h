#ifndef GUARD_SRC_INCLUDE_MAIN_EMPLOYEE_H_
#define GUARD_SRC_INCLUDE_MAIN_EMPLOYEE_H_

#include <string>
#include <cstddef>

#include <boost/serialization/strong_typedef.hpp>

namespace callcentre
{

  /// @brief A class representing a CallCentre employee.
  class Employee
  {

  public:

    // public aliases.

    /// @brief Identification of an Employee.
    BOOST_STRONG_TYPEDEF(std::size_t, Id);

    /// @brief The Experience of an Employee. This will
    /// be used, via an implementation-specific metric,
    /// whether an Employee can successfully close
    /// a Call of a given Severity.
    BOOST_STRONG_TYPEDEF(std::size_t, Experience);

    // Public enum classes.

    /// @brief A class representing the state of an
    ///   Employee.
    enum class State
    {
      FREE,
      BUSY,
      ON_BREAK,
      SIGNED_OFF
    };

    /// @brief A class representing the type of an
    ///   Employee.
    enum class Type
    {
      RESPONDENT,
      MANGER,
      DIRECTOR
    };


    // public structors.

    /// @brief Default constructor.
    /// @note Default implementation.
    Employee() = default;

    /// @brief 3-parameter constructor.
    /// @param name The name of this Employee.
    /// @param id The Id of this Employee.
    /// @param The Experience of this Employee.
    Employee( const std::string& name
            , const Id& id
            , const Experience& experience
            );

    /// @brief Copy constructor.
    /// @note Default implementation.
    Employee(const Employee&) = default;

    /// @brief Move constructor.
    /// @note Default implementation.
    Employee(Employee&&) = default;

    /// @brief Copy assignment operator.
    /// @note Default implementation.
    Employee& operator=(const Employee&) = default;

    /// @brief Move assignment operator.
    /// @note Default implementation.
    Employee&& operator=(Employee&&) = default;

    /// @brief Destructor.
    /// @note Default implementation.
    virtual ~Employee() = default;

    // public etters.

    /// @brief Retrieve the name of this Employee.
    /// @retval The name of this Employee.
    std::string name() const;

    /// @brief Retrieve the id of this Employee.
    /// @retval The id of this Employee.
    Id id() const;

    /// @brief Retrieve the experience of this Employee.
    /// @retval The experience of this Employee.
    Experience experience() const;

    /// @brief Set the experience of this Employee.
    /// @param experience The Experience to be set.
    void experience(const Experience& experience);

    /// @brief Return the state of this Employee.
    /// @retval The state of this Employee.
    Employee::State state() const = 0;

    /// @brief Set the state of this Employee.
    /// @param state The State of this Employee.
    void state(const Employee::State& state);

    /// @brief Retrieve the type of this Employee.
    /// @retval the type of this Employee.
    virtual Employee::Type type() const = 0;

  private:

    // Private data members.

    /// @brief The name of this Employee.
    const std::string m_name;

    /// @brief The id of this Employee.
    const Id m_id;

    /// @brief The experience of this Employee.
    Experience m_experience;

    /// @brief The state of this Employee.
    Employee::State m_state;

  }; // ! class Employee

}// ! namespace callcentre

#endif
