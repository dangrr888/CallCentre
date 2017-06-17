#ifndef GUARD_SRC_INCLUDE_MAIN_CALL_H_
#define GUARD_SRC_INCLUDE_MAIN_CALL_H_

#include <boost/serialization/strong_typedef.hpp>

#includec<string>

namespace callcentre
{

  class Call
  {
  public:
    BOOST_STRONG_TYPEDEF(std::size_t, Severity);
    BOOST_STRONG_TYPEDEF(std::size_t, Id);

    /* structors */
    Call( const Id& id
        , const std::string& caller_name
        , const std::string& description
        , const Severity& severity
        );
    Call(const Call&) = default;
    Call(Call&&) = default;
    Call& operator=(const Call&) = default;
    Call& operator=(Call&&) = default;

    ~Call() = default;

    /* publis etters */
    const Id& id() const;
    const std::string& caller_name() const;
    const std::string& description() const;
    const Severity& severity() const;
    void severity(const Severity& severity);

  private:

    /* data members */
    Id m_id;
    const std::string m_caller_name;
    const std::string m_description;
    Severity m_severity;

  }; // ! class Call

} // ! namespace callcentre

#endif

