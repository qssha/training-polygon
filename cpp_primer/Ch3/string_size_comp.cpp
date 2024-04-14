#include <iostream>
#include <string>

int main() {
	std::string first_string, second_string;
	std::cin >> first_string >> second_string;

	if (first_string.size() == second_string.size()) {
		std::cout << "Strings length is equal" << std::endl;
	} else {
		if (first_string.size() > second_string.size()) {
			std::cout << "First string is longer" << std::endl;
		} else {
			std::cout << "Second string is longer" << std::endl;
		}
	}

	return 0;
}
