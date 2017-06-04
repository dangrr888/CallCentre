#ifndef GUARD_SRC_INCLUDE_MAIN_RESPONDENT_H_
#define GUARD_SRC_INCLUDE_MAIN_RESPONDENT_H_

#include "Employee.h"
#include "Call.h"

#include <memory>

namespace callcentre
{

class callcentre::CallHandler;
class callcentre::Call;

class Respondent : public callcentre::Employee
{
public:

  enum class State
  {
    FREE,
    BUSY,
    ON_BREAK,
    SIGNED_OFF
  };

  enum class Type
  {
    RESPONDENT,
    MANGER,
    DIRECTOR
  };

  Respondent( const std::string& name_
            , callcentre::Employee::Id id_
            , callcentre::Employee::Experience experience_
            );

  Respondent( const std::string& name_
            , callcentre::Employee::Id id_
            , callcentre::Employee::Experience experience_
            , callcentre::CallHandler& handler_
            );

  virtual void process_call(std::unique_ptr<callcentre::Call>&& call_); // Could use state pattern here.
  virtual State state() const;
  virtual Type type() const;

private:
  void state(const State& state_);
  void close_call();
  virtual void escalate_call();
  void reject_call();
  void increment_experience();
  void notify_handler();
  //void take_break(); // no point since will be an indefinite break unless use multiple threads and hence equiv to sign_off
  void sign_off();
  std::size_t quota_metric() const; // Could use a strategy pattern here for the metric, or template this

  std::shared_ptr<callcentre::CallHandler> m_handler;
  std::unique_ptr<callcentre::Call> m_call;
  std::size_t m_breaks;
  State m_state;
  std::deque<std::unique_ptr<callcentre::Call>> m_closed_calls;

}; // ! class Respondent

} // ! namespace callcentre

#endif
