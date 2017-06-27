#ifndef GUARD_SRC_INCLUDE_MAIN_DIRECTOR_H_
#define GUARD_SRC_INCLUDE_MAIN_DIRECTOR_H_

#include <string>

#include "Employee.h"
#include "Respondent.h"

namespace callcentre
{

  // Forward declarations.
  class Call;
  class CallHnadler;

  /// @brief A class representing a Director, which
  ///  is a third and top tier Respondent, capable
  ///  of closing Calls.
  /// @detail A Director has no ability
  ///  to escalate a Call, hence all calls handled
  ///  by a Director will be closed. A CallCentre
  /// need not be restricted to possessing a single
  /// Director.
  class Director : public Respondent
  {
  public:

    // public structors.

    /// @brief 4-parameter constructor.
    /// @param name The name of this Director.
    /// @param id The Id of this Director.
    /// @param experience The Experience of this
    ///   Director.
    /// @param handler The CallHandler responsible
    ///  for allocating calls to this Director.
    Director( const std::string& name
            , Employee::Id id
            , Employee::Experience experience
            , CallHandler* handler = nullptr
            );

    /// @brief Copy constructor.
    /// @note Default implementation.
    Director(const Director&) = default;

    /// @brief Move constructor.
    /// @note Default implementation.
    Director(Director&&) = default;

    /// @brief Copy assignment operator.
    /// @note Default implementation.
    Director& operator=(const Director&) = default;

    /// @brief Move assignment operator.
    /// @note Default implementation.
    Director& operator=(Director&&) = default;

    /// @brief Destructor.
    /// @note Default implementation.
    virtual ~Director() = default;

    // public methods.

    /// @brief Return the state of this Employee.
    /// @retval The state of this Employee.
    virtual Employee::State state() const;

    /// @brief Retrieve the type of this Employee.
    /// @retval the type of this Employee.
    virtual Employee::Type type() const;

    /// @brief Process a call.
    /// @param call The call to be processed.
    virtual void process_call(Call&& call);

    /// @brief Register a CallHandler with this Respondent.
    /// @param handler The CallHandler to register.
    void set_handler(CallHandler* handler);

  }; // ! class Director

} // ! namespace callcentre

#endif
