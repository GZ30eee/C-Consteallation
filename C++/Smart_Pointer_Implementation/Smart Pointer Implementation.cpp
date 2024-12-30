#include <iostream>
#include <memory>

class Resource {
public:
    Resource() { std::cout << "Resource acquired.\n"; }
    ~Resource() { std::cout << "Resource released.\n"; }
};

void useResource() {
    std::unique_ptr<Resource> resPtr = std::make_unique<Resource>();
    // Resource will be automatically released when resPtr goes out of scope
}

int main() {
    useResource();
    return 0;
}
