#include <iostream>

int main() {

	int int_value = {5};
	int* int_pointer = &int_value;
	int* int_array = new int(2);

	int_array[0] = 1;
	*(int_array + 1) = 2;


    std::cout << int_pointer << " " <<  *int_pointer << std::endl;
	std::cout << int_array << " " << int_array[0] << std::endl;

	*int_pointer += 10;
	*int_array += 1;

    std::cout << int_pointer << " " <<  *int_pointer << std::endl;
	std::cout << int_array + 1 << " " << int_array[0] << std::endl;

	delete int_array;
	
	return 0;
}
