/**
 * @ Description  :
 * @ Version      : 1.0
 * @ Author       : koritafei(koritafei@gmail.com)
 * @ Date         : 2021-06-09 13:31:46
 * @ LastEditors  : koritafei(koritafei@gmail.com)
 * @ LastEditTime : 2021-06-09 13:45:05
 * @ FilePath     : /program/greedy/cionNum.cc
 * @ Copyright (C) 2021 koritafei(koritafei@gmail.com). All rights reserved.
 * */

#include <iostream>
#include <vector>

int min(int a, int b) {
  return a < b ? a : b;
}

int cionNum(std::vector<int> &vec, std::vector<int> &nums, int &target) {
  int len   = vec.size();
  int count = 0;
  for (int i = len - 1; i >= 0 && target > 0; i++) {
    int tmp = min(target / vec[i], nums[i]);
    target -= tmp * vec[i];
    count += tmp;
  }

  return count;
}

int main(int argc, char **argv) {
  int              target = 620;
  std::vector<int> vec    = {1, 5, 10, 50, 100, 500};
  std::vector<int> nums   = {3, 2, 1, 3, 0, 2};

  std::cout << cionNum(vec, nums, target) << std::endl;
}