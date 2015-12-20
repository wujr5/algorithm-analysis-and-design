# algorithm

> 参考：[algorithm](http://www.cplusplus.com/reference/algorithm/)

## 1 Non-modifying sequence operations

### 1.1 all_of

**Test condition on all elements in range**

Returns true if pred returns true for all the elements in the range [first,last) or if the range is empty, and false otherwise.

```cpp
template <class InputIterator, class UnaryPredicate>
bool all_of (InputIterator first, InputIterator last, UnaryPredicate pred);
```

**Example**

```cpp
// all_of example
#include <iostream>     // std::cout
#include <algorithm>    // std::all_of
#include <array>        // std::array

int main () {
  std::array<int,8> foo = {3,5,7,11,13,17,19,23};

  if ( std::all_of(foo.begin(), foo.end(), [](int i){return i%2;}) )
    std::cout << "All the elements are odd numbers.\n";

  return 0;
}
```

### 1.2 any_of

```cpp
template <class InputIterator, class UnaryPredicate>
bool any_of (InputIterator first, InputIterator last, UnaryPredicate pred);
```

**Test if any element in range fulfills condition**

Returns true if pred returns true for any of the elements in the range [first,last), and false otherwise.

```cpp
// any_of example
#include <iostream>     // std::cout
#include <algorithm>    // std::any_of
#include <array>        // std::array

int main () {
  std::array<int,7> foo = {0,1,-1,3,-3,5,-5};

  if ( std::any_of(foo.begin(), foo.end(), [](int i){return i<0;}) )
    std::cout << "There are negative elements in the range.\n";

  return 0;
}
```

### 1.3 none_of

```cpp
template <class InputIterator, class UnaryPredicate>
bool none_of (InputIterator first, InputIterator last, UnaryPredicate pred);
```

**Test if no elements fulfill condition**

Returns true if pred returns false for all the elements in the range [first,last) or if the range is empty, and false otherwise.

**Example**

```cpp
// none_of example
#include <iostream>     // std::cout
#include <algorithm>    // std::none_of
#include <array>        // std::array

int main () {
  std::array<int,8> foo = {1,2,4,8,16,32,64,128};

  if ( std::none_of(foo.begin(), foo.end(), [](int i){return i<0;}) )
    std::cout << "There are no negative elements in the range.\n";

  return 0;
}
```

### 1.4 for_each

**Apply function to range**

Applies function fn to each of the elements in the range [first,last).

```cpp
template <class InputIterator, class Function>
Function for_each (InputIterator first, InputIterator last, Function fn);
```

**Example**

```cpp
// for_each example
#include <iostream>     // std::cout
#include <algorithm>    // std::for_each
#include <vector>       // std::vector

void myfunction (int i) {  // function:
  std::cout << ' ' << i;
}

struct myclass {           // function object type:
  void operator() (int i) {std::cout << ' ' << i;}
} myobject;

int main () {
  std::vector<int> myvector;
  myvector.push_back(10);
  myvector.push_back(20);
  myvector.push_back(30);

  std::cout << "myvector contains:";
  for_each (myvector.begin(), myvector.end(), myfunction);
  std::cout << '\n';

  // or:
  std::cout << "myvector contains:";
  for_each (myvector.begin(), myvector.end(), myobject);
  std::cout << '\n';

  return 0;
}
```

### 1.5 find

```cpp
template <class InputIterator, class T>
InputIterator find (InputIterator first, InputIterator last, const T& val);
```

**Find value in range**

Returns an iterator to the first element in the range [first,last) that compares equal to val. If no such element is found, the function returns last.

**Example**

```cpp
// find example
#include <iostream>     // std::cout
#include <algorithm>    // std::find
#include <vector>       // std::vector

int main () {
  // using std::find with array and pointer:
  int myints[] = { 10, 20, 30, 40 };
  int * p;

  p = std::find (myints, myints+4, 30);
  if (p != myints+4)
    std::cout << "Element found in myints: " << *p << '\n';
  else
    std::cout << "Element not found in myints\n";

  // using std::find with vector and iterator:
  std::vector<int> myvector (myints,myints+4);
  std::vector<int>::iterator it;

  it = find (myvector.begin(), myvector.end(), 30);
  if (it != myvector.end())
    std::cout << "Element found in myvector: " << *it << '\n';
  else
    std::cout << "Element not found in myvector\n";

  return 0;
}
```

### 1.6 find_if

```cpp
template <class InputIterator, class UnaryPredicate>
InputIterator find_if (InputIterator first, InputIterator last, UnaryPredicate pred);
```

**Find element in range**
Returns an iterator to the first element in the range [first,last) for which pred returns true. If no such element is found, the function returns last.

**Example**

```cpp
// find_if example
#include <iostream>     // std::cout
#include <algorithm>    // std::find_if
#include <vector>       // std::vector

bool IsOdd (int i) {
  return ((i%2)==1);
}

int main () {
  std::vector<int> myvector;

  myvector.push_back(10);
  myvector.push_back(25);
  myvector.push_back(40);
  myvector.push_back(55);

  std::vector<int>::iterator it = std::find_if (myvector.begin(), myvector.end(), IsOdd);
  std::cout << "The first odd value is " << *it << '\n';

  return 0;
}
```

### 1.7 find_if_not

```cpp
template <class InputIterator, class UnaryPredicate>
InputIterator find_if_not (InputIterator first, InputIterator last, UnaryPredicate pred);
```

**Find element in range (negative condition)**

Returns an iterator to the first element in the range [first,last) for which pred returns false. If no such element is found, the function returns last.

**Example**

```cpp
// find_if_not example
#include <iostream>     // std::cout
#include <algorithm>    // std::find_if_not
#include <array>        // std::array

int main () {
  std::array<int,5> foo = {1,2,3,4,5};

  std::array<int,5>::iterator it =
    std::find_if_not (foo.begin(), foo.end(), [](int i){return i%2;} );
  std::cout << "The first even value is " << *it << '\n';

  return 0;
}
```

### 1.8 find_end

### 1.9 find_first_of

### 1.10 adjacent_find

### 1.11 count

### 1.12 count_if

### 1.13 mismatch

### 1.14 equal

### 1.15 search

### 1.16 search_n

## 2 Modifying sequence operations

## 3 Partitions

## 4 Sorting

## 5 Binary search

## 6 Merge 

## 7 Heap

## 8 Min/max

## 9 Other

