#include "key_summ.hpp"
#include <limits>
#include <stdexcept>

ishmuratov::Key_summ::Key_summ():
  int_sum_(0),
  str_sum_()
{}

void ishmuratov::Key_summ::operator()(const std::pair< const int, std::string > & key_value)
{
  constexpr int maxnum = std::numeric_limits< int >::max();
  constexpr int minnum = std::numeric_limits< int >::min();
  if ((int_sum_ > 0) && (int_sum_ > maxnum - key_value.first))
  {
    throw std::overflow_error("Overflow!");
  }
  if ((int_sum_ < 0) && (int_sum_ < minnum + key_value.first))
  {
    throw std::underflow_error("Underflow!");
  }
  int_sum_ += key_value.first;
  str_sum_ += " " + key_value.second;
}

int ishmuratov::Key_summ::get_int()
{
  return int_sum_;
}

std::string ishmuratov::Key_summ::get_str()
{
  return str_sum_;
}


