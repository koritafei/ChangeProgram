/**
 * @ Description  :
 * @ Version      : 1.0
 * @ Author       : koritafei(koritafei@gmail.com)
 * @ Date         : 2021-06-18 09:51:07
 * @ LastEditors  : koritafei(koritafei@gmail.com)
 * @ LastEditTime : 2021-06-18 09:51:08
 * @ FilePath     : /program/dp/lcs.cc
 * @ Copyright (C) 2021 koritafei(koritafei@gmail.com). All rights reserved.
 * */

#include <iostream>
#include <string>
#include <vector>

int lcs(std::string s1, int m, std::string s2, int n) {
  std::vector<std::vector<int>> dp =
      std::vector<std::vector<int>>(m + 1, std::vector<int>(n + 1, 0));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (s1[i] == s2[j]) {
        dp[i + 1][j + 1] =
            std::max(dp[i][j] + 1, std::max(dp[i][j + 1], dp[i + 1][j]));
      } else {
        dp[i + 1][j + 1] = std::max(dp[i][j + 1], dp[i + 1][j]);
      }
    }
  }

  return dp[m][n];
}

int main(int argc, char **argv) {
  std::string s1 = "abcd";
  std::string s2 = "becd";
  int         m  = 4;
  int         n  = 4;
  std::cout << lcs(s1, m, s2, n) << std::endl;
}
