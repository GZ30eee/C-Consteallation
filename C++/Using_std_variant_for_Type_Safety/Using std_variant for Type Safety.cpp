#include <iostream>
#include <variant>
#include <string>

using VarType = std::variant<int, float, std::string>;

void processVariant(const VarType& var) {
    std::visit([](auto&& arg) { 
        std::cout << arg << '\n'; 
    }, var);
}

int main() {
    VarType v1 = 42;
    VarType v2 = 3.14f;
    VarType v3 = ""Hello, World!"";
    
    processVariant(v1);
    processVariant(v2);
    processVariant(v3);

    return 0;
}
