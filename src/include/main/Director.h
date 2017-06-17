#ifndef GUARD_SRC_INCLUDE_MAIN_DIRECTOR_H_
#define GUARD_SRC_INCLUDE_MAIN_DIRECTOR_H_

#include <string>

#include "Employee.h"
#include "Respondent.h"

namespace callcentre
{

  class Call;

  class Director : public Respondent
  {
  public:

    /* structors */
    Director( const std::string& name
           , Employee::Id id
           , Employee::Experience experience
           );

    Director( const std::string& name
           , Employee::Id id
           , Employee::Experience experience
           , CallHandler& handler
           );

    Director(const Director&) = default;
    Director(Director&&) = default;
    Director& operator=(const Director&) = default;
    Director& operator=(Director&&) = default;
    virtual ~Director() = default;

    virtual void process_call(Call&& call);

  }; // ! class Director

} // ! namespace callcentre

#endif
