#include <iostream>
#include <string>
#include <vector>
#include <cctype>

int main() {
	std::vector<std::string> vec_of_words;
	std::string temp_string;

	while (std::cin >> temp_string) {
		vec_of_words.push_back(temp_string);
	}

	for (std::string& word : vec_of_words) {
		for (char& c : word) {
			c = std::toupper(c);
		}	
	}

	size_t i = 0;
	for (; i < vec_of_words.size(); i++) {
		std::cout << vec_of_words[i] << " ";

		if (i != 0 && i % 8 == 0) {
			std::cout << std::endl;
		}
	}

	if (i != 0 && (i - 1) % 8 != 0) {
    	std::cout << std::endl;
	}
	
	return 0;
}
