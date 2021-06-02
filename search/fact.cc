/**
 * @file fact.cc
 * @author koritafei (koritafei@gmail.com)
 * @brief  阶乘的实现
 * @version 0.1
 * @date 2021-03-27
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>
#include <vector>

class Fact {
public:
  int fact(int n) {
    if (n == 0 || n == 1) {
      return 1;
    }
    return fact(n - 2) + fact(n - 1);
  }

  int fact_memo(int n) {
    if (n <= 1) {
      return n;
    }

    if (memo[n] != 0) {
      return memo[n];
    }

    return memo[n] = fact_memo(n - 1) + fact_memo(n - 2);
  }

private:
  std::vector<int> memo;
};

int main(int argc, char **argv) {
  Fact f;
  std::cout << f.fact(20) << std::endl;
  std::cout << f.fact_memo(20) << std::endl;
}
