#include <iostream>

#include <boost/hana/maximum.hpp>
#include <boost/yap/expression.hpp>


struct get_arity
{
  template <long long I>
  boost::hana::llong<I> operator() (
      boost::yap::expr_tag<boost::yap::expr_kind::terminal>,
      boost::yap::placeholder<I>
  )
  {
    return boost::hana::llong_c<I>;
  }

  template <typename T>
  auto operator() (boost::yap::expr_tag<boost::yap::expr_kind::terminal>, T&&)
  {
    using namespace boost::hana::literals;
    return 0_c;
  }

  template <boost::yap::expr_kind Kind, typename ...Arg>
  auto operator() (boost::yap::expr_tag<Kind>, Arg&& ...arg)
  {
    return boost::hana::maximum(
      boost::hana::make_tuple(
        boost::yap::transform(
          boost::yap::as_expr(std::forward<Arg>(arg)),
          get_arity{}
        )...
      )
    );
  }
};


int main()
{
  using namespace boost::yap::literals;

  auto expr_1 = 1_p + 2.0;
  auto expr_1_fn = [expr_1](auto&& ...args)
  {
    auto const arity = boost::yap::transform(expr_1, get_arity{});
    static_assert(arity.value == sizeof...(args), "Called with wrong number of args.");
    return evaluate(expr_1, args...);
  };
  auto expr_1_fn_unchecked = [expr_1](auto&& ...args)
  {
    return evaluate(expr_1, args...);
  };


  std::cout << expr_1_fn(3.0) << std::endl;
  // std::cout << expr_1_fn(3.0, 2.0) << std::endl;
  // --> error: static assertion failed: Called with wrong number of args.
  std::cout << expr_1_fn_unchecked(3.0, 2.0) << std::endl;
}
