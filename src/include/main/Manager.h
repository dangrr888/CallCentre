#ifndef GUARD_SRC_INCLUDE_MAIN_MANAGER_H_
#define GUARD_SRC_INCLUDE_MAIN_MANAGER_H_

#include <string>

#include "Call.h"
#include "Employee.h"
#include "CallHandler.h"

namespace callcentre
{

  class Manager : public callcentre::Respondent
  {
  public:

    Manager( const std::string& name_
           , callcentre::Employee::Id id_
           , callcentre::Employee::Experience experience_
           );

    Manager( const std::string& name_
           , callcentre::Employee::Id id_
           , callcentre::Employee::Experience experience_
           , callcentre::CallHandler& handler_
           );

    virtual void process_call(std::unique_ptr<callcentre::Call>&& call_); // Could use state pattern here.
    virtual State state() const;
    virtual Type type() const;

  private:

  }; // ! class Manager

} // ! namespace callcentre

#endif
