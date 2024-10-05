#include <iostream>
#include <vector>

int main() {
	std::vector<int> vec_of_numbers;
	int temp_number;

	while (std::cin >> temp_number) {
		vec_of_numbers.push_back(temp_number);
	}

	if (vec_of_numbers.size() == 1) {
		std::cout << vec_of_numbers[0] << std::endl;
	} else if (vec_of_numbers.size() == 2) {
		int sum_of_two = vec_of_numbers[0] + vec_of_numbers[1];
		std::cout << sum_of_two << " " << sum_of_two << std::endl;
	} else {
		size_t i = 1;
		std::cout << vec_of_numbers[i - 1] + vec_of_numbers[i] << " ";
     	for (; i < vec_of_numbers.size() - 1; i++) {
			std::cout << vec_of_numbers[i - 1] + vec_of_numbers[i] + vec_of_numbers[i + 1] << " ";	
     	}
		std::cout << vec_of_numbers[i - 1] + vec_of_numbers[i] << std::endl;
	}


	return 0;
}
