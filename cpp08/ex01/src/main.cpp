#include "Span.hpp"

void subjectTests(void) {
    std::cout << "SUBJECT TESTS\n\n";
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "... Printing Span sp: " << sp << '\n';
    std::cout << "Shortest span: " << sp.shortestSpan() << '\n';
    std::cout << "Longest span: " << sp.longestSpan() << '\n';
}

void unitarySpanTests(void) {
    std::cout << "UNITARY SPAN (1) TESTS\n\n";
    Span sp(1);

    std::cout << "... Adding a number to an empty Span sp:\n";
    sp.addNumber(42);
    std::cout << "Span sp: " << sp << '\n';
    std::cout << '\n';

    std::cout << "... Adding a number to a full Span sp:\n";
    try {
        sp.addNumber(21);
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
    std::cout << '\n';

    std::cout << "... Testing shortest and longest spans:\n";
    try {
        std::cout << "Shortest span: " << sp.shortestSpan() << '\n';
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
    try {
        std::cout << "Longest span: " << sp.longestSpan() << '\n';
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
}

void shortSpanTests(void) {
    std::cout << "SHORT SPAN (10) TESTS\n\n";
    Span sp(10);

    std::cout << "... Testing inclusion of a range of numbers:\n";
    int arr[] = {42, 21, 84, 24, 12, 48};
    std::vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));

    sp.addRange(v.begin(), v.end());
    std::cout << "Span sp: " << sp << '\n';
    std::cout << '\n';

    std::cout << "... Filling array:\n";
    sp.fillSpan();
    std::cout << "Span sp: " << sp << '\n';
    std::cout << '\n';

    std::cout
        << "... Testing inclusion of a range of numbers exceeding capacity:\n";
    try {
        sp.addRange(v.begin(), v.end());
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
    std::cout << '\n';

    std::cout << "... Randomizing array:\n";
    sp.randomizeSpan(1000);
    std::cout << "Span sp: " << sp << '\n';
    std::cout << '\n';

    std::cout << "... Testing shortest and longest spans:\n";
    std::cout << "Shortest span: " << sp.shortestSpan() << '\n';
    std::cout << "Longest span: " << sp.longestSpan() << '\n';
    std::cout << '\n';

    std::cout << "... Printing sorted span to improve readability:\n";
    std::cout << "Span sp: ";
    std::sort(sp.getRange().begin(), sp.getRange().end());
    std::cout << sp << '\n';
}

void longSpanTests(void) {
    std::cout << "LONG SPAN (30000) TESTS\n\n";
    Span sp(30000);

    std::cout << "... Filling array and randomizing\n";
    sp.fillSpan();
    sp.randomizeSpan();
    std::cout << '\n';

    std::cout << "Smallest number: "
              << *std::min_element(sp.getRange().begin(), sp.getRange().end())
              << '\n';
    std::cout << "Largest number: "
              << *std::max_element(sp.getRange().begin(), sp.getRange().end())
              << '\n';
    std::cout << '\n';

    std::cout << "... Testing shortest and longest spans:\n";
    std::cout << "Shortest span: " << sp.shortestSpan() << '\n';
    std::cout << "Longest span: " << sp.longestSpan() << '\n';
}

int main(void) {
    subjectTests();
    std::cout << "\n-----------------------------------------------------------"
                 "---------------------\n\n";
    unitarySpanTests();
    std::cout << "\n-----------------------------------------------------------"
                 "---------------------\n\n";
    shortSpanTests();
    std::cout << "\n-----------------------------------------------------------"
                 "---------------------\n\n";
    longSpanTests();
}
