#include <iostream>
#include <thread>
#include <vector>
#include <future>
#include <mutex>
#include<algorithm>

class Vehicle
{
public:
    Vehicle(int id) : _id(id) {}
    int getID(){return _id;}

private:
    int _id;
};

class WaitingVehicles
{
public:
    WaitingVehicles() {}

    // getters / setters
    void printSize()
    {
        _mutex.lock();
        std::cout << "#vehicles = " << _vehicles.size() << std::endl;
        _mutex.unlock();
    }

    // typical behaviour methods
    void pushBack(Vehicle &&v)
    {
        while (1){
            for (size_t i=0; i<3; ++i){
                if (_mutex.try_lock_for(std::chrono::milliseconds(1))){
                    _vehicles.emplace_back(std::move(v)); // data race would cause an exception
                    std::this_thread::sleep_for(std::chrono::milliseconds(3));
                    _mutex.unlock();
                    return;
                } else {
                    std::cout << "trial failed for id " << v.getID() << std::endl;
                }
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }

private:
    std::vector<Vehicle> _vehicles; // list of all vehicles waiting to enter this intersection
    std::timed_mutex _mutex;
};

int main()
{
    std::shared_ptr<WaitingVehicles> queue(new WaitingVehicles); 
    std::vector<std::future<void>> futures;
    for (int i = 0; i < 1000; ++i)
    {
        Vehicle v(i);
        futures.emplace_back(std::async(std::launch::async | std::launch::deferred, &WaitingVehicles::pushBack, queue, std::move(v)));
    }

    std::for_each(futures.begin(), futures.end(), [](std::future<void> &ftr) {
        ftr.wait();
    });

    queue->printSize();

    return 0;
}
