#include <iostream>

// Global variable forward declarations (extern w/ no initializer):
extern int g_z;                 // forward declaration for non-constant global variable
extern const int g_z;           // forward declaration for const global variable
extern constexpr int g_z;       // not allowed: constexpr variables can't be forward declared

// External global variable definitions (no extern)
int g_h;                        // defines non-initialized external global variable (zero initialized by default)
int g_h { 1 };                  // defines initialized external global variable

// External const global variable definitions (extern w/ initializer)
extern const int g_h { 2 };     // defines initialized const external global variable
extern constexpr int g_h { 3 }; // defines initialized constexpr external global variable

int main(){

  return 0;
}
