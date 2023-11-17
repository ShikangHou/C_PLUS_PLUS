#include <iostream>
#include <thread>
#include <mutex>

std::mutex mu;

void thread_process(std::string name)
{
    // std::lock_guard<std::mutex> workLock(mu);
    std::unique_lock<std::mutex> workLock(mu);
    std::cout<<name<<" is working"<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout<<name<<" done work"<<std::endl;
    workLock.unlock();

}

int main(int argc, char *argv[])
{
    std::thread thread1(thread_process,"xiaoming");
    std::thread thread2(thread_process,"lihua");

    thread1.join();
    thread2.join();

    
    return 0;
}
