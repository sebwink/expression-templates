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

  auto expr_1 = 1_p + 2.0;
  auto expr_1_fn = [expr_1](auto&& ...args)
  {
    return boost::yap::evaluate(expr_1, args...);
  };

  auto expr_2 = 1_p * 2_p;
  auto expr_2_fn = [expr_2](auto&& ...args)
  {
    return boost::yap::evaluate(expr_2, args...);
  };

  auto expr_3 = (1_p - 2_p) / 2_p;
  auto expr_3_fn = [expr_3](auto&& ...args)
  {
    return boost::yap::evaluate(expr_3, args...);
  };

  std::cout << expr_1_fn(3.0) << std::endl;
  std::cout << expr_2_fn(3.0, 2.0) << std::endl;
  std::cout << expr_3_fn(3.0, 2.0) << std::endl;
  
  return 0;
}
