#define CATCH_CONFIG_MAIN
#include "../common/catch.hpp"
#include "file_utils.h"

int MaxCalories(const std::vector<std::string> &nums) {
    uint32_t max_cal = 0;
    uint32_t accum = 0;
    for (auto &x : nums) {
        if (x == "") {
            accum = 0;
        } else {
            accum += stoi(x);
            max_cal = std::max(accum, max_cal);
        }
    }
    return max_cal;
}

int MaxCalories3(const std::vector<std::string> &nums) {
    std::multiset<int> top3;
    uint32_t accum = 0;
    for (auto &x : nums) {
        if (x == "") {
            top3.insert(accum);
            if (top3.size() > 3) {
                top3.erase(top3.begin());
            }
            accum = 0;
        } else {
            accum += stoi(x);
        }
    }
    top3.insert(accum);
    if (top3.size() > 3) {
        top3.erase(top3.begin());
    }
    uint32_t max_cal = 0;
    for (auto &x : top3) {
        std::cout << x << " ";
        max_cal += x;
    }
    return max_cal;
}

TEST_CASE("Test Calorie Count Part 1", "[day_01]") {
    std::vector<std::string> elves = {"1000", "2000", "3000", "",     "4000",
                                      "",     "5000", "6000", "",     "7000",
                                      "8000", "9000", "",     "10000"};
    REQUIRE(MaxCalories(elves) == 24000);
}
TEST_CASE("Test part 1", "[day_01]") {
    std::vector<std::string> nums;
    read_as_list_of_strings("../inputs/day_01.txt", nums);
    std::cout << "Size: " << nums.size() << std::endl;
    REQUIRE(MaxCalories(nums) == 68923);
}

TEST_CASE("Test Calorie Count Part 2", "[day_01]") {
    std::vector<std::string> elves = {"1000", "2000", "3000", "",     "4000",
                                      "",     "5000", "6000", "",     "7000",
                                      "8000", "9000", "",     "10000"};
    REQUIRE(MaxCalories3(elves) == 45000);
}
TEST_CASE("Test part 2", "[day_01]") {
    std::vector<std::string> nums;
    read_as_list_of_strings("../inputs/day_01.txt", nums);
    std::cout << "Size: " << nums.size() << std::endl;
    REQUIRE(MaxCalories3(nums) == 200044);
}
