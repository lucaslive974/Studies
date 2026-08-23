#include "patterns.hpp"
#include <iostream>
#include <memory>
#include <string>

/**
 * Visitor interface
 */
class ComponentA;
class ComponentB;

class Visitor {
  public:
    virtual void visitComponentA(const ComponentA *ele) const = 0;
    virtual void visitComponentB(const ComponentB *ele) const = 0;
};

class Component {
  public:
    virtual void accept(Visitor *visitor) const = 0;
};

class ComponentA : public Component {
  public:
    void accept(Visitor *visitor) const override { visitor->visitComponentA(this); };
    auto specialMethodOfComponentA() const -> std::string { return "A"; }
};

class ComponentB : public Component {
  public:
    void accept(Visitor *visitor) const override { visitor->visitComponentB(this); };
    auto specialMehthodOfComponentB() const -> std::string { return "B"; };
};

class Visitor1 : public Visitor {
  public:
    void visitComponentA(const ComponentA *ele) const override {
        std::cout << ele->specialMethodOfComponentA() << " + Visitor1\n";
    };

    void visitComponentB(const ComponentB *ele) const override {
        std::cout << ele->specialMehthodOfComponentB() << " + Visitor1\n";
    }
};

class Visitor2 : public Visitor {
  public:
    void visitComponentA(const ComponentA *ele) const override {
        std::cout << ele->specialMethodOfComponentA() << " + Visitor2\n";
    };

    void visitComponentB(const ComponentB *ele) const override {
        std::cout << ele->specialMehthodOfComponentB() << " + Visitor2\n";
    }
};

void clientCode(std::array<std::shared_ptr<Component>, 2> &components, const std::shared_ptr<Visitor> &visitor) {
    for (const auto &component : components) {
        component->accept(visitor.get());
    }
}

void visitor() {
    std::array<std::shared_ptr<Component>, 2> components = {std::make_shared<ComponentA>(), std::make_shared<ComponentB>()};
    std::cout << "The client code works with all visitors by the base Visitor interface:\n";
    auto visitor1 = std::make_shared<Visitor1>();
    clientCode(components, visitor1);

    std::cout << "\nIt allows the same client code to work with different types of visitors:\n";
    auto visitor2 = std::make_shared<Visitor2>();
    clientCode(components, visitor2);
}