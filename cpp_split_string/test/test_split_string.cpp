#include <split_string.h>
#include <gtest/gtest.h>

TEST(basic_tests, empty_test) {
    std::vector<std::string> first_vec, second_vec;
    split_string_to_vector(first_vec, "fff", "f");
    EXPECT_EQ(first_vec, second_vec);
}

TEST(basic_tests, simple_split) {
    std::vector<std::string> first_vec, second_vec{"dd", "d"};
    split_string_to_vector(first_vec, "fddfdf", "f");
    EXPECT_EQ(first_vec, second_vec);
}

TEST(basic_tests, split_starts_with_delim) {
    std::vector<std::string> first_vec, second_vec{"dd"};
    split_string_to_vector(first_vec, "fdd", "f");
    EXPECT_EQ(first_vec, second_vec);
}

TEST(basic_tests, split_ends_with_delim) {
    std::vector<std::string> first_vec, second_vec{"dd"};
    split_string_to_vector(first_vec, "ddf", "f");
    EXPECT_EQ(first_vec, second_vec);
}

int main() {
    ::testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}



