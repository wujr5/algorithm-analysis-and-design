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

### 2.2 emplace
```cpp
template <class... Args> void emplace (Args&&... args);
```

**Construct and insert element**

Adds a new element at the top of the stack, above its current top element. This new element is constructed in place passing args as the arguments for its constructor.

This member function effectively calls the member function emplace_back of the underlying container, forwarding args.

```cpp
// stack::emplace
#include <iostream>       // std::cin, std::cout
#include <stack>          // std::stack
#include <string>         // std::string, std::getline(string)

int main ()
{
  std::stack<std::string> mystack;

  mystack.emplace ("First sentence");
  mystack.emplace ("Second sentence");

  std::cout << "mystack contains:\n";
  while (!mystack.empty())
  {
    std::cout << mystack.top() << '\n';
    mystack.pop();
  }

  return 0;
}
```

**Output:**
```cpp
mystack contains:
Second sentence
First sentence
```

### 2.3 empty

```cpp
bool empty() const;
```

### 2.4 pop

```cpp
void pop();
```

**Remove top element**

Removes the element on top of the stack, effectively reducing its size by one.

The element removed is the latest element inserted into the stack, whose value can be retrieved by calling member stack::top.

This calls the removed element's destructor.

This member function effectively calls the member function pop_back of the underlying container object.

### 2.5 push

```cpp
void push (const value_type& val);
```

**Insert element**

Inserts a new element at the top of the stack, above its current top element. The content of this new element is initialized to a copy of val.

This member function effectively calls the member function push_back of the underlying container object.

### 2.6 size

```cpp
size_type size() const;
```

### 2.7 swap

```cpp
void swap (stack& x) noexcept(/*see below*/);
```

**Swap contents**

Exchanges the contents of the container adaptor (*this) by those of x.

This member function calls the non-member function swap (unqualified) to swap the underlying containers.

The noexcept specifier matches the swap operation on the underlying container.

### 2.8 top

```cpp
      value_type& top();
const value_type& top() const;
```
