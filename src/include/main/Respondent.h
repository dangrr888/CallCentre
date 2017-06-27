#ifndef GUARD_SRC_INCLUDE_MAIN_RESPONDENT_H_
#define GUARD_SRC_INCLUDE_MAIN_RESPONDENT_H_

#include <string>
#include <deque>

#include "Employee.h"
#include "Call.h"

namespace callcentre
{

  // Forward declarations
  class CallHandler;
  class Call;

  /// @brief A class representing an Employee
  ///  capable of responding to calls recieved
  /// by the CallCentre that owns the Employee.
  class Respondent : public Employee
  {
  public:

    // public structors.

    /// @brief 4-parameter constructor.
    /// @param name The name of this Respondent.
    /// @param id The identification of this Respondent.
    /// @param experience The Experience of this Respondent.
    /// @param handler The CallHandler associated with this Respondent.
    Respondent( const std::string& name
              , Employee::Id id
              , Employee::Experience experience
              , CallHandler* handler
              );

    /// @brief Copy constructor.
    /// @note Default implementation.
    Respondent(const Respondent&) = default;

    /// @brief Move constructor.
    /// @note Default implementation.
    Respondent(Respondent&&) = default;

    /// @brief Copy constructor.
    /// @note Default implementation.
    Respondent& operator=(const Respondent&) = default;

    /// @brief Move assignment operator.
    /// @note Default implementation.
    Respondent& operator=(Respondent&&) = default;

    /// @brief Destructor.
    /// @note Default implementation.
    virtual ~Respondent() = default;

    /// @brief Process a Call.
    /// @param call The call to be processed.
    /// @todo - use state pattern based on Respondent Experience and
    ///   Call Severity.
    virtual void process_call(Call&& call);

    /// @brief Register a CallHandler with this Respondent.
    /// @param handlerThe CallHandler to register.
    void set_handler(CallHandler* handler);

  protected:

    // protected etters.

    /// @brief Clase the call after successful processing.
    void close_call();

    /// @brief Reject the current Call as it cannot be processed
    ///  by this Respondent.
    void reject_call();

    /// @brief Increment the Experience of this Respondent,
    ///  based upon the closed calls made by this Respondent.
    void increment_experience();

    /// @brief Notify the CallHandler registered with this
    ///  Respondent that a Call has been rejected and needs
    ///  to be handled by a more experienced Respondent.
    void notify_handler();

    /// @brief Return the result of the current metric
    ///  using the closed calls of this Respondent.
    /// @todo - Could use a strategy pattern here for the metric, or template this
    double quota_metric() const;

    //void sign_off();
    //void take_break(); // no point since will be an indefinite break unless use multiple threads and hence equiv to sign_off

    // protected data members.

    //std::size_t m_breaks;

    /// @brief The closed calls of this Respondent.
    std::deque<Call> m_closed_calls;

    /// @brief The CallHandler registered with this Respondent.
    CallHandler* m_callhandler;

    /// @brief The current Call being processed by this Respondent.
    Call m_call;

  private:

    // private etters.

    /// @brief Escalate the call to a more experienced Respondent.
    void escalate_call();

  }; // ! class Respondent

} // ! namespace callcentre

#endif
