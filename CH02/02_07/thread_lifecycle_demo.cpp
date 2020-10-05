/**
 * Two threads cooking soup
 */

#include <thread>
#include <chrono>

void chef_olivia()
{
    printf("Olivia started & waiting for sausage to thaw...\n");
    std::this_thread::sleep_for(std::chrono::seconds(3));
    printf("Olivia is done cooling sausage.\n");
}

int main()
{
    printf("Barron requests Olivia's help.\n");
    std::thread olivia(chef_olivia);

    printf(" Olivia is joinable ? %s\n", olivia.joinable() ? "true" : "false");

    printf("Barron continues cooking soup.\n");
    std::this_thread::sleep_for(std::chrono::seconds(1));

    printf(" Olivia is joinable ? %s\n", olivia.joinable() ? "true" : "false");

    printf("Barron patiently waits for olivia to finish and join...\n");
    olivia.join();

    printf(" Olivia is joinable ? %s\n", olivia.joinable() ? "true" : "false");

    printf("Barron and olivia are both done!\n");
    return 0;
}
