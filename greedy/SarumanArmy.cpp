/**
 * @ Description  :
 * @ Version      : 1.0
 * @ Author       : koritafei(koritafei@gmail.com)
 * @ Date         : 2021-06-09 14:49:25
 * @ LastEditors  : koritafei(koritafei@gmail.com)
 * @ LastEditTime : 2021-06-09 15:11:53
 * @ FilePath     : /program/greedy/SarumanArmy.cpp
 * @ Copyright (C) 2021 koritafei(koritafei@gmail.com). All rights reserved.
 * */

#include <algorithm>
#include <iostream>
#include <vector>

int markNum(std::vector<int> &nums, int len, int R) {
  int              count = 0;
  std::vector<int> res;  //存储被标记的点

  std::sort(nums.begin(), nums.end());
  int i = 0;
  while (i < len) {
    int left = nums[i++];  // 最左侧未标记点

    while (i < len && nums[i] <= left + R) {  // 向右滑行道第一个大于s+R的位置
      i++;
    }
    res.push_back(nums[i - 1]);
    count++;
    int right = nums[i - 1];
    while (i < len && nums[i] <= right + R) {  // 滑行到最后侧无需标记的点
      i++;
    }
  }

  for (auto item : res) {
    std::cout << item << " ";
  }
  std::cout << "\n";
  return count;
}

int main(int argc, char **argv) {
  int              R   = 10;
  int              N   = 6;
  std::vector<int> vec = {1, 7, 15, 20, 30, 50};

  std::cout << markNum(vec, N, R) << std::endl;
}