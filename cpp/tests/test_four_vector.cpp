#include <cassert>
#include "ml4particlephysics/FourVector.hpp"

int main(){
  // Define a four-momentum in GeV
  ml4particlephysics::FourVector p{10.0, 3.0, 4.0, 0.0};

  // Expected three-momentum squared: 9+16=25
  assert(p.momentum_squared() == 25.0);

  // Expected invariant mass squared: 100-9-16=75
  assert(p.mass_squared() == 75.0);
  
  return 0;
}
