// utility.cpp

// IN THIS FILE, define any of your OWN functions you may need to 
// solve the problems.    
#include <cmath>
#include "utility.h"


// You will need to include the function prototype in "utility.h" and
// then be sure to  #include "utility.h" in the file where you use
// these functions
bool approx_equal(double a, double b, double tol) {
  return abs(a - b) < tol;
}
