/**
 * @ Description  :
 * @ Version      : 1.0
 * @ Author       : koritafei(koritafei@gmail.com)
 * @ Date         : 2021-06-22 15:00:54
 * @ LastEditors  : koritafei(koritafei@gmail.com)
 * @ LastEditTime : 2021-06-22 15:11:47
 * @ FilePath     : /program/dp/coin.cc
 * @ Copyright (C) 2021 koritafei(koritafei@gmail.com). All rights reserved.
 * */

#include <iostream>
#include <vector>

int coin(std::vector<int> &coins, int amount) {
  std::vector<int> dp = std::vector<int>(amount + 1, amount + 1);
  dp[0]               = 0;
  for (int i = 0; i < dp.size(); i++) {
    for (auto c : coins) {
      if (i - c < 0) {
        continue;
      }
      dp[i] = std::min(dp[i], dp[i - c] + 1);
    }
  }

  return dp[amount] == amount + 1 ? -1 : dp[amount];
}

int main(int argc, char **argv) {
  std::vector<int> coins  = {1, 2, 5};
  int              amount = 11;
  std::cout << coin(coins, amount) << std::endl;
}
