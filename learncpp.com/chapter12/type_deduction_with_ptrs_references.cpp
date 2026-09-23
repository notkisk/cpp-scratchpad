#include <string>

constexpr std::string_view hello{"Hello"}; // implicitly const

constexpr const std::string_view &
getConstRef() // function is constexpr, returns a const std::string_view&
{
  return hello;
}

int main() {
  // auto ref1{getConstRef()}; // std::string (reference dropped, then top-level
  //                           // const dropped from result)
  // const auto &ref2{getConstRef()}; // this is how to reapply it unfortunatly,
  //                                  // this is really weird
  // // like why would they make it this complicated? why is the only thing they
  // // constantly doing is making the language harder and harder every std
  // update!
  auto ref1{getConstRef()}; // std::string_view (reference dropped and top-level
                            // const dropped)
  constexpr auto ref2{
      getConstRef()}; // constexpr const std::string_view (reference dropped and
                      // top-level const dropped, constexpr applied, implicitly
                      // const)

  auto &ref3{getConstRef()}; // const std::string_view& (reference reapplied,
                             // low-level const not dropped)
  constexpr const auto &ref4{
      getConstRef()}; // constexpr const std::string_view& (reference reapplied,
                      // low-level const not dropped, constexpr applied)

  return 0;
}
