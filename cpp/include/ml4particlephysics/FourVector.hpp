#pragma once

namespace ml4particlephysics{

struct FourVector {
  double energy{0.0};
  double px{0.0};
  double py{0.0};
  double pz{0.0};

  // Calculate the invariant mass squared
  double mass_squared() const {
    return energy*energy - px*px - py*py - pz*pz;
  }
};

} // namespace ml4particlephysics
