#include "default_headers.hpp"
#include "patterns.hpp"
#include <memory>

namespace {
// First you forward declare the implementation class
class Impl;

// Pass the forward impl class as a private member
// This would be your interface
class AbstractInterface {
  public:
    void printImplName();
    AbstractInterface();
    ~AbstractInterface();

  private:
    std::unique_ptr<Impl> impl;
};


// Here it goes on the implementation file(cpp)
class Impl {
    std::string implName;

  public:
    Impl(std::string name) : implName(std::move(name)) {};
    auto getImplName() -> std::string_view { return implName; };
};

AbstractInterface::~AbstractInterface() = default;

// Now define the Interface
AbstractInterface::AbstractInterface() : impl(std::make_unique<Impl>("Custom PIMPL")) {};
void AbstractInterface::printImplName() { std::cout << "Implementation name: " << impl->getImplName() << '\n'; }

} // namespace

void pimpl() {
    std::cout << "PIMPL Example" << '\n';
    AbstractInterface abs;
    abs.printImplName();
}