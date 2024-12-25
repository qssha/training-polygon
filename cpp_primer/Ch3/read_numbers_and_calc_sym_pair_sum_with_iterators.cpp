#include <iostream>
#include <vector>

int main() {
	std::vector<int> vec_of_numbers;
	int temp_number;

	while (std::cin >> temp_number) {
		vec_of_numbers.push_back(temp_number);
	}

    auto vec_mid = vec_of_numbers.cbegin() + (vec_of_numbers.cend() - vec_of_numbers.cbegin()) / 2;

	for (auto current_number = vec_of_numbers.cbegin(); current_number != vec_mid; ++current_number) {
		std::cout << *current_number + *(vec_of_numbers.cend() - 1 - current_number + vec_of_numbers.cbegin()) << " ";
	}

	if (vec_of_numbers.size() % 2 != 0) {
		std::cout << *vec_mid;
	}

	std::cout << std::endl;

	return 0;
}
