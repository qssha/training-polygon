#include <iostream>
#include <vector>
#include <string>

template<typename T>
void print_vector_size_and_content(const std::vector<T>& vec_to_print) {
	std::cout << "Vector size is " << vec_to_print.size() << std::endl;
	std::cout << "Vector content: ";

	for (auto& vec_elem: vec_to_print) {
		std::cout << vec_elem << " ";
	}

	std::cout << std::endl;
}

int main() {
	std::vector<int> v1;
	std::vector<int> v2(10);
	std::vector<int> v3(10, 42);
	std::vector<int> v4{10};
	std::vector<int> v5{10, 42};
	std::vector<std::string> v6{10};
	std::vector<std::string> v7{10, "hi"};

	print_vector_size_and_content(v1);
	print_vector_size_and_content(v2);
	print_vector_size_and_content(v3);
	print_vector_size_and_content(v4);
	print_vector_size_and_content(v5);
	print_vector_size_and_content(v6);
	print_vector_size_and_content(v7);

	return 0;
}
