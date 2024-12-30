#include <iostream>
#include <thread>
#include <vector>

void printNumbers(int threadId) {
    for (int i = 1; i <= 5; ++i) {
        std::cout << "Thread " << threadId << ": " << i << '\n';
    }
}

int main() {
    const int numThreads = 3;
    std::vector<std::thread> threads;

    for (int i = 0; i < numThreads; ++i) {
        threads.emplace_back(printNumbers, i + 1);
    }

    for (auto& t : threads) {
        t.join(); // Wait for all threads to finish
    }

    return 0;
}
