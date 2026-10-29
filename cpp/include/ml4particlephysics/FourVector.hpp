#pragma once

#include <cmath>
#include <stdexcept>

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
};

} // namespace ml4particlephysics
