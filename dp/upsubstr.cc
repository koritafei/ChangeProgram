/**
 * @Copyright (c) 2021  koritafei
 * @file upsubstr.cc
 * @brief
 * @author koritafei (koritafei@gmail.com)
 * @version 0.1
 * @date 2021-06-21 06:06:34
 *
 * */

#include <iostream>
#include <vector>

int longupstr(std::vector<int> &a, int n) {
  std::vector<int> dp  = std::vector<int>(n + 1, 0);
  int              res = 0;

  for (int i = 0; i < n; i++) {
    dp[i] = 1;
    for (int j = 0; j < i; j++) {
      if (a[i] > a[j]) {
        dp[i] = std::max(1, dp[j] + 1);
      }
    }
    res = std::max(res, dp[i]);
  }

  return res;
}

int main(int argc, char **argv) {
  std::vector<int> a = {4, 2, 3, 5, 1};
  int              n = 5;
  std::cout << longupstr(a, n) << std::endl;
}
