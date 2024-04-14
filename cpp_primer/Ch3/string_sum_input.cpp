#include <iostream>
#include <string>

int main() {
	std::string total, temp;
	while (getline(std::cin, temp)) {
		if (!temp.empty()) {
			total += temp + " ";
		} else {
			break;
		}
	}
	
	std::cout << "Final string is " << total << std::endl;

	return 0;
}
