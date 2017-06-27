#ifndef GUARD_SRC_INCLUDE_MAIN_MANAGER_H_
#define GUARD_SRC_INCLUDE_MAIN_MANAGER_H_

#include <string>

#include "Employee.h"
#include "Respondent.h"

namespace callcentre
{

  // Forward declarations.
  class Call;

  /// @brief A class representing a Manager, which
  ///   is a second tier Respondent, capable of
  ///   responding to calls.
  class Manager : public Respondent
  {
  public:

    // public structors.

    /// @brief 4-parameter constructror.
    /// @param name The name of this Manager.
    /// @param id The Id of this Manager.
    /// @param experience The Experience of this Manager.
    /// @param handler The CallHandler to allocate
    ///   calls to this Manager.
    Manager( const std::string& name
           , Employee::Id id
           , Employee::Experience experience
           , CallHandler* handler = nullptr
           );

    /// @brief Copy constructor.
    /// @note Default implementation.
    Manager(const Manager&) = default;

    /// @brief Move constructor.
    /// @note Default implementation.
    Manager(Manager&&) = default;

    /// @brief Copy assignment operator.
    /// @note Default implementation.
    Manager& operator=(const Manager&) = default;

    /// @brief Move assignment operator.
    /// @note Default implementation.
    Manager& operator=(Manager&&) = default;

    /// @brief Destructor.
    /// @note Default implementation.
    virtual ~Manager() = default;

    // public methods.

    /// @brief Process a call.
    /// @param call The Call to be processed.
    virtual void process_call(Call&& call);

  private:

    // private methods.

    /// @brief Escalate a call owing to this Manager
    ///  having insufficient experience to close the
    ///  current Call.
    void escalate_call();

  }; // ! class Manager

} // ! namespace callcentre

#endif
