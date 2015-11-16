//
//  main.cpp
//  3nPLUS1
//
//  Created by 吴家荣 on 15/11/10.
//  Copyright (c) 2015年 吴家荣. All rights reserved.
//

#include <iostream>
using namespace std;

int n, r, len;
int a[17];

void comput() {
  int i, p, n1, r1;
  n1 = abs(n);
  r1 = abs(r);
  len = -1;
  memset(a, 0, sizeof(a));
  while (n1 > 0) {
    ++len;
    a[len] = n1 % r1;
    n1 = n1 / r1;
  }
  if (n > 0) p = 1;
  else p = 0;
  while (p <= len) {
    if (a[p] > 0) {
      // 向A[P+1]位进1
      ++a[p+1];
      i = p + 1;
      while (a[i] >= r1) {
        a[i] -= r1;
        ++i;
        ++a[i];
      }
      if (i > len) len = i;
      a[p] = r1 - a[p];
    }
    p += 2;
  }
}

void print() {
  int i;
  for (i = len; i >= 0; --i) {
    if (a[i] < 10) cout << a[i];
    else cout << (char) (a[i] + 55);
  }
  cout << endl;
}

void run() {
  // 若读到数据文件的结束符号，程序结束
  while (cin >> n >> r) {
    // 无论在什么进制，0仍是0
    if (n == 0) cout << 0 << endl;
    else {
      comput();
      print();
    }
  }
}


int main() {
  freopen("../3nPLUS1/data.in", "r", stdin);
  freopen("../3nPLUS1/data.out", "w", stdout);
  run();
  return 0;
}

