#include <iostream>
#include <string>

int main() {
	/*
	std::string s;
	std::cin >> s;
	std::cout << s << std::endl;
	*/

	std::string s;
	getline(std::cin, s);
	std::cout << s << std::endl;

	return 0;
}
