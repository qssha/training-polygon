source_path = ./

files = unsigned_test check_type print_2m init_exercise_test ident_test scope_test pointer_exercise

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
