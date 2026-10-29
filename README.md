# Machine Learning for Particle Physics

ML4ParticlePhysics is an open-source scientific computing framework for particle physics, machine learning, and statistical analysis.

The project aims to provide modular, reusable tools for particle physics research, independent of any specific experiment or collaboration.

## Goals

- Develop a high-performance C++ kinematic event generator.
- Provide Python interfaces for physics simulations.
- Support on-the-fly event generation for ML training.
- Integrate with PyTorch and TensorFlow.
- Implement classical and deep learning methods.
- Provide statistical interference and data analysis tools.
- Support reproducible computational physics research.

## Current Development

The project is in its early development stage.

### Implementation

- Basic C++ `FourVector` structure.
- Three-momentum squared calculation.
- Three-momentum magnitude calculation.
- Transverse momentum calculation.
- Invariant mass squared calculation.
- Invariant mass calculation with spacelike vector handling.
- C++ physics tests for kinematic calculations and exceptions.

### Planned

- Four-vector mathematical operations.
- Lorentz transformations
- Two-body and multi-body decay generation.
- Python bindings and event streaming.
- Machine learning and statistical analysis modules.

## Project Structure

```text
cpp/
├── include/
│   └── ml4particlephysics/
│       └── FourVector.hpp
├── src/
└── tests/
    └── test_four_vector.cpp
```

## Testing

The current C++ test can be compiled using:

```bash
c++ -std=c++17 -Wall -Wextra -Icpp/include cpp/tests/test_four_vector.cpp  -o /tmp/test_four_vector
```

Run the test:

```bash
/tmp/test_four_vector
```

The test passes if the program exits successfully.

## Conventions

- Natural units are used, with `c = 1`.
- Four-momenta follow `(E, p_x, p_y, p_z)`.
- The Minkowski metric convention is `(+, -, -, -)`.

## Development Status

ML4ParticlePhysics is under active development. Features are being implemented and validated incrementally.
