#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() {
    {
        std::cout << "TESTING DERIVED CLASSES AS OBJECTS\n";
        std::cout << "Instantiating Animal, Cat, and Dog objects\n";
        const Animal animal;
        const Cat cat;
        const Dog dog;
        const WrongAnimal wrongAnimal;
        const WrongCat wrongCat;
        std::cout << '\n';

        std::cout << "Calling makeSound() on each object\n";
        std::cout << "The Cat goes: ";
        cat.makeSound();
        std::cout << "The Dog goes: ";
        dog.makeSound();
        std::cout << "The Animal goes: ";
        animal.makeSound();
        std::cout << "The WrongCat goes: ";
        wrongCat.makeSound();
        std::cout << "The WrongAnimal goes: ";
        wrongAnimal.makeSound();
        std::cout << '\n';

        std::cout << "--> Everything works as expected, as each object is "
                     "instantiated as its respective class\n";
        std::cout << '\n';
    }
    {
        std::cout << "\n-------------------------------------------------------"
                     "-------------------------\n";
        std::cout << "\nTESTING DERIVED CLASSES AS BASE CLASS OBJECTS\n";
        std::cout << "Instantiating Animal, Cat, and Dog objects as Animal\n";
        const Animal animal = Animal();
        const Animal cat = Cat();
        const Animal dog = Dog();
        const WrongAnimal wrongAnimal = WrongAnimal();
        const WrongAnimal wrongCat = WrongCat();
        std::cout << '\n';

        std::cout << "Calling makeSound() on each object\n";
        std::cout << "The Cat goes: ";
        cat.makeSound();
        std::cout << "The Dog goes: ";
        dog.makeSound();
        std::cout << "The Animal goes: ";
        animal.makeSound();
        std::cout << "The WrongCat goes: ";
        wrongCat.makeSound();
        std::cout << "The WrongAnimal goes: ";
        wrongAnimal.makeSound();
        std::cout << '\n';

        std::cout
            << "--> Notice that the makeSound() function of the base class is "
               "called for each object, as they are instantiated as the base "
               "class and as such, the derived class is sliced\n";
        std::cout << '\n';
    }
    std::cout << "\n-----------------------------------------------------------"
                 "---------------------\n";
    std::cout << "\nTESTING DERIVED CLASSES AS BASE CLASS POINTERS\n";
    std::cout << "Instantiating Animal, Cat, and Dog objects as 'Animal *'\n";
    const Animal *animal = new Animal();
    Animal *cat = new Cat();
    const Animal *dog = new Dog();
    std::cout << '\n';

    std::cout << "Calling makeSound() on each object\n";
    std::cout << "The " << cat->getType() << " goes: ";
    cat->makeSound();
    std::cout << "The " << dog->getType() << " goes: ";
    dog->makeSound();
    std::cout << "The " << animal->getType() << " goes: ";
    animal->makeSound();
    std::cout << '\n';

    std::cout << "--> Because the makeSound() function is virtual, the correct "
                 "function is called for each object using the vtable\n";
    std::cout << '\n';

    std::cout << "We can see that the Animal and Cat objects are 8 bytes "
                 "larger than the WrongAnimal and WrongCat objects, "
                 "respectively, because they have a vtable pointer.\n";
    std::cout << "Size of Animal: " << sizeof(Animal) << '\n';
    std::cout << "Size of WrongAnimal: " << sizeof(WrongAnimal) << '\n';
    std::cout << "Size of Cat: " << sizeof(Cat) << '\n';
    std::cout << "Size of WrongCat: " << sizeof(WrongCat) << '\n';
    std::cout << '\n';

    std::cout
        << "But we can still use the scope resolution operator (::) to call "
           "the makeSound() function of the Animal class, if we'd like\n";
    std::cout << "The " << cat->getType() << " goes: ";
    cat->Animal::makeSound();
    std::cout << "The " << dog->getType() << " goes: ";
    dog->Animal::makeSound();
    std::cout << "The " << animal->getType() << " goes: ";
    animal->Animal::makeSound();
    std::cout << '\n';

    std::cout << "--> This is because the scope resolution operator provides "
                 "static binding to the base class's implementation, rather "
                 "than using dynamic dispatch through the vtable.\n";
    std::cout << '\n';

    std::cout << "Deleting the Animal, Cat, and Dog objects\n";
    delete animal;
    delete cat;
    delete dog;
    std::cout << '\n';

    std::cout << "Instantiating a WrongAnimal and WrongCat objects as "
                 "'WrongAnimal *'\n";
    const WrongAnimal *wrongAnimal = new WrongAnimal();
    const WrongAnimal *wrongCat = new WrongCat();
    std::cout << '\n';

    std::cout << "Calling makeSound() on each object\n";
    std::cout << "The " << wrongCat->getType() << " goes: ";
    wrongCat->makeSound();
    std::cout << "The " << wrongAnimal->getType() << " goes: ";
    wrongAnimal->makeSound();
    std::cout << '\n';

    std::cout << "--> Because the makeSound() function is not virtual, the "
                 "makeSound() function of the base class is called for each "
                 "object, as they are pointers to the base class.\n";
    std::cout << '\n';

    std::cout << "Deleting the WrongAnimal and WrongCat objects\n";
    delete wrongAnimal;
    delete wrongCat;

    return 0;
}
