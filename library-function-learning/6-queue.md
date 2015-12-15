# queue

## 1 Member functions

### 1.1 empty

Returns whether the queue is empty.

```cpp
// queue::empty
#include <iostream>       // std::cout
#include <queue>          // std::queue

int main () {
  std::queue<int> myqueue;
  int sum (0);

  for (int i=1;i<=10;i++) myqueue.push(i);

  while (!myqueue.empty()) {
     sum += myqueue.front();
     myqueue.pop();
  }

  std::cout << "total: " << sum << '\n';

  return 0;
}
```

### 1.2 size

Returns the number of elements in the queue.

```cpp
// queue::size
#include <iostream>       // std::cout
#include <queue>          // std::queue

int main ()
{
  std::queue<int> myints;
  std::cout << "0. size: " << myints.size() << '\n';

  for (int i=0; i<5; i++) myints.push(i);
  std::cout << "1. size: " << myints.size() << '\n';

  myints.pop();
  std::cout << "2. size: " << myints.size() << '\n';

  return 0;
}
```

### 1.3 front

Returns a reference to the next element in the queue.

```cpp
// queue::front
#include <iostream>       // std::cout
#include <queue>          // std::queue

int main ()
{
  std::queue<int> myqueue;

  myqueue.push(77);
  myqueue.push(16);

  myqueue.front() -= myqueue.back();    // 77-16=61

  std::cout << "myqueue.front() is now " << myqueue.front() << '\n';

  return 0;
}
```

### 1.4 back

Returns a reference to the last element in the queue. This is the "newest" element in the queue (i.e. the last element pushed into the queue).

```cpp
// queue::back
#include <iostream>       // std::cout
#include <queue>          // std::queue

int main () {
  std::queue<int> myqueue;

  myqueue.push(12);
  myqueue.push(75);   // this is now the back

  myqueue.back() -= myqueue.front();

  std::cout << "myqueue.back() is now " << myqueue.back() << '\n';

  return 0;
}
```

### 1.5 push

Inserts a new element at the end of the queue, after its current last element.

```cpp
// queue::push/pop
#include <iostream>       // std::cin, std::cout
#include <queue>          // std::queue

int main () {
  std::queue<int> myqueue;
  int myint;

  std::cout << "Please enter some integers (enter 0 to end):\n";

  do {
    std::cin >> myint;
    myqueue.push (myint);
  } while (myint);

  std::cout << "myqueue contains: ";
  while (!myqueue.empty()) {
    std::cout << ' ' << myqueue.front();
    myqueue.pop();
  }
  std::cout << '\n';

  return 0;
}
```

### 1.6 emplace

Adds a new element at the end of the queue, after its current last element.

```cpp
// queue::emplace
#include <iostream>       // std::cin, std::cout
#include <queue>          // std::queue
#include <string>         // std::string, std::getline(string)

int main () {
  std::queue<std::string> myqueue;

  myqueue.emplace ("First sentence");
  myqueue.emplace ("Second sentence");

  std::cout << "myqueue contains:\n";
  while (!myqueue.empty()) {
    std::cout << myqueue.front() << '\n';
    myqueue.pop();
  }

  return 0;
}
```

### 1.7 pop

Removes the next element in the queue, effectively reducing its size by one.

```cpp
// queue::push/pop
#include <iostream>       // std::cin, std::cout
#include <queue>          // std::queue

int main () {
  std::queue<int> myqueue;
  int myint;

  std::cout << "Please enter some integers (enter 0 to end):\n";

  do {
    std::cin >> myint;
    myqueue.push (myint);
  } while (myint);

  std::cout << "myqueue contains: ";
  while (!myqueue.empty()) {
    std::cout << ' ' << myqueue.front();
    myqueue.pop();
  }
  std::cout << '\n';

  return 0;
}
```

### 1.8 swap

Exchanges the contents of the container adaptor (*this) by those of x.

```cpp
// queue::swap
#include <iostream>       // std::cout
#include <queue>          // std::queue

int main () {
  std::queue<int> foo,bar;
  foo.push (10); foo.push(20); foo.push(30);
  bar.push (111); bar.push(222);

  foo.swap(bar);

  std::cout << "size of foo: " << foo.size() << '\n';
  std::cout << "size of bar: " << bar.size() << '\n';

  return 0;
}
```

## 2 Non-member function overloads

### 2.1 relational operators
### 2.2 swap(queue)
