#include "Call.h"

#include <string>

namespace callcentre
{

  Call::Call( const Id& id
            , const std::string& caller_name
            , const std::string& description
            , const Severity& severity
            )
    : m_id(id)
    , m_caller_name(caller_name)
    , m_description(description)
    , m_severity(severity)
  {}

  const Call::Id& Call::id() const
  {
    return m_id;
  }

  const std::string& Call::caller_name() const
  {
    return m_caller_name;
  }

  const std::string& Call::description() const
  {
    return m_description;
  }

  const Call::Severity& Call::severity() const
  {
    return m_severity;
  }

  void Call::severity(const Call::Severity& severity_)
  {
    m_severity = severity_;
  }

} // ! namespace callcentre
