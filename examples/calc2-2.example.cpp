// Copyright (C) 2016-2018 T. Zachary Laine
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>

#include <boost/yap/expression.hpp>


int main()
{
  using namespace boost::yap::literals;

  std::cout << make_expression_function(1_p + 2.0)(3.0) << std::endl;
  std::cout << make_expression_function(1_p * 2_p)(3.0, 2.0) << std::endl;
  std::cout << make_expression_function((1_p - 2_p) / 2_p)(3.0, 2.0) << std::endl;
}
