#include <iostream>
#include <vector>
#include <string>

int main() {
	std::string temp_str;
	std::vector<std::string> vect_str;

	while (std::cin >> temp_str) {
		vect_str.push_back(temp_str);
	}

	for (auto &str: vect_str) {
		std::cout << str << " ";
	}

	std::cout << std::endl;

	return 0;
}
