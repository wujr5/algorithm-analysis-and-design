//
//  sorting-algorithms.cpp
//  sorting-algorithm-review
//
//  Created by 吴家荣 on 15/9/23.
//  Copyright (c) 2015年 吴家荣. All rights reserved.
//

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

template<typename Type>
void insert_sort(vector<Type>& v, int left, int right) {
  for (int i = left + 1; i < right; i++) {
    Type temp = v[i];
    int j = i - 1;
    for (; v[j] > temp && j >= left; j--) {
      v[j+1] = v[j];
    }
    v[j+1] = temp;
  }
}

template<typename Type>
void quick_sort(vector<Type>& v, int left, int right) {
  if (left < right) {
    Type pivot = v[left];
    int i, j;
    for (i = left, j = right - 1; i < j; ) {
      while (i < j && v[j] >= pivot) j--;
      swap(v[i], v[j]);
      while (i < j && v[i] <= pivot) i++;
      swap(v[i], v[j]);
    }
    
    quick_sort(v, left, i - 1);
    quick_sort(v, i + 1, right);
  }
}

template<typename Type>
void merge(vector<Type>& v, int left1, int right1, int left2, int right2) {
  int k = 0, i = left1, j = left2, n1 = right1 - left1 + 1, n2 = right2 - left2 + 1;
  
  vector<Type> tmp = vector<Type>(n1 + n2);
  
  while (i <= right1 && j <= right2) {
    if (v[i] < v[j]) tmp[k++] = v[i++];
    else tmp[k++] = v[j++];
  }
  
  while (i <= right1) tmp[k++] = v[i++];
  while (j <= right2) tmp[k++] = v[j++];
  
  for (int i = 0; i < n1; i++) v[left1++] = tmp[i];
  for (int i = n1; i < n1 + n2; i++) v[left2++] = tmp[i];
}

template<typename Type>
void merge_sort(vector<Type>& v, int left, int right) {
  int left1, right1, left2, right2, n = right - left + 1, size = 1;
  
  while (size < n) {
    left1 = left;
    
    while (left1 + size < n) {
      left2 = left1 + size;
      right1 = left2 - 1;
      if (left2 + size > n) {
        right2 = right;
      } else {
        right2 = left2 + size - 1;
      }
      
      merge(v, left1, right1, left2, right2);
      
      left1 = right2 + 1;
    }
    
    size *= 2;
  }
}

template<typename Type>
void filter_down(vector<Type>& v, int i, int n) {
  int child;
  Type tmp;
  
  for (tmp = v[i]; 2 * i + 1 < n; i = child) {
    child = 2 * i + 1;
    if (child != n - 1 && v[child] < v[child+1]) child++;
    
    if (tmp < v[child]) v[i] = v[child];
    else break;
  }
  
  v[i] = tmp;
}

template<typename Type>
void heap_sort(vector<Type>& v, int left, int right) {
  int n = right - left + 1;
  vector<Type> tmp(n);
  
  for (int i = 0; i < n; i++) tmp[i] = v[i];
  
  for (int i = n / 2; i >= 0; i--) filter_down(tmp, i, n);
  
  for (int j = n - 1; j > 0; j--) {
    swap(tmp[0], tmp[j]);
    filter_down(tmp, 0, j);
  }
  
  for (int i = 0; i < n; i++) v[left+i] = tmp[i];
}

template<typename Type>
void shell_insert_sort(vector<Type>& v, int n, int dk) {
  for (int i = dk; i < n; i++) {
    
  }
}

template<typename Type>
void shell_sort(vector<Type>& v, int left, int right) {
  int n = right - left + 1;
  int dk = n / 2;
  while (dk >= 1) {
    shell_insert_sort(v, n, dk);
    dk /= 2;
  }
}

