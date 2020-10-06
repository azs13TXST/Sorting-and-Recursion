#include <iostream>
#include <vector>
#include "hw5.h"

void print(std::vector<std::string> &v) {
  std::cout << "[";
  bool first = true;
  for (auto x : v) {
    if (!first) {
      std::cout << ", ";
    }
    std::cout << x;
    first = false;
  }
  std::cout << "]";
  std::cout << std::endl;
}

void print2(std::vector<int> &t) {
  std::cout << "[";
  bool first = true;
  for (auto y : t) {
    if (!first) {
      std::cout << ", ";
    }
    std::cout << y;
    first = false;
  }
  std::cout << "]";
  std::cout << std::endl;
}

void print3(std::vector<std::string> &h) {
  std::cout << "[";
  bool first = true;
  for (auto w : h) {
    if (!first) {
      std::cout << ", ";
    }
    std::cout << w;
    first = false;
  }
  std::cout << "]";
  std::cout << std::endl;
}

int main() {
  std::vector<std::string> v;
  v = {"emma", "dora", "ruth", "ziegellaub", "eichler"};

  std::cout << "Case 1: ";

  MergeSort(v);
  print(v);

  std::cout << "Expected: [dora, eichler, emma, ruth, ziegellaub]" << std::endl << std::endl;

  std::vector<int> t;
  t = {11, 3, 420, 97, 69, 22};

  std::cout << "Case 2: ";

  InsertionSort(t);
  print2(t);

  std::cout << "Expected: [3, 11, 22, 69, 97, 420]" << std::endl << std::endl;

  std::vector<std::string> h;
  h = {"ana", "mercy", "baptiste", "moira", "zenyatta", "brigitte"};

  std::cout << "Case 3: ";

  BubbleSort(h);
  print3(h);
  
  std::cout << "Expected: [ana, baptiste, brigitte, mercy, moira, zenyatta]"  << std::endl << std::endl;
}