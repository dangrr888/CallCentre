#ifndef GUARD_SRC_INCLUDE_MAIN_CALL_H_
#define GUARD_SRC_INCLUDE_MAIN_CALL_H_

#include <string>

#include <boost/serialization/strong_typedef.hpp>

namespace callcentre
{

  /// @brief A class representing a call made to
  ///  a call centre.
  class final Call
  {
  public:

    // public aliases

    /// @brief Call severity, used within a
    ///   an implementation specific metric
    ///   that will be used to determine the
    ///   nececessary experience and rank of
    ///   a respondent that can close such a
    ///   call.
    BOOST_STRONG_TYPEDEF(std::size_t, Severity);

    /// @brief Call identification.
    BOOST_STRONG_TYPEDEF(std::size_t, Id);

    // public structors

    /// @brief 4-parameter constructor.
    /// @param id Id of this Call.
    /// @param caller_name The name of the caller.
    /// @param description A brief description of the
    ///    the purpose of the call.
    /// @param severity The severity of the call.
    Call( const Id& id
        , const std::string& caller_name
        , const std::string& description
        , const Severity& severity
        );

    /// @brief Copy constructor.
    /// @note Default implementation.
    Call(const Call&) = default;

    /// @brief Move constructor.
    /// @note Default implementation.
    Call(Call&&) = default;

    /// @brief Copy assignment operator.
    /// @note Default implementation.
    Call& operator=(const Call&) = default;

    /// @brief Move assignment operator.
    /// @note Default implementation.
    Call& operator=(Call&&) = default;

    /// @brief Destructor.
    /// @note Default implementation.
    ~Call() = default;

    // Public etters

    /// @brief Return the id of this Call.
    /// @retval The id of this Call.
    const Id& id() const;

    /// @brief Return the name of the caller
    ///   associated with this Call.
    /// @retval The name of the caller.
    const std::string& caller_name() const;

    /// @brief Return a description of this Call.
    /// @retval The description of this Call.
    const std::string& description() const;

    /// @brief Return the severity of this Call.
    /// @retval The severity of this Call.
    const Severity& severity() const;

    /// @brief Set the severity of this Call.
    /// @param severity_ The severity to set.
    void severity(const Severity& severity_);

  private:

    // Private data members.

    /// @brief The id of this Call.
    const Id m_id;

    /// @brief The caller name.
    const std::string m_caller_name;

    /// @brief The description of this Call.
    const std::string m_description;

    /// @brief The severity of this Call.
    Severity m_severity;

  }; // ! class Call

} // ! namespace callcentre

#endif

