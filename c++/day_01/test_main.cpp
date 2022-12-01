#define CATCH_CONFIG_MAIN
#include "../common/catch.hpp"
#include "file_utils.h"

int MaxCalories(const std::vector<std::string> &nums) {
    return 0;
}

TEST_CASE("Test Calorie Count Part 1", "[day_01]") {
  std::vector<std::string> elves = {"1000", "2000", "3000", "", "4000", "", "5000", "6000", "", "7000", "8000", "9000", "", "10000"};
  REQUIRE(MaxCalories(elves) == 24000);
}
TEST_CASE("Test part 1", "[day_01]") {
  std::vector<std::string> nums;
  read_as_list_of_strings("../inputs/day_01.txt", nums);
  std::cout << "Size: " << nums.size() << std::endl;
  REQUIRE(MaxCalories(nums) == 0);
}
