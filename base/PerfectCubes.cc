/**
 * @file PerfectCubes.cc
 * @author koritafei (koritafei@gmail.com)
 * @brief 求 a^3=b^3+c^3+d^3中的a,b,c,d
 * @version 0.1
 * @date 2021-03-02
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>

void solve(int a) {
  for (int i = 6; i < a; i++) {
    for (int j = 2; j < i; j++) {
      for (int k = j + 1; k < i; k++) {
        for (int m = k + 1; m < i; m++) {
          if (i * i * i == j * j * j + k * k * k + m * m * m) {
            printf("Cube = %d, Triple = (%d,%d,%d)\n", i, j, k, m);
          }
        }
      }
    }
  }
}

int main() {
  int a;
  scanf("%d", &a);
  solve(a);
}
