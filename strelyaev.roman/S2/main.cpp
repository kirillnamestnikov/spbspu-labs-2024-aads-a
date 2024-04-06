#include <iostream>
#include <fstream>
#include "queue.hpp"
#include "stack.hpp"
#include "calculations.hpp"
#include "conversion.hpp"

int main(int argc, char * argv[])
{
  using namespace strelyaev;
  Stack< long long > results;
  if (argc == 1)
  {
    while (std::cin.good())
    {
      long long result = 0;
      try
      {
        result = calculateInfixExpression(std::cin);
      }
      catch (const std::length_error& e)
      {
        continue;
      }
      catch (const std::exception& e)
      {
        std::cerr << e.what() << "\n";
        return 1;
      }
      results.push(result);
    }
    printResults(results, std::cout);
  }
  else if (argc == 3)
  {
    std::ifstream input_file(argv[1]);
    std::ofstream output_file(argv[2]);
    while (input_file.good())
    {
      long long result = 0;
      try
      {
        result = calculateInfixExpression(input_file);
      }
      catch (const std::length_error& e)
      {
        continue;
      }
      catch (const std::exception& e)
      {
        std::cerr << e.what() << "\n";
        return 1;
      }
      results.push(result);
    }
    printResults(results, output_file);
  }
  else
  {
    std::cerr << "Invalid cmd parameters\n";
    return 1;
  }
}
