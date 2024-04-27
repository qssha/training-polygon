#include <iostream>
#include <string>
#include <cctype>

int main() {
	std::string input_string, string_without_punct_chars;
	std::getline(std::cin, input_string);
	
	for (auto &c: input_string) {
		if (!ispunct(c)) {
			string_without_punct_chars += c;
		}
	}

	std::cout << string_without_punct_chars << std::endl;

	return 0;
}
