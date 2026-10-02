class IntPair {
public:
  IntPair(int x, int y) {}
};

void print(IntPair p) {}

int main() {
  // instead of doing this
  IntPair p{3, 5};
  print(p);
  // we can do this instead:

  print(IntPair{5, 6}); // temporary IntPair
  print({2, 5});        // this is also valid
}
