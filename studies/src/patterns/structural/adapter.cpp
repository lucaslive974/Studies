#include "patterns.hpp"
#include <algorithm>
#include <iostream>
#include <memory>

/**
 * The Target defines the domain-specific interface used by the client code.
 */
class Target {
  public:
    virtual ~Target() = default;
    [[nodiscard]] virtual std::string request() const { return "Target: The default target's behavior."; }
};

/**
 * The Adaptee contains some useful behavior, but its interface is incompatible
 * with the existing client code. The Adaptee needs some adaptation before the
 * client code can use it.
 */
class Adaptee {
  public:
    [[nodiscard]] std::string specificRequest() const { // NOLINT(readability-convert-member-functions-to-static)
        return ".eetpadA eht fo roivaheb laicepS";
    }
};

/**
 * The Adapter makes the Adaptee's interface compatible with the Target's
 * interface.
 */
class Adapter : public Target {
  private:
    std::shared_ptr<Adaptee> adaptee_;

  public:
    Adapter(std::shared_ptr<Adaptee> adaptee) : adaptee_(std::move(adaptee)) {}
    [[nodiscard]] std::string request() const override {
        std::string toReverse = this->adaptee_->specificRequest();
        std::ranges::reverse(toReverse);
        return "Adapter: (TRANSLATED) " + toReverse;
    }
};

/**
 * The client code supports all classes that follow the Target interface.
 */
void clientCode(const Target *target) { std::cout << target->request(); }

void adapter() {
    std::cout << "Client: I can work just fine with the Target objects:\n";

    auto target = std::make_unique<Target>();
    clientCode(target.get());
    std::cout << "\n\n";

    auto adaptee = std::make_shared<Adaptee>();
    std::cout << "Client: The Adaptee class has a weird interface. See, I don't understand it:\n";
    std::cout << "Adaptee: " << adaptee->specificRequest();
    std::cout << "\n\n";
    std::cout << "Client: But I can work with it via the Adapter:\n";

    auto adapter = std::make_unique<Adapter>(adaptee);

    clientCode(adapter.get());
    std::cout << "\n";
}