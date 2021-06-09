/**
 * @ Description  :
 * @ Version      : 1.0
 * @ Author       : koritafei(koritafei@gmail.com)
 * @ Date         : 2021-06-09 14:01:13
 * @ LastEditors  : koritafei(koritafei@gmail.com)
 * @ LastEditTime : 2021-06-09 14:48:37
 * @ FilePath     : /program/greedy/BestCowLine.cpp
 * @ Copyright (C) 2021 koritafei(koritafei@gmail.com). All rights reserved.
 * */

#include <iostream>
#include <vector>

std::string bestCowLine(std::string &s, int N) {
  std::string result;
  if (N < 0) {
    return result;
  }
  int left = 0, right = N - 1;
  while (left <= right) {
    bool leftFlag = false;  // 标记从左还是从右开始
    for (int i = 0; left + i < right; i++) {
      if (s[left + i] < s[right - i]) {
        leftFlag = true;
        break;
      } else if (s[left + i] > s[right - i]) {
        leftFlag = false;
        break;
      }
    }

    if (leftFlag) {
      result.push_back(s[left++]);
    } else {
      result.push_back(s[right--]);
    }
  }
  return result;
}

int main(int argc, char **argv) {
  std::string s("ACDBCB");
  int         N = 6;
  std::cout << bestCowLine(s, N) << std::endl;
}