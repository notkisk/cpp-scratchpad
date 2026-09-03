// #include <iostream>

// so name shadowing is when you declare multiple variables with same identifier but in diffrent scopes
// what happens is the ones in their local scope will shadow or hide the ones in other scopes
int value { 5 }; // global variable, it is externaly linked by default
const int c_value {}; // constant global variables are internaly linked 
constexpr int ce_value  {}; // internally linked by default 
static int st_value {}; // since its marked as static, it will be internally linked, meaning any reference to this variable
// will be linked to this definition, any reference to it outside of this translation unit will result in a linker error!
// constants are internally linked so you can safely propagate them using header files safely without violating the ODR rule 

static constexpr int v{}; // no need to use the static keyword, as the constxpr are internaly linked by default 
// so you can emit that static 
extern bool something; // this mean it will be externaly linked, the linker will 
// search for the definition of something and link to it any reference, 
/*functions are globly linked by default, marking tem 
 * as static set them to be internaly linked*/
[[maybe_unused]] static int add (int x, int y){
  return x + y;
}
int main()
{

    return 0;
}
