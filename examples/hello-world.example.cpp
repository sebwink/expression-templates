#include <iostream>

#include <boost/yap/expression.hpp>

int main()
{
  boost::yap::evaluate(
    boost::yap::make_terminal(std::cout) << "Hello, World!\n"
  );

  return 0;
}
