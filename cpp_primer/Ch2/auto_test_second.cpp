#include <iostream>

int main() {
	const int i = 42;
	auto j = i; const auto &k = i; auto *p = &i;
	const auto j2 = i, &k2 = i;

	j = 1;
	//k = 1; error
	p = &j;
	//*p += 1; error

	std::cout << k2 << std::endl;

	return 0;
}
