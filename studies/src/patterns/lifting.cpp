#include "patterns.hpp"
#include <iostream>

// We have a templated function
template <typename T> void TemplateFunction(T &t) {
    std::cout << "TemplateFunction called with type: " << typeid(T).name() << std::endl;
};

template <typename T, typename Fn> void algorithm(T t, Fn f) { f(t); }

void lifting() {
    /*
     Template functions arent first class citizens, so we need to lift it into a function
     object
    */
    algorithm(42, [](auto &t) { TemplateFunction(t); });
    algorithm(std::string("Hello"), [](auto &t) { TemplateFunction(t); });
}