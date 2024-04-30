#include <memory>
#include <iostream>

class MyClass {
public:
    MyClass(int value) : m_value(value) {}
    void printValue() {
        std::cout << "Value: " << m_value << std::endl;
    }
private:
    int m_value;
};

int main() {
    std::shared_ptr<MyClass> ptr = std::make_shared<MyClass>(42);
    ptr->printValue();

    return 0;
}