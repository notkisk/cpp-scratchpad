int main() {
  /*What type of conversion happens in each of the following cases?
   * Valid answers are: No conversion needed, numeric promotion,
   * numeric conversion, won’t compile due to narrowing conversion.
   * Assume int and long are both 4 bytes.
   */
  int a{5};   // 1a -> no conversion nedded
  int b{'a'}; // 1b -> numeric promotion from char aka int8_t to int
  int c{5.4}; // 1c -> this won't compile because list initiliazation disallow's
              // narrowing conversion
  int d{true}; // 1d -> numeric promortion
  int e{static_cast<int>(
      5.4)}; // 1e -> static cast will perform a numeric conversion
  // from double to int, omiting the fractional part, and then a normal
  // assignment int to an int

  double f{5.0f}; // 1f ->   // a numeric promotion because its from a float to
                  // double
  double g{5};    // 1g -> this is a numeric conversion from int to double

  // Extra credit section
  long h{5}; // 1h -> numeric conversion, since both int and long are 4 bytes

  float i{f}; // 1i (uses previously defined variable f) -> this is a narrowing
              // conversion since we are
  // converting a wide type doulbe to a narrower type float making us loss
  // information, this won't compile since list initiliazation disallow
  // narrowing conversions, this won't compile because we are initlizing it with
  // an expression that is not a constexpr
  float j{5.0}; // 1j -> numeric conversion double to float, this is allowed
                // only when the expression is assigned a constexpr
}
