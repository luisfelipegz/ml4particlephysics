#include <cassert>
#include <cmath>
#include <stdexcept>
#include "ml4particlephysics/FourVector.hpp"

int main(){
  // Define a four-momentum in GeV
  ml4particlephysics::FourVector p{10.0, 3.0, 4.0, 0.0};

  // Expected three-momentum squared: 9+16=25
  assert(p.momentum_squared() == 25.0);

  // Expected three-momentum magnitude: sqrt(25)=5.
  assert(p.momentum() == 5.0);

  // Expected invariant mass squared: 100-9-16=75
  assert(p.mass_squared() == 75.0);

  // Expected invariant mass: sqrt(75).
  assert(std::abs(p.mass())-std::sqrt(75.0) < 1e-12);

  // Define a spacelike four-vector
  ml4particlephysics::FourVector spacelike{1.0, 2.0, 0.0, 0.0};

  // Check that calculating its mass throws a domain error.
  bool exception_thrown = false;
  try{
    spacelike.mass();
  }
  catch (const std::domain_error &){
    exception_thrown = true;
  }
  assert(exception_thrown);

  // Test transverse momentum.
  ml4particlephysics::FourVector p_transverse{10.0, 3.0, 4.0, 0.0};
  
  // Expected transverse momentum: sqrt(9+16)=5.
  assert(p_transverse.pt() == 5.0);
  
  // Changing pz should not affect transverse momentum.
  ml4particlephysics::FourVector p_longitudinal{10.0, 3.0, 4.0, 6.0};
  assert(p_longitudinal.pt() == 5.0);
  
  return 0;
}
