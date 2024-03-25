#include <iostream>
#include <Sales_data.h>

int main () {
	Sales_data curr_data, total_data;
	double price = 0;

	if (std::cin >> total_data.bookNo >> total_data.units_sold >> price) {
		total_data.revenue = total_data.units_sold * price;

		while (std::cin >> curr_data.bookNo >> curr_data.units_sold >> price) {
			if (total_data.bookNo == curr_data.bookNo) {
				total_data.units_sold += curr_data.units_sold;
				double curr_revenue = curr_data.units_sold * price;
				total_data.revenue += curr_revenue;
			} else {
				std::cout << total_data.bookNo << " " << total_data.units_sold << " " << total_data.revenue << " ";

				if (total_data.units_sold != 0) {
					std::cout << total_data.revenue / total_data.units_sold << std::endl;
				} else {
					std::cout << "(no sales)" << std::endl;
				}

				total_data.bookNo = curr_data.bookNo;
				total_data.units_sold = curr_data.units_sold;
				total_data.revenue = total_data.units_sold * price;
			}
		}

		std::cout << total_data.bookNo << " " << total_data.units_sold << " " << total_data.revenue << " ";
		if (total_data.units_sold != 0) {
			std::cout << total_data.revenue / total_data.units_sold << std::endl;
		} else {
			std::cout << "(no sales)" << std::endl;
		}

		return 0;
	} else {
		std::cerr << "Wrong data!" << std::endl;
		return -1;
	}
}
