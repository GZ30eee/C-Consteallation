#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<std::pair<int, std::string>> vec = {{3, "three"}, {1, "one"}, {2, "two"}};

    std::sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
        return a.first < b.first; // Sort by first element
    });

    for (const auto& p : vec) {
        std::cout << p.first << ": " << p.second << '\n';
    }

    return 0;
}
