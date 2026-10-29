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

  // Test azimuthal angles in all four quadrants.
  const double tolerance = 1e-12;
  
  // Quadrant I px > 0, py > 0.
  ml4particlephysics::FourVector p1{10.0, 3.0, 4.0, 0.0};
  assert(std::abs(p1.phi() - 0.9272952180016122) < tolerance);

  // Quadrant II: px < 0, py > 0.
  ml4particlephysics::FourVector p2{10.0, -3.0, 4.0, 0.0};
  assert(std::abs(p2.phi() - 2.214297435588181) < tolerance);

  // Quadrant III: px < 0, py < 0.
  ml4particlephysics::FourVector p3{10.0, -3.0, -4.0, 0.0};
  assert(std::abs(p3.phi() + 2.214297435588181) < tolerance);

  // Quadrant IV: px > 0, py < 0.
  ml4particlephysics::FourVector p4{10.0, 3.0, -4.0, 0.0};
  assert(std::abs(p4.phi() + 0.9272952180016122) < tolerance);
 
  // Test pseudorapidity.
  const double eta_tolerance = 1e-12;
  
  // Positive pseudorapidity: px = 3, py=4, pz=5.
  ml4particlephysics::FourVector eta_positive{10.0, 3.0, 4.0, 5.0};
  
  // Expected eta = asinh(1) = ln(1+sqrt(2)).
  double expected_eta = std::log(1.0 + std::sqrt(2.0));
  assert(std::abs(eta_positive.eta() - expected_eta) < eta_tolerance);

  // Negative pseudorapidity: reverse the z-momentum.
  ml4particlephysics::FourVector eta_negative{10.0, 3.0, 4.0, -5.0};
  assert(std::abs(eta_negative.eta() + expected_eta) < eta_tolerance);

  // Zero pseudorapidity: momentum entirely in the transverse plane.
  ml4particlephysics::FourVector eta_zero{10.0, 3.0, 4.0, 0.0};
  assert(eta_zero.eta() == 0.0);

  // Infinite pseudorapidity: momentum along the z-axis.
  ml4particlephysics::FourVector eta_forward{10.0, 0.0, 0.0, 5.0};
  ml4particlephysics::FourVector eta_backward{10.0, 0.0, 0.0, -5.0};
  assert(std::isinf(eta_forward.eta()) && eta_forward.eta() > 0.0);
  assert(std::isinf(eta_backward.eta()) && eta_backward.eta() < 0.0);

  // Undefined pseudorapidity: zero spatial momentum.
  ml4particlephysics::FourVector eta_undefined{10.0, 0.0, 0.0, 0.0};
  bool eta_exception_thrown = false;
  try {
      eta_undefined.eta();
  }
  catch (const std::domain_error&) {
      eta_exception_thrown = true;
  }
  assert(eta_exception_thrown);

  return 0;
}
