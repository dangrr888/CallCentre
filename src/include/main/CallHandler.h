#ifndef GUARD_SRC_MAIN_INCLUDE_CALLHANDLER_H_
#define GUARD_SRC_MAIN_INCLUDE_CALLHANDLER_H_

#include <deque>
#include <queue>
#include <memory>

#include "Employee.h"
#include "Respondent.h"
#include "Call.h"

namespace callcentre
{

class CallHandler : public Employee
{
public:
  CallHandler() = default;
  ~CallHandler() = default;

  template< RespondentIter respondent_iter
          , CallIter call_iter
          >
  CallHandler( RespondentIter respondent_beg
             , RespondentIter respondent_end
             , CallIter call_beg
             , CallIter call_end
             );

  void add_call(std::unique_ptr<callcentre::Call>&& call_);
  void process_call();
  void acknowledge(callcentre::Respondent& respondent_);

private:
  callcentre::Respondent& find_respondent(const callcentre::Call& call_) const; // use lambda here
  void assign_call(std::unique_ptr<callcentre::Call>&& call_); // try to avoid 2 moves if possible

  std::queue<std::unique_ptr<callcentre::Call>> m_calls;
  std::deque<callcentre::Respondent&> m_respondents;

}; // ! class CallHandler

} // ! namespace callcentre

#endif
