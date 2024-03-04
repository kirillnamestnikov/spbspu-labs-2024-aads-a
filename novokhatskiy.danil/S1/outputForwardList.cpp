#include "outputForwardList.hpp"
#include <limits>

int novokhatskiy::outputForwardList(std::ostream& out, ForwardList<std::pair<std::string, ForwardList< size_t  > > >& pairs)
{
  if (pairs.empty())
  {
    out << "0" << '\n';
  }
  ForwardIterator< std::pair<std::string, ForwardList< size_t > > > iter = pairs.begin();
  size_t maxSize{};
  for (; iter != pairs.end(); iter++)
  {
    if (std::isalpha(iter->first[0]))
    {
      if (iter != pairs.begin())
      {
        out << ' ';
      }
      out << iter->first;
    }
    else
    {
      std::cout << ' ';
    }
    maxSize = std::max(maxSize, iter->second.max_size());
  }
  std::cout << '\n';
  ForwardList< size_t > listOfSums;
  size_t sum{};
  for (size_t i = 0; i < maxSize; i++)
  {
    for (auto j = pairs.begin(); j != pairs.end(); ++j)
    {
      ForwardIterator< size_t > numberIter = j->second.begin();
      if (j->second.max_size() <= i)
      {
        continue;
      }
      numberIter = numberIter.moveIterator(i);
      if (sum != 0)
      {
        out << ' ';
      }
      if (std::numeric_limits< size_t>::max() - *numberIter <= *numberIter)
      {
        std::cerr << "Overflow\n";
        return 1;
      }
      out << *numberIter;
      sum += *numberIter;
    }
    out << '\n';
    listOfSums.push_front(sum);
    sum = 0;
  }
  listOfSums.reverse();
  for (auto i = listOfSums.begin(); i != listOfSums.end(); ++i)
  {
    if (i != listOfSums.begin())
    {
      out << ' ';
    }
    out << *i;
  }
  out << '\n';
  return 0;
}
