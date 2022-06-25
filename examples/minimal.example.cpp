#include <iostream>

#include <boost/yap/print.hpp>
#include <boost/yap/expression.hpp>


template <boost::yap::expr_kind Kind, typename Tuple>
struct minimal_expr
{
  static const boost::yap::expr_kind kind = Kind;
  Tuple elements;
};

template <typename T>
T plus(T a, T b)
{
  auto left = boost::yap::make_terminal<minimal_expr>(a);
  auto right = boost::yap::make_terminal<minimal_expr>(b);
  auto expr = boost::yap::make_expression<
    minimal_expr, 
    boost::yap::expr_kind::plus
  >(left, right);

  boost::yap::print(std::cout, left);
  boost::yap::print(std::cout, right);
  boost::yap::print(std::cout, expr);

  return boost::yap::evaluate(expr);
}

int main()
{
  std::cout << plus(1, 41) << std::endl;
}
