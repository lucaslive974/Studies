#include "patterns.hpp"
#include <iostream>
#include <string>

class Singleton {
  private:
    std::string name;
    Singleton(std::string &&n) : name(std::move(n)) {};

  public:
    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;
    Singleton(Singleton &&) = delete;
    Singleton &operator=(Singleton &&) = delete;

    static Singleton &getInstance() {
        static Singleton instance{"S1"};
        return instance;
    };

    void printName() { std::cout << std::format("Singleton Name: {}\n", name); }
};

void singleton() {
    auto *s1 = &Singleton::getInstance();
    auto *s2 = &Singleton::getInstance();

    s1->printName();
    std::cout << std::format("Both point to the same object address: {}\n", s1 == s2);
    std::cout << std::format("The pointers are two different addresses: {}\n", &s1 != &s2);
}