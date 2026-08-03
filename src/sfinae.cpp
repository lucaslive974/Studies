#include "default_headers.hpp"
#include "patterns.hpp"
#include "utility"

namespace {
template <typename T, typename = void> struct has_behaviour : std::false_type {};
template <typename T> struct has_behaviour<T, std::void_t<decltype(std::declval<T>().behaviour())>> : std::true_type {};

struct SpecializedAdaptor {
  public:
    static void behaviour() { std::cout << "Specialized adaptor behavior by SFINAE" << '\n'; }
};

// Traits composition
template <typename Adaptor, typename = std::enable_if_t<has_behaviour<Adaptor>::value>> struct GenericAdaptor {
  public:
    void behaviour() { Adaptor::behaviour(); };
};
} // namespace

void sfinae() {
    std::cout << "SFINAE Example" << "\n";
    GenericAdaptor<SpecializedAdaptor> adaptor;
    adaptor.behaviour();
}