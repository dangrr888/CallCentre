#ifndef GUARD_SRC_MAIN_INCLUDE_CALLHANDLER_H_
#define GUARD_SRC_MAIN_INCLUDE_CALLHANDLER_H_

#include <deque>
#include <list>
#include <memory>

#include "Employee.h"
#include "Call.h"

namespace callcentre
{

  class CallCentre;
  class Respondent;

  class CallHandler : public Employee
  {
  public:

    /* structors */
    CallHandler(CallCentre& callcentre);
    CallHandler(const CallHandler&) = default;
    CallHandler(CallHandler&&) = default;
    CallHandler& operator=(const CallHandler&) = default;
    CallHandler& operator=(CallHandler&&) = default;
    ~CallHandler() = default;

    /* etters */
    void receive_call(Call&& call);
    void process_call();

    std::list<Call>::size_type num_calls() const;

  private:

    /* private etters */
    Respondent& find_respondent(const Call& call, Employee::Type) const;
    void assign_call(Call&& call, Respondent& respondent);

    /* data members */
    std::list<Call> m_calls; // convert to queue of unique pointers if possible
    CallCentre& m_callcentre;

  }; // ! class CallHandler

} // ! namespace callcentre

#endif
