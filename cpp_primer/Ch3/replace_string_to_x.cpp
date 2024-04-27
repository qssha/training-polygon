#include <iostream>
#include <string>

int main() {
	std::string input_string;

	std::getline(std::cin , input_string);
	std::string input_string_backup = input_string;

	for (char &c: input_string) {
		c = 'X';
	}

	std::cout << input_string << std::endl;
	input_string = input_string_backup;
	// std::string::size_type == size_t?
    // std::cout << sizeof(std::string::size_type) << " " << sizeof(decltype(input_string.size())) << " " << sizeof(size_t) << std::endl;
	size_t index = 0;

	while (index != input_string.size()) {
		input_string[index] = 'X';
		++index;
	}

	std::cout << input_string << std::endl;
	input_string = input_string_backup;
	index = 0;

	for (; index != input_string.size(); ++index) {
		input_string[index] = 'X';
	}

	std::cout << input_string << std::endl;

	return 0;
}
