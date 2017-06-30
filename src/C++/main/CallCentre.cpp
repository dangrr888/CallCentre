#include "CallCentre.h"
#include "CallHandler.h"
#include "Employee.h"

#include <stdexcept>
#include <vector>

namespace
{

  bool compare(callcentre::CallHandler* i, callcentre::CallHandler* j)
  {
    return i->num_calls() < j->num_calls();
  }

} // ! anonymous namespace

namespace callcentre
{

  void CallCentre::recieve_call(Call&& call)
  {
    if (status() != Status::OPEN)
    {
      /// @todo - throw boost exception!
      throw std::logic_error("Attempted to submit call to closed CallCentre!");
    }

    // Obtain the CallHandler's
    /// @note This iterating through the CallCentre employees
    ///  is necessary because the CallCentre does not have
    ///  separate lists for its different employee types.
    ///  Hence, the CallCentre is decoupled from the various
    ///  concrete employee subclasses. This results in the
    ///  rather disappointing algorithm below, which acknowledges
    ///  CallHandler's in any case. However, no further Employee
    ///  distinctions need to be made, hence split employee list
    ///  into two lists, one for CallHandlers and another for
    ///  other employees so that the distinction need not be
    ///  reaffirmed here.
    std::vector<CallHandler*> call_handlers;
    for (Employee& employee : m_employees)
    {
      if (employee.type() == Employee::Type::CALLHANDLER)
      {
        call_handlers.push_back(&dynamic_cast<CallHandler&>(employee));
      }
    }

    // Select the call handler with the least number of calls
    std::sort(call_handlers.begin(), call_handlers.end(), compare);

    (*call_handlers.begin())->receive_call(std::move(call));
  }

  const CallCentre::Status& CallCentre::status() const
  {
    return m_status;
  }


} // ! namespace callcentre
