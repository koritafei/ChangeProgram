/**
 * @ Description  :
 * @ Version      : 1.0
 * @ Author       : koritafei(koritafei@gmail.com)
 * @ Date         : 2021-06-18 09:30:42
 * @ LastEditors  : koritafei(koritafei@gmail.com)
 * @ LastEditTime : 2021-06-18 09:48:18
 * @ FilePath     : /program/dp/package01.cpp
 * @ Copyright (C) 2021 koritafei(koritafei@gmail.com). All rights reserved.
 * */

#include <iostream>
#include <vector>

class Solution {
public:
  int weightPackage(std::vector<int> &weights, std::vector<int> &nums, int W) {
    // 标记
    std::vector<std::vector<int>> dp = std::vector<std::vector<int>>(
        nums.size() + 1, std::vector<int>(W + 1, 0));
    for (int i = nums.size() - 1; i >= 0; i--) {
      for (int j = 0; j <= W; j++) {
        if (j < weights[i]) {
          dp[i][j] = dp[i + 1][j];
        } else {
          dp[i][j] =
              std::max(dp[i + 1][j], dp[i + 1][j - weights[i]] + nums[i]);
        }
      }
    }
    return dp[0][W];
  }
};

int main(int argc, char **argv) {
  Solution         solution;
  std::vector<int> weights = {2, 1, 3, 2};
  std::vector<int> nums    = {3, 2, 4, 2};
  int              W       = 5;

  std::cout << solution.weightPackage(weights, nums, W) << std::endl;
}
