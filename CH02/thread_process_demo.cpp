/**
 * Thread that waste CPU cycles
 */

#include <thread>
#include <chrono>
#include <unistd.h>

void cpu_waster()
{
    printf("CPU Waster Process ID: %d\n", getpid());
    printf("CPU Waster Thread ID: %d\n", std::this_thread::get_id());
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main()
{
    // may return 0 when not able to detect
    const auto processor_count = std::thread::hardware_concurrency();
    printf("Processor count: %d\n", processor_count);

    printf("Main Process ID: %d\n", getpid());
    printf("Main Thread ID: %d\n", std::this_thread::get_id());
    std::thread thread1(cpu_waster);
    std::thread thread2(cpu_waster);
    while (true) // Keep the main thread alive "forever"
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return 0;
}