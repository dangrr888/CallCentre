#ifndef GUARD_SRC_INCLUDE_MAIN_CALLCENTRE_H_
#define GUARD_SRC_INCLUDE_MAIN_CALLCENTRE_H_

#include <deque>

#include "Employee.h"

namespace callcentre
{

class CallCentre
{
public:
  CallCentre() = default;

  template<typename EmployeeIter>
  CallCentre( EmployeeIter beg
            , EmployeeIter end
            );

  void open();
  void close();

private:
  std::deque<callcentre::CallCentre> m_call_handlers;
  std::deque<callcentre::Respondent> m_respondents;

}; // ! class CallCentre

} // ! namespace callcentre

#endif
