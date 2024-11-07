#include <iostream>
#include <stdexcept>

class invalidCharacterException : public std::exception {
    const char* what() const throw() {
        return "Invalid character exception: start is not a letter.";
    }
};

class invalidRangeException : public std::exception {
    const char* what() const throw() {
        return "Invalid range exception: target is not a letter.";
    }
};

char character(char start, int offset) {
    if (!((start >= 'A' && start <= 'Z') || (start >= 'a' && start <= 'z'))) {
        throw invalidCharacterException();
    }

    char target = start + offset;

    if ((start >= 'A' && start <= 'Z' && (target < 'A' || target > 'Z')) ||
        (start >= 'a' && start <= 'z' && (target < 'a' || target > 'z'))) {
        throw invalidRangeException();
    }

    return target;
}

int main() {
    try {
        std::cout << "character('a', 1): " << character('a', 1) << std::endl;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << "character('a', -1): ";
        character('a', -1);
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << "character('Z', -1): " << character('Z', -1) << std::endl;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << "character('?', 5): ";
        character('?', 5);
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << "character('A', 32): ";
        character('A', 32);
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
