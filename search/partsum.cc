/**
 * @ Description  :
 * @ Version      : 1.0
 * @ Author       : koritafei(koritafei@gmail.com)
 * @ Date         : 2021-03-27 21:31:15
 * @ LastEditors  : koritafei(koritafei@gmail.com)
 * @ LastEditTime : 2021-06-02 16:27:39
 * @ FilePath     : /program/search/partsum.cc
 * @ Copyright (C) 2021 koritafei(koritafei@gmail.com). All rights reserved.
 * */

#include <iostream>
#include <vector>

class Slove {
public:
  void partsum(std::vector<int> &nums, int target) {
    if (dfs(nums, target, 0, 0)) {
      std::cout << "Yes" << std::endl;
      return;
    }
    std::cout << "No" << std::endl;
  }

private:
  bool dfs(std::vector<int> &nums, int target, int sum, int index) {
    if (index == nums.size()) {
      return target == sum;
    }

    if (dfs(nums, target, sum, index + 1)) {
      return true;
    }

    if (dfs(nums, target, sum + nums[index], index + 1)) {
      return true;
    }

    return false;
  }
};

int main(int argc, char **argv) {
  Slove            slove;
  std::vector<int> nums   = {1, 2, 4, 7};
  int              target = 13;
  slove.partsum(nums, target);
  target = 15;
  slove.partsum(nums, target);
}
