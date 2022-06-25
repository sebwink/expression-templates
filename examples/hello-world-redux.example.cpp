#include <iostream>

#include <boost/yap/algorithm.hpp>


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

  return 0;
}
