/**
 * @Copyright (c) 2021  koritafei
 * @file partnum.cc
 * @brief
 * @author koritafei (koritafei@gmail.com)
 * @version 0.1
 * @date 2021-06-21 07:06:61
 *
 * */

#include <iostream>
#include <vector>

int partnum(int n, int m, int M) {
  std::vector<std::vector<int>> dp =
      std::vector<std::vector<int>>(m + 1, std::vector<int>(n + 1, 0));
  dp[0][0] = 1;

  for (int i = 1; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      if (j - i >= 0) {
        dp[i][j] = (dp[i][j - i] + dp[i - 1][j]) % M;
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  return dp[m][n];
}

int main(int argc, char **argv) {
  int n = 4;
  int m = 3;
  int M = 10000;

  std::cout << partnum(n, m, M) << std::endl;
}
