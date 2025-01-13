#include <iostream>
#include <string>
#include <vector>

void split_string_to_vector(std::vector<std::string>& string_vector, const std::string& string_to_split, const std::string& delim) {
    std::size_t index = string_to_split.find(delim);
    std::size_t left_pos_index;

    if (index == 0) {
        left_pos_index = delim.size();
        index = string_to_split.find(delim, left_pos_index);
    } else {
        left_pos_index = 0;
    }

    while (index != -1) {
        if (left_pos_index != index) {
            string_vector.emplace_back(string_to_split.substr(left_pos_index, index - left_pos_index));
        }

        left_pos_index = index + delim.size();

        index = string_to_split.find(delim, index + delim.size());
    }

    if (left_pos_index < string_to_split.size()) {
        string_vector.emplace_back(string_to_split.substr(left_pos_index));
    }
}
