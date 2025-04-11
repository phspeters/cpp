#include <cctype>
#include <iostream>

int main(int argc, char *argv[]) {
    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << '\n';
        return 0;
    }

    std::string input;
    for (int i = 1; i < argc; i++) {
        input += argv[i];
    }

    for (std::string::size_type i = 0; i < input.length(); i++) {
        input[i] = std::toupper(input[i]);
    }

    std::cout << input << '\n';

    return 0;
}
