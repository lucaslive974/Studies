#include <iostream>
#include <memory>
#include <string>

/**
 * The Subsystem can accept requests either from the facade or client directly.
 * In any case, to the Subsystem, the Facade is yet another client, and it's not
 * a part of the Subsystem.
 */
class Subsystem1 {
  public:
    std::string operation1() const { return "Subsystem1: Ready!\n"; }
    // ...
    std::string operationN() const { return "Subsystem1: Go!\n"; }
};

/**
 * Some facades can work with multiple subsystems at the same time.
 */
class Subsystem2 {
  public:
    std::string operation1() const { return "Subsystem2: Get ready!\n"; }
    // ...
    std::string operationZ() const { return "Subsystem2: Fire!\n"; }
};

/**
 * The Facade class provides a simple interface to the complex logic of one or
 * several subsystems. The Facade delegates the client requests to the
 * appropriate objects within the subsystem. The Facade is also responsible for
 * managing their lifecycle. All of this shields the client from the undesired
 * complexity of the subsystem.
 */
class Facade {
  protected:
    std::unique_ptr<Subsystem1> subsystem1_;
    std::unique_ptr<Subsystem2> subsystem2_;
    /**
     * Depending on your application's needs, you can provide the Facade with
     * existing subsystem objects or force the Facade to create them on its own.
     */
  public:
    /**
     * In this case we will delegate the memory ownership to Facade Class
     */
    Facade(std::unique_ptr<Subsystem1> &&subsystem1 = nullptr, std::unique_ptr<Subsystem2> &&subsystem2 = nullptr) {
        this->subsystem1_ = subsystem1 ? std::move(subsystem1) : std::make_unique<Subsystem1>();
        this->subsystem2_ = subsystem2 ? std::move(subsystem2) : std::make_unique<Subsystem2>();
    }
    /**
     * The Facade's methods are convenient shortcuts to the sophisticated
     * functionality of the subsystems. However, clients get only to a fraction of
     * a subsystem's capabilities.
     */
    std::string Operation() {
        std::string result = "Facade initializes subsystems:\n";
        result += this->subsystem1_->operation1();
        result += this->subsystem2_->operation1();
        result += "Facade orders subsystems to perform the action:\n";
        result += this->subsystem1_->operationN();
        result += this->subsystem2_->operationZ();
        return result;
    }
};

/**
 * The client code works with complex subsystems through a simple interface
 * provided by the Facade. When a facade manages the lifecycle of the subsystem,
 * the client might not even know about the existence of the subsystem. This
 * approach lets you keep the complexity under control.
 */
void clientCode(Facade *facade) {
    // ...
    std::cout << facade->Operation();
    // ...
}
/**
 * The client code may have some of the subsystem's objects already created. In
 * this case, it might be worthwhile to initialize the Facade with these objects
 * instead of letting the Facade create new instances.
 */
int facade() {
    auto subsystem1 = std::make_unique<Subsystem1>();
    auto subsystem2 = std::make_unique<Subsystem2>();
    auto facade = std::make_unique<Facade>(std::move(subsystem1), std::move(subsystem2));

    clientCode(facade.get());

    return 0;
}