/**
 * Two threads chopping vegitables
 */

#include <thread>
#include <chrono>

bool chopping = true;

void vegetable_chopper(const char *name)
{
    unsigned int vegetable_counter = 0;
    while (chopping)
    {
        vegetable_counter++;
    }
    printf("%s chopped %u vegetables. \n", name, vegetable_counter);
}

int main()
{

    std::thread olivia(vegetable_chopper, "olivia");
    std::thread barron(vegetable_chopper, "barron");

    printf("Barron and olivia are chopping vegetables...\n");
    std::this_thread::sleep_for(std::chrono::seconds(1));
    chopping = false;
    olivia.join();
    barron.join();
    return 0;
}