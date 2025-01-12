source_path = ./

files = sum_50_100_using_word print_10_to_1_using print_range_using string_input_test read_string_and_line string_comp string_size_comp string_sum_input \
		string_sum_input replace_string_to_x print_string_without_punct_chars read_int_to_vector read_string_to_vector print_vector_size_and_content \
		read_words_and_convert_to_upper_case read_numbers_and_calc_near_sum read_numbers_and_calc_sym_pair_sum read_numbers_and_calc_sym_pair_sum_with_iterators \
		cluster_grades test_array_init init_array_with_index_number init_and_copy_array_with_index_number init_and_copy_vector_with_index_number \
		array_values_to_zeroes_with_pointers compare_two_arrays compare_two_vectors compare_two_cpp_strings compare_two_c_strings copy_two_cstrings_to_third_cstring \
		init_int_vec_from_array copy_int_vec_to_array print_multi_dim_arr_without_typedef_auto_or_decltype print_multi_dim_arr_with_typedef print_multi_dim_arr_with_auto

bin_path = ../bin/
bin=$(addprefix $(bin_path), $(files))

INC = ../include
INC_PARAMS=$(foreach d, $(INC), -I$d)
CXXFLAGS=-O0 -Wall -std=c++14 -pedantic

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
