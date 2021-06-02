/**
 * @ Description  :
 * @ Version      : 1.0
 * @ Author       : koritafei(koritafei@gmail.com)
 * @ Date         : 2021-02-25 15:59:36
 * @ LastEditors  : koritafei(koritafei@gmail.com)
 * @ LastEditTime : 2021-06-02 16:10:23
 * @ FilePath     : /program/base/trangle.cc
 * @ Copyright (C) 2021 koritafei(koritafei@gmail.com). All rights reserved.
 * */

#include <iostream>
#include <vector>

void solve(std::vector<int> &in) {
  int res = 0;
  int len = in.size();
  if (len <= 2) {
    std::cout << 0 << std::endl;
    return;
  }

  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      for (int k = j + 1; k < len; k++) {
        int c    = in[i] + in[j] + in[k];
        int maxc = std::max(std::max(in[i], in[j]), in[k]);
        int ret  = c - maxc;
        if (ret > maxc) {
          res = res > c ? ret : c;
        }
      }
    }
  }

  std::cout << res << std::endl;
}

int main(int argc, char **argv) {
  std::vector<int> in = {2, 3, 4, 5, 10};
  solve(in);
  std::vector<int> in1 = {4, 5, 10, 20};
  solve(in1);
}
