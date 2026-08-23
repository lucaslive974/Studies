#include "default_headers.hpp"
#include "patterns.hpp"
#include <concepts>

namespace {
// Concepts (C++20)
template <typename T>
concept HasBehaviour = requires(T &typo) {
    { typo.behaviour() } -> std::same_as<void>;
};

struct SpecializedAdaptor {
  public:
    static void behaviour() { std::cout << "Specialized adaptor behavior by Concepts" << '\n'; }
};

// Concepts composition
template <HasBehaviour Adaptor> struct GenericAdaptor {
  public:
    void behaviour() { Adaptor::behaviour(); };
};
} // namespace

auto concepts() -> void {
    GenericAdaptor<SpecializedAdaptor> adaptor;
    adaptor.behaviour();
}
