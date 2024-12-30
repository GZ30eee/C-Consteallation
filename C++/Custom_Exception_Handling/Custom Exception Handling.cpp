#include <iostream>
#include <stdexcept>

class MyException : public std::runtime_error {
public:
    MyException(const std::string& message) : std::runtime_error(message) {}
};

void riskyFunction() {
    throw MyException("Something went wrong!");
}

int main() {
    try {
        riskyFunction();
    } catch (const MyException& e) {
        std::cout << "Caught exception: " << e.what() << '\n';
    }
    
    return 0;
}
