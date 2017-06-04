#ifndef GUARD_SRC_INCLUDE_MAIN_CALL_H_
#define GUARD_SRC_INCLUDE_MAIN_CALL_H_

#include <boost/serialization/strong_typedef.hpp>

namespace callcentre
{

  class Call
  {
  public:
    BOOST_STRONG_TYPEDEF(std::size_t, Severity);
    BOOST_STRONG_TYPEDEF(std::size_t, Id);

    Call( const Id& id_
        , const std::string& caller_name_
        , const std::string& description_
        , const Severity& severity_
        );

    const Id& id() const;
    const std::string& caller_name() const;
    const std::string& description() const;
    const Severity& severity() const;
    void severity(const Severity& severity_);

  private:
    Id m_id;
    const std::string m_caller_name;
    const std::string m_description;
    Severity m_severity;

  }; // ! class Call

} // ! namespace callcentre

#endif

