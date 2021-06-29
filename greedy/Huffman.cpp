/**
 * @ Description  :
 * @ Version      : 1.0
 * @ Author       : koritafei(koritafei@gmail.com)
 * @ Date         : 2021-06-09 14:53:20
 * @ LastEditors  : koritafei(koritafei@gmail.com)
 * @ LastEditTime : 2021-06-09 16:15:57
 * @ FilePath     : /program/greedy/Huffman.cpp
 * @ Copyright (C) 2021 koritafei(koritafei@gmail.com). All rights reserved.
 * */

#include <iostream>
#include <vector>

template <class T>
class Huffman {
public:
  void createHuffman(std::vector<int> &nums, int len) {
    HuffmanNode *parent, *left, *right;
    while (len > 1) {
      int minL1 = 0, minL2 = 1;  // 最短与次短
      if (nums[minL1] > nums[minL2]) {
        std::swap(minL1, minL2);
      }

      for (int i = 2; i < len; i++) {
        if (nums[minL1] > nums[i]) {
          minL2 = minL1;
          minL1 = i;
        } else if (nums[i] > nums[minL2]) {
          minL2 = i;
        }
      }
      int sum       = nums[minL1] + nums[minL2];
      left          = new HuffmanNode(nums[minL1]);
      right         = new HuffmanNode(nums[minL2]);
      parent        = new HuffmanNode(sum);
      left->parent  = parent;
      right->parent = parent;
      nums[minL1]   = sum;
      nums[minL2]   = nums[len - 1];
      len--;
    }
    root = parent;
  }

private:
  struct HuffmanNode {
    T            key;     // 权值
    HuffmanNode *parent;  // 父亲节点
    HuffmanNode *left;    // 左孩子
    HuffmanNode *right;   // 右孩子

    HuffmanNode(T key)
        : key(key),
          parent(nullptr),
          left(nullptr),
          right(nullptr) {
    }
  };

  HuffmanNode *root;
};

int main(int argc, char **argv) {
}