#pragma once
#include <exception>

class InsufficientFundsExpection : public std::exception
{
  public:
    InsufficientFundsExpection() = default;
    ~InsufficientFundsExpection() = default;
    virtual const char *what() const noexcept override
    {
        return "Insuffients funds";
    }
};
class InsufficientWithdraws : public std::exception
{
  public:
    InsufficientWithdraws() = default;
    ~InsufficientWithdraws() = default;
    virtual const char *what() const noexcept override
    {
        return "You've done too many withdraws";
    }
};