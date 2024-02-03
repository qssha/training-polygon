#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <vector>

#include "matrix.h"

template <typename T>
void fill_matrix(matrix<T>* matrix_to_fill)
{
	srand((unsigned) time(NULL));
	
	for (unsigned int i = 0; i < matrix_to_fill->get_height(); i++)
	{
		for (unsigned int j = 0; j < matrix_to_fill->get_width(); j++)
		{
			(*matrix_to_fill)(i, j) = rand() % 100;
		}
	}
}

template <typename T>
void print_matrix(matrix<T>* matrix_to_print)
{
	for (unsigned int i = 0; i < matrix_to_print->get_height(); i++)
	{
		for (unsigned int j = 0; j < matrix_to_print->get_width(); j++)
		{
			std::cout << (*matrix_to_print)(i, j) << " ";
		}
		std::cout << std::endl;
	}
}

template <typename T>
void calc_matrix(matrix<T>* matrix_to_calc)
{
	auto start = std::chrono::high_resolution_clock::now();
	#pragma omp parallel for
	for (unsigned int i = 0; i < matrix_to_calc->get_height(); i++)
	{
		for (unsigned int j = 0; j < matrix_to_calc->get_width(); j++)
		{
			(*matrix_to_calc)(i, j) *= 7;
			(*matrix_to_calc)(i, j) += 11;
		}
	}
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	std::cout << "Elapsed time: " << elapsed.count() << " s\n";
}

int main()
{
	unsigned int N = 1000000;

	auto start = std::chrono::high_resolution_clock::now();
	matrix<char>* p = new flat_array_matrix<char>(N, N / 1000);	
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	std::cout << "Allocation time: " << elapsed.count() << " s\n";

	//fill_matrix(p);
	//print_matrix(p);
	calc_matrix(p);
	//print_matrix(p);

	delete p;

	start = std::chrono::high_resolution_clock::now();
	p = new pointer_array_matrix<char>(N, N / 1000);	
	finish = std::chrono::high_resolution_clock::now();
	elapsed = finish - start;
	std::cout << "Allocation time: " << elapsed.count() << " s\n";

	//fill_matrix(p);
	//print_matrix(p);
	calc_matrix(p);
	//print_matrix(p);

	delete p;

}
