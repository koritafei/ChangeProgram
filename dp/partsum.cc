/**
 * @Copyright (c) 2021  koritafei
 * @file partsum.cc
 * @brief
 * @author koritafei (koritafei@gmail.com)
 * @version 0.1
 * @date 2021-06-21 06:06:13
 *
 * */

#include <iostream>
#include <vector>

void partsum(std::vector<int> &a, std::vector<int> &m, int n, int K) {
  std::vector<std::vector<bool>> dp =
      std::vector<std::vector<bool>>(n + 1, std::vector<bool>(K + 1, false));
  dp[0][0] = true;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= K; j++) {
      for (int k = 0; k <= m[i] && k * a[i] <= j; k++) {
        dp[i + 1][j] = dp[i + 1][j] | dp[i][j - k * a[i]];
      }
    }
  }
  if (dp[n][K]) {
    std::cout << "Yes\n" << std::endl;
  } else {
    std::cout << "No\n" << std::endl;
  }
}

int main(int argc, char **argv) {
  int              n = 3;
  int              K = 17;
  std::vector<int> a = {3, 5, 8};
  std::vector<int> m = {3, 2, 2};
  partsum(a, m, n, K);
}
