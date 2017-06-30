#ifndef GUARD_SRC_INCLUDE_MAIN_CALLCENTRE_H_
#define GUARD_SRC_INCLUDE_MAIN_CALLCENTRE_H_

#include "Employee.h"
#include "Call.h"

#include <deque>

namespace callcentre
{

  /// @brief A class representing a CallCentre.
  class CallCentre final
  {

  public:

    // public enumeration classes.

    /// @brief An internal enum class representing the
    ///  state of a CallCenre.
    enum class Status
    {
      OPEN,
      CLOSED
    };

    // public structors.

    /// @brief Default constructor.
    CallCentre() = default;

    /// @brief 2-parameter templatized constructor.
    /// @param EmployeeIter An iterator to a
    ///   list of callcentre::Employee's to
    ///   become owned by this CallCentre.
    /// @param beg The start Employee.
    /// @param end The last Employee.
    template<typename EmployeeIter>
    CallCentre( EmployeeIter beg
              , EmployeeIter end
              );

    /// @brief Copy constructor.
    /// @note Deleted.
    CallCentre(const CallCentre&) = delete;

    /// @brief Move Constructor.
    /// @note Deleted.
    CallCentre(CallCentre&&) = delete;

    /// @brief Copy assignment operator.
    /// @note Deleted.
    CallCentre& operator=(const CallCentre&) = delete;

    /// @brief Move assignment operator.
    /// @param Deleted.
    CallCentre& operator=(const CallCentre&&) = delete;

    /// @brief Destructor.
    /// @note Deleted.
    ~CallCentre() = default;

    // Public etters.

    /// @brief Submit a call to the CallCentre.
    /// @param call The submitted Call.
    void recieve_call(Call&& call);

    /// @brief Add an Employee to the CallCentre.
    /// @param employee The Employee to become owned
    ///  by this CallCentre.
    void add_employee(Employee&& employee);

    /// @todo - Use iterator pattern here to obscure internal details

    /// @brief Return a constant iterator to one beyond the last enntry in
    ///   a list of the Employee's owned by this CallCentre.
    std::deque<callcentre::Employee>::const_iterator cbegin() const;

    /// @brief Return a constant iterator to the first entry in a list of the
    ///   Employee's owned by this CallCentre.
    std::deque<callcentre::Employee>::const_iterator cend() const;

    /// @brief Return a non-constant iterator to one beyond the last enntry in
    ///   a list of the Employee's owned by this CallCentre.
    std::deque<callcentre::Employee>::iterator begin();

    /// @brief Return a non-constant iterator to the first entry in a list of the
    ///   Employee's owned by this CallCentre.
    std::deque<callcentre::Employee>::iterator end();

    /// @brief Return the status of this CallCentre.
    /// @retval The status of this CallCentre.
    const Status& status() const;

    /// @brief Set the status of this CallCentre.
    /// @param status_ The status to be set.
    void status(const Status& status_);

  private:

    // private data members.

    /// @brief The list of Employee owned by this CallCentre.
    std::deque<callcentre::Employee> m_employees;

    /// @brief The status of this CallCentre
    Status m_status;

    /// @brief The list of calls currently submitted to this CallCenter
    ///   that have not yet been transferred to a respondent.
    std::deque<callcentre::Call> m_calls;

  }; // ! class CallCentre


  // Definitions of templatized functions.

  template<typename EmployeeIter>
  CallCentre::CallCentre( EmployeeIter beg
                        , EmployeeIter end
                        )
    : m_employees()
    , m_status(Status::OPEN)
    , m_calls()
  {
    for(EmployeeIter iter = beg; iter != end; ++iter)
    {
      // take ownership of the Employee populating this CallCentre.
      add_employee(std::move(*iter));
    }
  }

} // ! namespace callcentre

#endif
