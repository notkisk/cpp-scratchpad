// whats wrong with this snippen of code?
int main() {
  int v1{45};
  int *ptr{&v1}; // initialize ptr with address of v1

  int v2{78};
  *ptr = &v2; // assign ptr to address of v2
  // the issue resides in the last line, you deferencing ptr and and assigning
  // it address of v2, there is a type mismatch here and there is no valid
  // conversion for that, you can't assign int with an int*, to fix this you can
  // emit the ampersand (address of operator) this way you will assign the value
  // of v2 to whatever ptr is pointing to, this results in v1 = 78
}
