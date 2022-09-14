#ifndef LISTEXCEPTION_HPP_INCLUDED
#define LISTEXCEPTION_HPP_INCLUDED

#include <exception>

class UnderFlowException : public std::exception {
public:
  const char *what() const noexcept { return "Alulcsordulas!"; }
};

class OverflowException : public std::exception {
public:
    const char *what() const noexcept { return "Felulcsordulas!"; }
};


class NotValidInput : public std::exception {
public:
    const char *what() const noexcept { return "Helytelen ertek beolvasasnal!"; }
};

#endif // LISTEXCEPTION_HPP_INCLUDED
