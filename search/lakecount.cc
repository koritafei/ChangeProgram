/**
 * @ Description  :
 * @ Version      : 1.0
 * @ Author       : koritafei(koritafei@gmail.com)
 * @ Date         : 2021-03-27 22:01:02
 * @ LastEditors  : koritafei(koritafei@gmail.com)
 * @ LastEditTime : 2021-06-02 16:35:06
 * @ FilePath     : /program/search/lakecount.cc
 * @ Copyright (C) 2021 koritafei(koritafei@gmail.com). All rights reserved.
 * */

#include <iostream>
#include <vector>

class Solve {
public:
  int lakecount(std::vector<std::vector<char>> &field) {
    int res = 0;
    int row = field.size();
    if (row == 0) {
      return res;
    }

    int col = field[0].size();
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (field[i][j] == 'W') {
          dfs(field, i, j, row, col);
          res++;
        }
      }
    }

    return res;
  }

private:
  void dfs(std::vector<std::vector<char>> &field, int x, int y, int row,
           int col) {
    field[x][y] = '.';
    for (int dx = -1; dx <= 1; dx++) {
      for (int dy = -1; dy <= 1; dy++) {
        int nx = x + dx;
        int ny = y + dy;
        if (isInArray(nx, ny, row, col) && field[nx][ny] == 'W') {
          dfs(field, nx, ny, row, col);
        }
      }
    }
  }

  bool isInArray(int x, int y, int row, int col) {
    return x >= 0 && x < row && y >= 0 && y < col;
  }
};

int main(int argc, char **argv) {
  std::vector<std::vector<char>> field = {
      {'W', '.', '.', '.', '.', '.', '.', '.', '.', 'W', 'W', '.'},
      {'.', 'W', 'W', 'W', '.', '.', '.', '.', '.', 'W', 'W', 'W'},
      {'.', '.', '.', '.', 'W', 'W', '.', '.', '.', 'W', 'W', '.'},
      {'.', '.', '.', '.', '.', '.', '.', '.', '.', 'W', 'W', '.'},
      {'.', '.', '.', '.', '.', '.', '.', '.', '.', 'W', '.', '.'},
      {'.', '.', 'W', '.', '.', '.', '.', '.', '.', 'W', '.', '.'},
      {'.', 'W', '.', 'W', '.', '.', '.', '.', '.', 'W', 'W', '.'},
      {'W', '.', 'W', '.', 'W', '.', '.', '.', '.', '.', 'W', '.'},
      {'.', 'W', '.', 'W', '.', '.', '.', '.', '.', '.', 'W', '.'},
      {'.', '.', 'W', '.', '.', '.', '.', '.', '.', '.', 'W', '.'}};
  Solve s;
  std::cout << s.lakecount(field) << std::endl;
}
