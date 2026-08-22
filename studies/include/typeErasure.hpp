#include <memory>
#include <string>

class Object {
  public:
    template <typename T> Object(T &&obj) : object(std::make_shared<Model<T>>(std::forward<T>(obj))) {}

    [[nodiscard]] std::string getName() const { return object->getName(); }

    struct Concept { // (5)
        virtual ~Concept() {}
        [[nodiscard]] virtual std::string getName() const = 0;
    };

    template <typename T> // (6)
    struct Model : Concept {
        Model(const T &&t) : object(t) {}
        [[nodiscard]] std::string getName() const override { return object.getName(); }

      private:
        T object;
    };

    std::shared_ptr<const Concept> object;
};
