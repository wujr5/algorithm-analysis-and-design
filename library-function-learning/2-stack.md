# stack 库函数

## 1 库函数介绍

**声明**

```cpp
template <class T, class Container = deque<T>> class stack;
```



## 2 成员函数

### 2.1 (constructor)

```cpp
// constructing stacks
#include <iostream>       // std::cout
#include <stack>          // std::stack
#include <vector>         // std::vector
#include <deque>          // std::deque

int main ()
{
  std::deque<int> mydeque (3,100);          // deque with 3 elements
  std::vector<int> myvector (2,200);        // vector with 2 elements

  std::stack<int> first;                    // empty stack
  std::stack<int> second (mydeque);         // stack initialized to copy of deque

  std::stack<int,std::vector<int> > third;  // empty stack using vector
  std::stack<int,std::vector<int> > fourth (myvector);

  std::cout << "size of first: " << first.size() << '\n';
  std::cout << "size of second: " << second.size() << '\n';
  std::cout << "size of third: " << third.size() << '\n';
  std::cout << "size of fourth: " << fourth.size() << '\n';

  return 0;
}
``` 

**Output:**
```cpp
size of first: 0
size of second: 3
size of third: 0
size of fourth: 2
```

### 2.2
### 2.3
### 2.4
### 2.5
### 2.6
### 2.7
### 2.8
### 2.9

## 3 分析