#include "default_headers.hpp"
#include "patterns.hpp"

namespace {
// CRTP Pattern
template <typename ConcreteType> class Base {
    Base() = default;

  public:
    void interface() { std::cout << "Base Interface: " << static_cast<ConcreteType *>(this)->getName() << "\n"; };
    friend ConcreteType;
};

class Derived : public Base<Derived> {
    std::string symbolName;

  public:
    Derived(std::string symName) : symbolName(std::move(symName)) {};
    [[nodiscard]] auto getName() const -> std::string_view { return symbolName; };
};
} // namespace

void crtp() {
    std::cout << "CRTP Example" << "\n";
    Derived dev{/**symName=*/"CRTP Derived"};
    dev.interface();
}