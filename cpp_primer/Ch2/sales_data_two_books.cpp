#include <iostream>
#include <Sales_data.h>

int main () {
	Sales_data first_book, second_book;
	double price = 0;

    std::cin >> first_book.bookNo >> first_book.units_sold >> price;
	first_book.revenue = first_book.units_sold * price;

    std::cin >> second_book.bookNo >> second_book.units_sold >> price;
	second_book.revenue = second_book.units_sold * price;

	if (first_book.bookNo == second_book.bookNo) {
		unsigned totalCnt = first_book.units_sold + second_book.units_sold;
		double totalRevenue = first_book.revenue + second_book.revenue;

		std::cout << first_book.bookNo << " " << totalCnt << " " << totalRevenue << " ";
		if (totalCnt != 0) {
			std::cout << totalRevenue / totalCnt << std::endl;
		} else {
			std::cout << "(no sales)" << std::endl;
		}
		return 0;
	} else {
		std::cerr << "Data must refer to same ISBN" << std::endl;
		return -1;
	}

}
