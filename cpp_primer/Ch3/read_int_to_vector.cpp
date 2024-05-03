#include <iostream>
#include <vector>
#include <string>

int main() {
	int temp_int;
	std::vector<int> vect_int;

	while (std::cin >> temp_int) {
		vect_int.push_back(temp_int);
	}

	for (auto &number: vect_int) {
		std::cout << number << " ";
	}

	std::cout << std::endl;

	return 0;
}
