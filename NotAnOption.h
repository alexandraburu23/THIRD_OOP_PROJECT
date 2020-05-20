#ifndef NOTANOPTION_H
#define NOTANOPTION_H


#include <exception>

class NotAnOption : public std::exception {
public:
  NotAnOption () noexcept {}

  NotAnOption (const NotAnOption&) noexcept = default;

  NotAnOption& operator= (const NotAnOption&) noexcept = default;

  virtual ~NotAnOption() noexcept = default;

  virtual const char* what() const noexcept {
    return "The option you chose was not listed. Exit proceeded.\n";
  }
};
#endif // NOTANOPTION_H
