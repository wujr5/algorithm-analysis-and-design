//
//  sorting-algorithms.cpp
//  sorting-algorithm-review
//
//  Created by 吴家荣 on 15/9/23.
//  Copyright (c) 2015年 吴家荣. All rights reserved.
//

#include "sorting-algorithms.h"
#include <iostream>

template<typename Type>
void bubble_sort(vector<Type>& a, int left, int right) {
  bool flag;
  
  for (int i = left; i < right - 1; i++) {
    flag = false;
    
    for (int j = left; j < right - i - 1; j++) {
      if (a[j] > a[j+1]) {
        swap(a[j], a[j+1]);
        flag = true;
      }
    }
    
    if (!flag) return;
  }
}

template<typename Type>
void select_sort(vector<Type>& v, int left, int right) {
  int minpos;
  for (int i = left; i < right; i++) {
    minpos = i;
    for (int j = i + 1; j < right; j++) {
      if (v[j] < v[minpos]) {
        minpos = j;
      }
    }
    if (i != minpos) swap(v[i], v[minpos]);
  }
}


