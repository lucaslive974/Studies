# 📚 Programming Studies: Idioms, Patterns & LeetCode

[![Build](https://img.shields.io/badge/Build-CMake-success.svg)]()
[![Status](https://img.shields.io/badge/Status-Active_Learning-success.svg)]()

This is my personal repository for studying software design patterns, architectural idioms, advanced programming concepts, and algorithmic problem-solving. While the current implementations explore specific paradigms, the core structural and algorithmic concepts are largely language-agnostic.

## 📁 Repository Structure

The project is organized to separate architectural concepts, algorithmic challenges, and testing modules:

*   **`ring-zero/`**: Directory for foundational or low-level experiments.
*   **`studies/`**: The core project folder, configured for compilation via `CMakeLists.txt`.
    *   **`include/`**: Contains central header files like `patterns.hpp`, `leetcode.hpp`, `algorithms.hpp`, `hashmap.h`, and `helpers.hpp`.
    *   **`src/algorithms/`**: Algorithm implementations, including sorting, graph traversal, and numeric operations (`fastExponentiation.cpp`).
    *   **`src/patterns/`**: Practical implementations of design idioms and concepts:
        *   `CRTP.cpp` (Curiously Recurring Template Pattern for static polymorphism)
        *   `concepts.cpp` (Semantic type constraints)
        *   `lifting.cpp` (Function lifting / Type elevation)
        *   `mixin.cpp` (Composition via Mixins / Multiple Inheritance)
        *   `pimpl.cpp` (Pointer to Implementation / Compilation firewalls)
        *   `sfinae.cpp` (Substitution Failure Is Not An Error / Type introspection)
        *   `typeErasure.cpp` (Type Erasure pattern for runtime polymorphism)
        *   `typeTraits.cpp` (Type manipulation at compile-time)
        *   `memory.cpp` (Rule of Five, Copy & Swap idiom, Smart Pointers)
        *   `hashmap.c` (Custom hash map implementation)
    *   **`src/leetcode/`**: Solutions to competitive programming challenges:
        *   **`problems/`**: Individual numbered problem solutions (e.g., `1.cpp`, `9.cpp`, `704.cpp`).
        *   **`quests/`**: Thematic algorithmic study tracks, including `array1.cpp`, `array2.cpp`, `monotonic1.cpp`, `stack.cpp`, and `extras.cpp`.
        *   **`plans/`**: Learning plans and tracking (`leetcode.cpp`).
    *   **`src/tests/`**: Dedicated testing modules for the different study areas (`hashmap.c`, `leetcode.cpp`, `patterns.cpp`, `algorithms.cpp`).

## 🚀 Getting Started

This repository uses CMake to manage builds. To compile the project:

```bash
# Clone the repository
git clone --recurse-submodules [https://github.com/lucaslive974/Studies.git](https://github.com/lucaslive974/Studies.git)
cd Studies/studies

# Configure and build using CMake
mkdir build && cd build
cmake ..
make