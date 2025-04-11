#include "Zombie.hpp"

int main() {
    int hordeSize = HORDE_SIZE;
    std::string name = HORDE_NAME;

    std::cout << "Allocating Zombie horde of " << hordeSize
              << " zombies on the heap:\n";
    Zombie* horde = zombieHorde(hordeSize, name);
    std::cout << '\n';

    std::cout << "Horde is announcing itself:\n";
    for (int i = 0; i < hordeSize; i++) {
        horde[i].announce();
    }
    std::cout << '\n';

    std::cout << "Deallocating Zombie horde:\n";
    delete[] horde;

    return 0;
}
