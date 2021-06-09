/**
 * @ Description  :
 * @ Version      : 1.0
 * @ Author       : koritafei(koritafei@gmail.com)
 * @ Date         : 2021-06-09 14:53:05
 * @ LastEditors  : koritafei(koritafei@gmail.com)
 * @ LastEditTime : 2021-06-09 15:50:16
 * @ FilePath     : /program/greedy/FenceRepair.cpp
 * @ Copyright (C) 2021 koritafei(koritafei@gmail.com). All rights reserved.
 * */

#include <algorithm>
#include <iostream>
#include <vector>

long long FenceRepair(std::vector<int> &nums, int len) {
  // huffman树解法
  long long        res = 0;
  std::vector<int> t;
  // 每次找出最短板和次短板合并即为结果
  while (len > 1) {
    int minL1 = 0, minL2 = 1;  // minL1最短板，minL2次短板
    if (nums[minL1] > nums[minL2]) {
      std::swap(minL1, minL2);
    }

    for (int i = 2; i < len; i++) {
      if (nums[i] < nums[minL1]) {
        minL2 = minL1;
        minL1 = i;
      } else if (nums[i] < nums[minL2]) {
        minL2 = i;
      }
    }

    // 合并最短板和次短板
    int sum = nums[minL1] + nums[minL2];
    t.push_back(nums[minL1]);
    t.push_back(nums[minL2]);
    res += sum;
    nums[minL1] = sum;
    nums[minL2] = nums[len - 1];
    len--;
  }
  for (auto item : t) {
    std::cout << item << " ";
  }
  std::cout << "\n";
  return res;
}

int main(int argc, char **argv) {
  int              N = 3;
  std::vector<int> L = {8, 5, 8};
  std::cout << FenceRepair(L, N) << std::endl;  // 34
}
