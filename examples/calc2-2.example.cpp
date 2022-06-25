#include <iostream>

#include <boost/yap/expression.hpp>


int main()
{
  using namespace boost::yap::literals;

  std::cout << make_expression_function(1_p + 2.0)(3.0) << std::endl;
  std::cout << make_expression_function(1_p * 2_p)(3.0, 2.0) << std::endl;
  std::cout << make_expression_function((1_p - 2_p) / 2_p)(3.0, 2.0) << std::endl;
}
