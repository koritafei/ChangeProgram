/**
 * @file trangle.cc
 * @author koritafei (koritafei@gmail.com)
 * @brief 给定一组数据，判断这组数据是否能够组成三角形
 * @version 0.1
 * @date 2021-02-25
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>
#include <vector>

void solve(std::vector<int> &in) {
  int res = 0;
  int len = in.size();
  if (len <= 2) {
    std::cout << 0 << std::endl;
    return;
  }

  for (int i = 0; i < len - 2; i++) {
    for (int j = i + 1; j < len - 1; j++) {
      for (int k = j + 1; k < len; k++) {
        int c     = in[i] + in[j] + in[k];
        int ledge = std::max(std::max(in[i], in[j]), in[k]);
        int rest  = c - ledge;
        if (rest > ledge) {
          res = std::max(c, res);
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
