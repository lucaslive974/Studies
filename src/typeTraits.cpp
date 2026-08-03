#include "default_headers.hpp"
#include "patterns.hpp"
#include <type_traits>

namespace {
// Example from std
template <typename T> struct Integral : std::false_type {};

struct MyType {
  public:
    static auto getTypeName() -> std::string { return "MyType"; }
};

// Explicit specialization
// Actually specializate this traits on std is UB, but this is for education purposes;
template <> struct Integral<MyType> : std::true_type {};

} // namespace

void typeTraits() {
    std::cout << "Type traits Example" << '\n';
    if constexpr (Integral<MyType>::value) {
        std::cout << MyType::getTypeName() << " is integral!" << '\n';
    } else {
        std::cout << MyType::getTypeName() << " isn't integral!" << '\n';
    }
}