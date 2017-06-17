#ifndef GUARD_SRC_INCLUDE_MAIN_RESPONDENT_H_
#define GUARD_SRC_INCLUDE_MAIN_RESPONDENT_H_

#include <string>
#include <deque>

#include "Employee.h"
#include "Call.h"

namespace callcentre
{

class CallHandler;
class Call;

class Respondent : public Employee
{
public:

  /* structors */
  Respondent( const std::string& name
            , Employee::Id id
            , Employee::Experience experience
            );

  Respondent( const std::string& name
            , Employee::Id id
            , Employee::Experience experience
            , CallHandler& handler
            );

  Respondent(const Respondent&) = default;
  Respondent(Respondent&&) = default;
  Respondent& operator=(const Respondent&) = default;
  Respondent& operator=(Respondent&&) = default;
  virtual ~Respondent() = default;

  virtual void process_call(Call&& call); // Could use state pattern here.

protected:
  void close_call();
  void reject_call();
  void increment_experience();
  void notify_handler();

  void sign_off();
  std::size_t quota_metric() const; // Could use a strategy pattern here for the metric, or template this

  //void take_break(); // no point since will be an indefinite break unless use multiple threads and hence equiv to sign_off
  //std::size_t m_breaks;
  std::deque<Call> m_closed_calls;

  CallHandler* m_callhandler;
  Call m_call;

private:
    void escalate_call();

}; // ! class Respondent

} // ! namespace callcentre

#endif
