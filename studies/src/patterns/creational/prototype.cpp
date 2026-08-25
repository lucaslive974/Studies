#include "patterns.hpp"
#include <iostream>
#include <memory>
#include <string>

using Byte = unsigned char;

enum Type : Byte { PROTOTYPE_1 = 0, PROTOTYPE_2 };

class Prototype {
  protected:
    std::string prototype_name_;
    float prototype_field_;

  public:
    Prototype() {}
    Prototype(std::string &&prototype_name) : prototype_name_(std::move(prototype_name)) {}
    virtual ~Prototype() {}
    [[nodiscard]] virtual std::unique_ptr<Prototype> clone() const = 0;
    virtual void method(float prototype_field) {
        this->prototype_field_ = prototype_field;
        std::cout << "Call Method from " << prototype_name_ << " with field : " << prototype_field << '\n';
    }
};

class ConcretePrototype1 : public Prototype {
  private:
    float concrete_prototype_field1_;

  public:
    ConcretePrototype1(std::string &&prototype_name, float concrete_prototype_field)
        : Prototype(std::forward<std::string &&>(prototype_name)), concrete_prototype_field1_(concrete_prototype_field) {}

    [[nodiscard]] std::unique_ptr<Prototype> clone() const override { return std::make_unique<ConcretePrototype1>(*this); }
};

class ConcretePrototype2 : public Prototype {
  private:
    float concrete_prototype_field2_;

  public:
    ConcretePrototype2(std::string &&prototype_name, float concrete_prototype_field)
        : Prototype(std::forward<std::string &&>(prototype_name)), concrete_prototype_field2_(concrete_prototype_field) {}
    [[nodiscard]] std::unique_ptr<Prototype> clone() const override { return std::make_unique<ConcretePrototype2>(*this); }
};

#include <unordered_map>
class PrototypeFactory {
  private:
    std::unordered_map<Type, std::unique_ptr<Prototype>, std::hash<int>> prototypes_;

  public:
    PrototypeFactory() {
        prototypes_[Type::PROTOTYPE_1] = std::make_unique<ConcretePrototype1>("PROTOTYPE_1 ", 50.F);
        prototypes_[Type::PROTOTYPE_2] = std::make_unique<ConcretePrototype2>("PROTOTYPE_2 ", 60.F);
    }

    /**
     * Notice here that you just need to specify the type of the prototype you
     * want and the method will create from the object with this type.
     */
    std::unique_ptr<Prototype> createPrototype(Type type) { return prototypes_[type]->clone(); }
};

void Client(PrototypeFactory &prototype_factory) {
    std::cout << "Let's create a Prototype 1\n";

    std::unique_ptr<Prototype> prototype = prototype_factory.createPrototype(Type::PROTOTYPE_1);
    prototype->method(90);

    std::cout << "\n";

    std::cout << "Let's create a Prototype 2 \n";

    prototype = prototype_factory.createPrototype(Type::PROTOTYPE_2);
    prototype->method(10);
}

void prototype() {
    PrototypeFactory factory;
    Client(factory);
}