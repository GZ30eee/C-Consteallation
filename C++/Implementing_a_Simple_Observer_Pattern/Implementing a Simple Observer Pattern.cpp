#include <iostream>
#include <vector>
#include <algorithm>

class Observer;

class Subject {
public:
    void attach(Observer* observer) {
        observers.push_back(observer);
    }

    void notify() {
        for (auto* observer : observers) {
            observer->update();
        }
    }

private:
    std::vector<Observer*> observers;
};

class Observer {
public:
    virtual void update() = 0;
};

class ConcreteObserver : public Observer {
public:
    void update() override {
        std::cout << ""Observer notified!\n"";
    }
};

int main() {
    Subject subject;
    
   ConcreteObserver observer1;
    
   subject.attach(&observer1);
    
   subject.notify(); // Notify all observers
    
   return 0;
}
