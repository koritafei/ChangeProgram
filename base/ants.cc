/**
 * @ Description  :
 * @ Version      : 1.0
 * @ Author       : koritafei(koritafei@gmail.com)
 * @ Date         : 2021-02-25 16:21:34
 * @ LastEditors  : koritafei(koritafei@gmail.com)
 * @ LastEditTime : 2021-06-02 16:11:59
 * @ FilePath     : /program/base/ants.cc
 * @ Copyright (C) 2021 koritafei(koritafei@gmail.com). All rights reserved.
 * */

#include <iostream>
#include <vector>

void solve(std::vector<int> &in, int L) {
  int len = in.size();

  int min = 0;
  int max = 0;

  for (int i = 0; i < len; i++) {
    min = std::max(min, std::min(in[i], L - in[i]));
  }

  for (int i = 0; i < len; i++) {
    max = std::max(max, std::max(in[i], L - in[i]));
  }

  std::cout << "min = " << min << std::endl;
  std::cout << "max = " << max << std::endl;
}

int main(int argc, char **argv) {
  std::vector<int> in = {2, 6, 7};
  int              L  = 10;
  solve(in, L);
}
