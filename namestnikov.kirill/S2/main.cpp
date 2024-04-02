#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include "stack.hpp"
#include "convert_to_postfix.hpp"
#include "calculate_postfix_expression.hpp"

int main()
{
  /*std::queue<std::string> prefixExpression;
  std::queue<std::string> postfixExpression;
  std::stack<std::string> operationStack;
  std::string inString = "";
  while (std::cin >> inString)
  {
    if (std::isdigit(inString[0]))
    {
      postfixExpression.push(inString);      
    }
    else
    {
      if (!operationStack.empty())
      {
        postfixExpression.push(operationStack.top());
        operationStack.pop();
      }
      operationStack.push(inString);
    }
  }*/
  std::stack< std::string > processStack;
  std::queue< std::string > currentQueue;
  std::queue< std::string > resultQueue;
  std::string inputString = "";
  while ((!std::cin.eof()) && (std::cin >> inputString))
  {
    std::cout << inputString << "|";
    currentQueue.push(inputString);
  }
  std::cout << currentQueue.size();
  namestnikov::convertToPostfix(currentQueue, resultQueue);
  /*std::string result = "";
  while (!resultQueue.empty())
  {
    //std::cout << resultQueue.front() << "\t";
    result += resultQueue.front();
    resultQueue.pop();
  }
  std::cout << result << "\n";*/
  std::cout << namestnikov::calculatePostfixExpression(resultQueue);
}