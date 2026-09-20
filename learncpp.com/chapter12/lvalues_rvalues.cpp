int return5() { return 5; }

int main() {
  int x{5};            // 5 is an rvalue expression
  const double d{1.2}; // 1.2 is an rvalue expression

  int y{x};          // x is a modifiable lvalue expression
  const double e{d}; // d is a non-modifiable lvalue expression
  int z{return5()};  // return5() is an rvalue expression (since the result is
                     // returned by value)

  int w{x + 1}; // x + 1 is an rvalue expression, becayuse it evaluates to a
                // temp value x+1 <=> 5 + 1 = 6 which is a temp value
  int q{static_cast<int>(
      d)}; // the result of static casting d to an int is an rvalue expression,
           // because the static cast evaluates to just the temp value 1 ( .2
           // truncated )
  // 5 = w; this is invalid because the assignment operator= enforces that the
  // value to the left of =(aka the left operand) must be a modifiable lvalue
  // expression you don't know what an expression is? an expression is just a
  // set of litterals/operators/variables/function calls the results in a value
  // like 5 + 1 or add(1,2)

  const double t{};

  // int z{y}; // y is a modifiable lvalue because it evaluates to an
  // identifiable object
  const double f{d}; // d is a non-modifiable lvalue because it evaluates to a
                     // const identifiable object
  return 0;
}
