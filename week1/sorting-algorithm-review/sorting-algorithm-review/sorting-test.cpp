//
//  main.cpp
//  sorting-algorithm-review
//
//  Created by 吴家荣 on 15/9/23.
//  Copyright (c) 2015年 吴家荣. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include "sorting-algorithms.h"

using namespace std;
using namespace sort_algorithms;

const int SIZE = 10;

template<typename Type>
vector<Type> produce_random_vector() {
  vector<Type> v(SIZE);
  for (int i = 0; i < SIZE; i++) {
    v[i] = rand() % 100;
  }
  return v;
}

template<typename Type>
void print_vector(vector<Type>& v) {
  vector<int>::const_iterator itr = v.begin();
  while (itr != v.end()) cout << *itr++ << "\t";
  
  cout << endl;
}

int main(int argc, const char * argv[]) {
  vector<int> intvec;
  
  // test bubble_sort
  
  cout << "Unsorted Numbers: " << endl;
  intvec = produce_random_vector<int>();
  print_vector(intvec);
  
  cout << "Bubble Sorted Numbers: " << endl;
  bubble_sort(intvec, 0, SIZE);
  print_vector(intvec);
  cout << endl;
  
  // test select_sort
  
  cout << "Unsorted Numbers: " << endl;
  intvec = produce_random_vector<int>();
  print_vector(intvec);
  
  cout << "Select Sorted Numbers: " << endl;
  select_sort(intvec, 0, SIZE);
  print_vector(intvec);
  cout << endl;
  
  // test insert_sort
  
  cout << "Unsorted Numbers: " << endl;
  intvec = produce_random_vector<int>();
  print_vector(intvec);
  
  cout << "Insert Sorted Numbers: " << endl;
  insert_sort(intvec, 0, SIZE);
  print_vector(intvec);
  cout << endl;
  
  // test quick_sort
  
  cout << "Unsorted Numbers: " << endl;
  intvec = produce_random_vector<int>();
  print_vector(intvec);
  
  cout << "Quick Sorted Numbers: " << endl;
  quick_sort(intvec, 0, SIZE);
  print_vector(intvec);
  cout << endl;
  
  // test merge_sort
  
  cout << "Unsorted Numbers: " << endl;
  intvec = produce_random_vector<int>();
  print_vector(intvec);
  
  cout << "Merge Sorted Numbers: " << endl;
  merge_sort(intvec, 0, SIZE - 1);
  print_vector(intvec);
  cout << endl;
  
  // test heap_sort
  cout << "Unsorted Numbers: " << endl;
  intvec = produce_random_vector<int>();
  print_vector(intvec);
  
  cout << "Heap Sorted Numbers: " << endl;
  heap_sort(intvec, 0, SIZE - 1);
  print_vector(intvec);
  
  return 0;
}
