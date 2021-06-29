/**
 * @ Description  :
 * @ Version      : 1.0
 * @ Author       : koritafei(koritafei@gmail.com)
 * @ Date         : 2021-03-28 11:40:59
 * @ LastEditors  : koritafei(koritafei@gmail.com)
 * @ LastEditTime : 2021-06-02 21:56:58
 * @ FilePath     : /program/search/maze.cc
 * @ Copyright (C) 2021 koritafei(koritafei@gmail.com). All rights reserved.
 * */

#include <iostream>
#include <queue>
#include <vector>

class Maze {
public:
  typedef std::pair<int, int> pair;

  int MazeStep(std::vector<std::vector<int>> &maze, int row, int col,
               int startx, int starty, int endx, int endy) {
    // std::cout << startx << ", " << starty << "\t" << endx << ", " << endy
    // << std::endl;
    step = std::vector<std::vector<int>>(row, std::vector<int>(col, INF));
    step[startx][starty] = 0;
    std::queue<pair> q;
    q.push(std::make_pair(startx, starty));

    while (q.size()) {
      pair top = q.front();
      // std::cout << top.first << "," << top.second << "\n";
      q.pop();

      if (top.first == endx && top.second == endy) {
        break;
      }

      // 四个方向开始移动
      for (int i = 0; i < 4; i++) {
        int nx = top.first + dx[i];
        int ny = top.second + dy[i];

        if (isInMaze(nx, ny, row, col) && maze[nx][ny] == 0 &&
            step[nx][ny] == INF) {
          q.push(std::make_pair(nx, ny));
          step[nx][ny] = step[top.first][top.second] + 1;
        }
      }
    }

    return step[endx][endy];
  }

private:
  bool isInMaze(int x, int y, int row, int col) {
    return x >= 0 && y >= 0 && x < row && y < col;
  }

  std::vector<std::vector<int>> step;
  int                           dx[4] = {0, -1, 0, 1};
  int                           dy[4] = {-1, 0, 1, 0};

  const int INF = 1000000;
};

int main(int argc, char **argv) {
  std::vector<std::vector<int>> maze = {{0, 0, 0, 0, 0},
                                        {0, -1, 0, -1, 0},
                                        {0, -1, -1, 0, 0},
                                        {0, -1, -1, 0, -1},
                                        {0, 0, 0, 0, 0}};
  Maze                          m;

  int startx = 0, starty = 0, endx = 4, endy = 4;
  int row = 5;
  int col = 5;

  std::cout << m.MazeStep(maze, row, col, startx, starty, endx, endy)
            << std::endl;
}
