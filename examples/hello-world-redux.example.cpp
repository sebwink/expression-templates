// Copyright (C) 2016-2018 T. Zachary Laine
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>

#include <boost/yap/algorithm.hpp>
#include <boost/yap/print.hpp>


template <boost::yap::expr_kind Kind, typename Tuple>
struct stream_expr
{
  static const boost::yap::expr_kind kind = Kind;

  Tuple elements;

  template <typename T>
  decltype(auto) operator<< (T&& x)
  {
    return boost::yap::value(*this) << std::forward<T&&>(x);
  }
};


int main()
{
  auto cout = boost::yap::make_terminal<stream_expr>(std::cout);
  cout << "Hello" << ',' << " World!" << '\n';

  boost::yap::print(std::cout, cout);

  return 0;
}
