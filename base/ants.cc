/**
 * @file ants.cc
 * @author koritafei (koritafei@gmail.com)
 * @brief 所有蚂蚁爬行掉落的最大和最小距离
 * @version 0.1
 * @date 2021-02-25
 *
 * @copyright Copyright (c) 2021
 *
 */

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
