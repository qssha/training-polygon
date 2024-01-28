source_path = ./

files = unsigned_test check_type print_2m

bin_path = ../bin/
bin=$(addprefix $(bin_path), $(files))

INC = ../include
INC_PARAMS=$(foreach d, $(INC), -I$d)
CXXFLAGS=-O0 -Wall -std=c++14

all: $(bin)

$(bin_path)%: $(source_path)%.cpp
	$(CXX) $(INC_PARAMS) $< $(CXXFLAGS) -o $@

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
