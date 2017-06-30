#include "CallHandler.h"
#include "Call.h"

#include <list>

namespace callcentre
{

  std::list<Call>::size_type CallHandler::num_calls() const
  {
    return m_calls.size();
  }

  void CallHandler::receive_call(Call&& call)
  {
    /// @todo - implement me.
  }

} // ! namespace callcentre
