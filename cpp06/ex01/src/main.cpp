#include <sstream>

#include "Serializer.hpp"

int main() {
    Data data;
    data.str = "Hello, World!";

    std::cout << "Let's first show the original values:\n";
    std::cout << "Original string: " << data.str << "\n";
    std::cout << "Original struct address: " << &data << "\n";

    std::cout << "\nNow let's serialize the struct:\n";
    uintptr_t serialized = Serializer::serialize(&data);
    std::cout << "Serialized struct: " << serialized << "\n";

    std::cout << "\nIf we convert this number to hex, we get:\n";
    std::stringstream ss;
    ss << std::hex << serialized;
    std::string hexStr = ss.str();
    std::cout << "Serialized struct in hex: " << hexStr << "\n";
    std::cout << "We can see this is the address of the struct, so the "
                 "serialize worked.\n";

    std::cout << "\nNow let's deserialize the struct:\n";
    Data* deserialized = Serializer::deserialize(serialized);
    std::cout << "Deserialized is a pointer to: " << deserialized << "\n";

    std::cout << "And if we try to access the string, we get:\n";
    std::cout << "Deserialized string: " << deserialized->str << "\n";

    std::cout << "\nNow let's serialize the struct again and deserialize it "
                 "again, just to be sure:\n";
    serialized = Serializer::serialize(&data);
    std::cout << "Serialized struct: " << serialized << "\n";
    ss.str("");
    ss << std::hex << serialized;
    hexStr = ss.str();
    std::cout << "Serialized struct in hex: " << hexStr << std::endl;

    deserialized = Serializer::deserialize(serialized);
    std::cout << "Deserialized is a pointer to: " << deserialized << "\n";
    std::cout << "Deserialized string: " << deserialized->str << "\n";
}
