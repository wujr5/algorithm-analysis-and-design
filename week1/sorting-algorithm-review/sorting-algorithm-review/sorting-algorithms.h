//
//  sorting-algorithms.h
//  sorting-algorithm-review
//
//  Created by 吴家荣 on 15/9/23.
//  Copyright (c) 2015年 吴家荣. All rights reserved.
//

#ifndef __sorting_algorithm_review__sorting_algorithms__
#define __sorting_algorithm_review__sorting_algorithms__

#include <vector>
using namespace std;

namespace sort_algorithms {
  template<typename Type> void bubble_sort(vector<Type>&, int, int);
  template<typename Type> void select_sort(vector<Type>&, int, int);
  template<typename Type> void insert_sort(vector<Type>&, int, int);
  template<typename Type> void quick_sort(vector<Type>&, int, int);
  template<typename Type> void merg_sort(vector<Type>&, int, int);
  template<typename Type> void heap_sort(vector<Type>&, int, int);
  
  template<typename Type> const Type& median3(vector<Type>&, int, int);
  template<typename Type> void merg(vector<Type>&, int, int);
  template<typename Type> void filter_down(vector<Type>&, int, int);
  
  #include "sorting-algorithms-impl.h"
}

#endif /* defined(__sorting_algorithm_review__sorting_algorithms__) */
