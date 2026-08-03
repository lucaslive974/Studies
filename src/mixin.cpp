#include "default_headers.hpp"
#include "patterns.hpp"

namespace {
template <typename ConcreteType, template <typename> class... Traits> class Base : public Traits<ConcreteType>... {
    Base() = default;

  public:
    void interface() { std::cout << "Multiple Interface: " << static_cast<ConcreteType *>(this)->getName() << "\n"; };
    friend ConcreteType;
};

template <typename Concrete> struct PrintableTrait {
    PrintableTrait() = default; // NOLINT(bugprone-crtp-constructor-accessibility)

  public:
    void print() const { std::cout << "Name Trait: " << static_cast<const Concrete *>(this)->getName() << "\n"; }
    friend Concrete;
};

template <typename Concrete> struct LoggableTrait {
    LoggableTrait() = default; // NOLINT(bugprone-crtp-constructor-accessibility)

  public:
    void log() { std::cout << "Logger Mixin" << "\n"; }
    friend Concrete;
};

class Derived : public Base<Derived, PrintableTrait, LoggableTrait> {
    std::string symbolName;

  public:
    Derived(std::string symName) : symbolName(std::move(symName)) {};
    [[nodiscard]] auto getName() const -> std::string_view { return symbolName; };
};
} // namespace

void mixin() {
    std::cout << "Mixins Example" << "\n";
    Derived dev{"Mixins"};
    dev.interface();
    dev.print();
    dev.log();
}