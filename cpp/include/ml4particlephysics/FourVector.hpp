#pragma once

#include <cmath>
#include <stdexcept>
#include <limits>

namespace ml4particlephysics{

struct FourVector {
  double energy{0.0};
  double px{0.0};
  double py{0.0};
  double pz{0.0};

  // Calculate the magnitude squared of the spatial momentum.
  double momentum_squared() const {
    return px*px + py*py + pz*pz;
  }

  // Calculate the magnitude of the spatial momentum
  double momentum() const {
    return std::sqrt(momentum_squared());
  }

  // Calculate the transverse momentum.
  double pt() const {
    return std::hypot(px, py);
  }

  // Calculate the invariant mass squared.
  double mass_squared() const {
    return energy*energy - momentum_squared();
  }

  // Calculate the invariant mass.
  double mass() const {
    double m2 = mass_squared();
    if (m2 < 0.0){
      throw std::domain_error("Invariant mass is undefined for spacelike four-vectors.");
    }
    return std::sqrt(m2);
  }

  // Calculate the azimuthal angle in radians.
  double phi() const {
    return std::atan2(py, px);
  }

  // Calculate the pseudorapidity.
  double eta() const {
    double transverse = pt();

    // Handle particles moving exactly along the z-axis
    if (transverse == 0){
      if (pz == 0){
        throw std::domain_error("Pseudorapidity is undefined for zero momentum.");
      }
      double infinity = std::numeric_limits<double>::infinity();
      return pz > 0.0 ? infinity : -infinity;
    }
    
    return std::asinh(pz / transverse);
  }
};

} // namespace ml4particlephysics
