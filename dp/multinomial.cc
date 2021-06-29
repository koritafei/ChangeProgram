/**
 * @Copyright (c) 2021  koritafei
 * @file multinomial.cc
 * @brief
 * @author koritafei (koritafei@gmail.com)
 * @version 0.1
 * @date 2021-06-21 07:06:40
 *
 * */

#include <iostream>
#include <vector>

int multinomial(int n, int m, std::vector<int> &a, int M) {
  std::vector<std::vector<int>> dp =
      std::vector<std::vector<int>>(n + 1, std::vector<int>(m + 1, 0));
  for (int i = 0; i <= n; i++) {
    dp[i][0] = 1;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= m; j++) {
      if (j - 1 - a[i] >= 0) {
        dp[i + 1][j] =
            (dp[i][j] + dp[i + 1][j - 1] - dp[i][j - 1 - a[i]] + M) % M;
      } else {
        dp[i + 1][j] = (dp[i][j] + dp[i + 1][j - 1]) % M;
      }
    }
  }

  return dp[n][m];
}

int main(int argc, char **argv) {
  int              n = 3;
  int              m = 3;
  std::vector<int> a = {1, 2, 3};
  int              M = 10000;
  std::cout << multinomial(n, m, a, M) << std::endl;
}
