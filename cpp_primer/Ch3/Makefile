source_path = ./

files = sum_50_100_using_word print_10_to_1_using print_range_using string_input_test read_string_and_line string_comp string_size_comp string_sum_input \
		string_sum_input replace_string_to_x print_string_without_punct_chars

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
