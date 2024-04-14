#include <iostream>
#include <string>

int main() {
	std::string first_string, second_string;
	std::cin >> first_string >> second_string;

	if (first_string == second_string) {
		std::cout << "Strings are equal" << std::endl;
	} else {
		if (first_string > second_string) {
			std::cout << "First string is bigger" << std::endl;
		} else {
			std::cout << "Second string is bigger" << std::endl;
		}
	}

	return 0;
}
