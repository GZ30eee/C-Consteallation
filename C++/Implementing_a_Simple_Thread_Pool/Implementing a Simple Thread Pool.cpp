#include <iostream>
#include <vector>
#include <thread>
#include <queue>
#include <functional>
#include <mutex>
#include <condition_variable>

class ThreadPool {
public:
   ThreadPool(size_t numThreads);
   
   template<class F>
   void enqueue(F&& f);

private:
   std::vector<std::thread> workers;
   
   std::queue<std::function<void()>> tasks;

   std::mutex queueMutex;
   
   std::condition_variable condition;

   bool stop;

};

// Constructor
ThreadPool::ThreadPool(size_t numThreads) : stop(false) {
   for (size_t i = 0; i < numThreads; ++i)
       workers.emplace_back([this]{
           for (;;) {
               std::function<void()> task;

               {  
                   std::unique_lock<std::mutex> lock(this->queueMutex);
                   this->condition.wait(lock, [this] { return this->stop || !this->tasks.empty(); });
                   if (this->stop && this->tasks.empty())
                       return;
                   task = std::move(this->tasks.front());
                   this->tasks.pop();
               }
               task();
           }
       });
}

// Enqueue function
template<class F>
void ThreadPool::enqueue(F&& f) {
   {  
       std::unique_lock<std::mutex> lock(queueMutex);
       tasks.emplace(std::forward<F>(f));
   }
   condition.notify_one();
}

// Destructor
ThreadPool::~ThreadPool() {
   {  
       std::unique_lock<std::mutex> lock(queueMutex);
       stop = true;
   }
   condition.notify_all();
   for (std::thread &worker: workers)
       worker.join();
}

int main() {
   ThreadPool pool(4); // Create a thread pool with 4 threads
   
   for (int i = 0; i < 10; ++i) {
       pool.enqueue([i]{
           std::cout << ""Task "" << i << "" is being executed.\n"";
       });
   }

   return 0;
}
