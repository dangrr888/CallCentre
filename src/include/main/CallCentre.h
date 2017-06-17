#ifndef GUARD_SRC_INCLUDE_MAIN_CALLCENTRE_H_
#define GUARD_SRC_INCLUDE_MAIN_CALLCENTRE_H_

#include <deque>

#include "Employee.h"
#include "Call.h"

namespace callcentre
{

class CallCentre
{
public:

  /* structors */
  CallCentre() = default;

  template<typename EmployeeIter>
  CallCentre( EmployeeIter beg
            , EmployeeIter end
            );

  CallCentre(const CallCentre&) = delete;
  CallCentre(CallCentre&&) = delete;
  CallCentre& operator=(const CallCentre&) = delete;
  CallCentre& operator=(const CallCentre&&) = delete;
  ~CallCentre() = default;

  /* etters */
  void recieve_call(Call&& call);
  void add_employee(Employee&& employee);

  /* Use iterator pattern here to obscure internal details */
  std::deque<callcentre::Employee>::const_iterator cbegin() const;
  std::deque<callcentre::Employee>::const_iterator cend() const;

  std::deque<callcentre::Employee>::iterator begin();
  std::deque<callcentre::Employee>::iterator end();

  void open();
  void close();

private:

  /* data members */
  enum class Status
  {
    OPEN,
    CLOSED
  };

  std::deque<callcentre:Employee> m_employees;
  Status m_status;
  std::deque<callcentre::Call> m_calls;

}; // ! class CallCentre

} // ! namespace callcentre

#endif
