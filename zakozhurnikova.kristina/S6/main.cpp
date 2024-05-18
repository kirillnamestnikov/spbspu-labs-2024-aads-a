#include <algorithm>
#include <cstdlib>
#include <deque>
#include <forward_list>
#include <list>
#include <iostream>
#include <string>
#include <list.hpp>
#include "generate.hpp"
#include "sorting.hpp"
#include "print.hpp"
#include "sortingSheets.hpp"

int main(int argc, char* argv[])
{
  using namespace zakozhurnikova;
  if (argc != 4)
  {
    std::cerr << "No right argument";
    return 1;
  }

  std::string sort = argv[1];
  std::string type = argv[2];
  size_t size = std::atoi(argv[3]);
  if (size == 0)
  {
    std::cerr << "Why 0? The size must be greater than zero";
    return 1;
  }
  try
  {
    if (type == "ints")
    {
      sortingSheets< int >(sort, type, size);
    }
    else if (type == "floats")
    {
      sortingSheets< float >(sort, type, size);
    }
    else
    {
      throw std::logic_error("No right type");
    }
  }
  catch (std::exception& e)
  {
    std::cerr << e.what();
    return 1;
  }
}
