#include <iostream>
#include <typeinfo>

int main() {
	int i = 0, &r = i;
	auto a = r;

	const int ci = i, &cr = ci;

	auto b = ci;
	auto c = cr;
	auto d = &i;
	auto e = &ci;
	
	auto &g = ci;

	std::cout << "i = " << i << std::endl;
	std::cout << "r = " << r << std::endl;
	std::cout << "ci = " << ci << std::endl;
	std::cout << "cr = " << cr << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;
	std::cout << "e = " << e << std::endl;
	std::cout << "g = " << g << std::endl;

	std::cout << "######" << std::endl;

	a = 42;
	b = 42;
	c = 42;
 	//d = 42;
	//e = 42;
	//g = 42;

	std::cout << "i = " << i << std::endl;
	std::cout << "r = " << r << std::endl;
	std::cout << "ci = " << ci << std::endl;
	std::cout << "cr = " << cr << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;
	std::cout << "e = " << e << std::endl;
	std::cout << "g = " << g << std::endl;

	return 0;
}
