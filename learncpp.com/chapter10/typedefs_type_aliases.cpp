// #define INT_2_BYTES
#ifdef INT_2_BYTES
using int8_t = char;
using int16_t = int;
using int32_t = long;
#else
using int8_t = char;
using int16_t = short;
using int32_t = int;
#endif

int main() {
  using Miles = long; // define Miles as an alias for type long
  using Speed = long; // define Speed as an alias for type long
  typedef long Miles; // same as above
  typedef long Speed;
  Miles distance{5}; // distance is actually just a long
  Speed mhz{3200};   // mhz is actually just a long

  // The following is syntactically valid (but semantically meaningless)
  distance = mhz;

  return 0;
}
