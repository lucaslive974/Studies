# 📚 Programming Studies: Idioms, Patterns & LeetCode

[![Build](https://img.shields.io/badge/Build-CMake-success.svg)]()
[![Status](https://img.shields.io/badge/Status-Active_Learning-success.svg)]()

This is my personal repository for studying software design patterns, architectural idioms, advanced programming concepts, and algorithmic problem-solving. While the current implementations explore specific paradigms, the core structural and algorithmic concepts are largely language-agnostic.

## 📁 Repository Structure

The project is organized to separate architectural concepts, algorithmic challenges, and testing modules[cite: 1]:

*   **`ring-zero/`**: Directory for foundational or low-level experiments[cite: 1].
*   **`studies/`**: The core project folder, configured for compilation via `CMakeLists.txt`[cite: 1].
    *   **`include/`**: Contains central header files like `patterns.hpp`, `leetcode.hpp`, `hashmap.h`, and `helpers.hpp`[cite: 1].
    *   **`src/patterns/`**: Practical implementations of design idioms and concepts[cite: 1]:
        *   `CRTP.cpp` (Curiously Recurring Template Pattern for static polymorphism)[cite: 1]
        *   `concepts.cpp` (Semantic type constraints)[cite: 1]
        *   `mixin.cpp` (Composition via Mixins / Multiple Inheritance)[cite: 1]
        *   `pimpl.cpp` (Pointer to Implementation / Compilation firewalls)[cite: 1]
        *   `sfinae.cpp` (Substitution Failure Is Not An Error / Type introspection)[cite: 1]
        *   `typeTraits.cpp` (Type manipulation at compile-time)[cite: 1]
        *   `memory.cpp` (Memory management concepts)[cite: 1]
        *   `hashmap.c` (Custom hash map implementation)[cite: 1]
    *   **`src/leetcode/`**: Solutions to competitive programming challenges[cite: 1]:
        *   **`problems/`**: Individual numbered problem solutions (e.g., `1.cpp`, `9.cpp`, `704.cpp`)[cite: 1].
        *   **`quests/`**: Thematic algorithmic study tracks, including `array1.cpp`, `monotonic1.cpp`, and `stack.cpp`[cite: 1].
        *   **`plans/`**: Learning plans and tracking (`leetcode.cpp`)[cite: 1].
    *   **`src/tests/`**: Dedicated testing modules for the different study areas (`hashmap.c`, `leetcode.cpp`, `patterns.cpp`)[cite: 1].

## 🚀 Getting Started

This repository uses CMake to manage builds[cite: 1]. To compile the project:

```bash
# Clone the repository
git clone --recurse-submodules [https://github.com/lucaslive974/Studies.git](https://github.com/lucaslive974/Studies.git)
cd Studies/studies

# Configure and build using CMake
mkdir build && cd build
cmake ..
make