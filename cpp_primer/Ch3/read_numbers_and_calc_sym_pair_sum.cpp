#include <iostream>
#include <vector>

int main() {
	std::vector<int> vec_of_numbers;
	int temp_number;

	while (std::cin >> temp_number) {
		vec_of_numbers.push_back(temp_number);
	}

	for (size_t i = 0; i < vec_of_numbers.size() / 2; i++) {
		std::cout << vec_of_numbers[i] + vec_of_numbers[vec_of_numbers.size() - 1 - i] << " ";
	}

	if (vec_of_numbers.size() % 2 != 0) {
		std::cout << vec_of_numbers[vec_of_numbers.size() / 2];
	}

	std::cout << std::endl;

	return 0;
}
