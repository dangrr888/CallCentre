#ifndef GUARD_SRC_INCLUDE_MAIN_MANAGER_H_
#define GUARD_SRC_INCLUDE_MAIN_MANAGER_H_

#include <string>

#include "Employee.h"
#include "Respondent.h"

namespace callcentre
{

  class Call;

  class Manager : public Respondent
  {
  public:

    /* structors */
    Manager( const std::string& name
           , Employee::Id id
           , Employee::Experience experience
           );

    Manager( const std::string& name
           , Employee::Id id
           , Employee::Experience experience
           , CallHandler& handler
           );

    Manager(const Manager&) = default;
    Manager(Manager&&) = default;
    Manager& operator=(const Manager&) = default;
    Manager& operator=(Manager&&) = default;
    virtual ~Manager() = default;

    virtual void process_call(Call&& call);

  private:
    void escalate_call();

  }; // ! class Manager

} // ! namespace callcentre

#endif
