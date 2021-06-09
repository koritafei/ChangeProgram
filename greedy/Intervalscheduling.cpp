/**
 * @ Description  :
 * @ Version      : 1.0
 * @ Author       : koritafei(koritafei@gmail.com)
 * @ Date         : 2021-06-09 13:46:34
 * @ LastEditors  : koritafei(koritafei@gmail.com)
 * @ LastEditTime : 2021-06-09 13:59:08
 * @ FilePath     : /program/greedy/Intervalscheduling.cpp
 * @ Copyright (C) 2021 koritafei(koritafei@gmail.com). All rights reserved.
 * */

#include <algorithm>
#include <iostream>
#include <vector>

int intervalSelect(std::vector<int> &s, std::vector<int> &e, int len) {
  typedef std::pair<int, int> pair;  // start, end
  std::vector<pair>           intervals;
  std::vector<pair>           res;
  int                         count = 0;

  for (int i = 0; i < len; i++) {
    intervals.push_back(std::make_pair(e[i], s[i]));
  }
  std::sort(intervals.begin(), intervals.end());

  int end = 0;  // 上一次选中结束时间
  for (int i = 0; i < len; i++) {
    if (end < intervals[i].second) {
      end = intervals[i].first;
      res.push_back(intervals[i]);
      count++;
    }
  }

  for (auto i = res.begin(); i != res.end(); i++) {
    std::cout << "<" << i->second << " , " << i->first << "> ";
  }
  std::cout << "\n";
  return count;
}

int main(int argc, char **argv) {
  int              len = 6;
  std::vector<int> s   = {1, 2, 4, 6, 8};
  std::vector<int> e   = {3, 5, 7, 9, 10};

  std::cout << intervalSelect(s, e, len) << std::endl;
}