source_path = ./

files := return_test hello_world number_mult test_comment_compilation \
	sum_50_100 print_10_to_1 print_range sum_50_100_for print_10_to_1_for \
	print_range_for sum_of_numbers get_count_of_input_numbers print_range_if_chap \
	sales_item_read_write_test read_and_sum_two_books read_multiply_books \
	count_sales_item sum_sales_items

bin_path = ../bin/
bin=$(addprefix $(bin_path), $(files))

INC = ../include
INC_PARAMS=$(foreach d, $(INC), -I$d)
CXXFLAGS=-O0 -Wall -std=c++14

all: $(bin)

$(bin_path)%: $(source_path)%.cpp | $(bin_path)
	$(CXX) $(INC_PARAMS) $< $(CXXFLAGS) -o $@

$(bin_path):
	mkdir -p $(bin_path)

format: 
	for file in $(files); do \
		clang-format -i -style='{BasedOnStyle: Google, IndentWidth: 4}' $$file.cpp; \
	done

lint: 
	for file in $(files); do \
		clang-tidy -checks=* $$file.cpp -- $(INC_PARAMS); \
	done

clean:
	rm -f $(bin)
