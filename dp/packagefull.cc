/**
 * @Copyright (c) 2021  koritafei
 * @file packagefull.cc
 * @brief
 * @author koritafei (koritafei@gmail.com)
 * @version 0.1
 * @date 2021-06-21 05:06:00
 *
 * */

#include <iostream>
#include <vector>

int packagefull(std::vector<int> &w, std::vector<int> &v, int m, int W) {
  std::vector<std::vector<int>> dp =
      std::vector<std::vector<int>>(m + 1, std::vector<int>(W + 1, 0));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j <= W; j++) {
      if (j < w[i]) {
        dp[i + 1][j] = dp[i][j];
      } else {
        dp[i + 1][j] = std::max(dp[i][j], dp[i + 1][j - w[i]] + v[i]);
      }
    }
  }

  return dp[m][W];
}

int main(int argc, char **argv) {
  std::vector<int> w   = {3, 4, 2};
  std::vector<int> v   = {4, 5, 3};
  int              len = 3;
  int              W   = 7;

  std::cout << packagefull(w, v, len, W) << std::endl;
}
