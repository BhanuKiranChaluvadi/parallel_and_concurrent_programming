/**
 * Two shoppers adding notes to a shared notepad
 */

#include <thread>

unsigned int garlic_count = 0;

void shopper()
{
    for (int i = 0; i < 10000000; i++)
        garlic_count++;
}

int main()
{
    std::thread barron(shopper);
    std::thread olivia(shopper);

    barron.join();
    olivia.join();

    printf("we should buy %u garlic.\n", garlic_count);
    return 0;
}
