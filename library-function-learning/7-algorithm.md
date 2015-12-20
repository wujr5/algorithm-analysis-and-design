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

```cpp
template <class ForwardIterator1, class ForwardIterator2>
ForwardIterator1 find_end (ForwardIterator1 first1, ForwardIterator1 last1,ForwardIterator2 first2, ForwardIterator2 last2);

template <class ForwardIterator1, class ForwardIterator2, class BinaryPredicate>
ForwardIterator1 find_end (ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2, BinaryPredicate pred);
```

查找最后一个匹配的子序列。

**Find last subsequence in range**
Searches the range [first1,last1) for the last occurrence of the sequence defined by [first2,last2), and returns an iterator to its first element, or last1 if no occurrences are found.

The elements in both ranges are compared sequentially using operator== (or pred, in version (2)): A subsequence of [first1,last1) is considered a match only when this is true for all the elements of [first2,last2).

**Example**

```cpp
// find_end example
#include <iostream>     // std::cout
#include <algorithm>    // std::find_end
#include <vector>       // std::vector

bool myfunction (int i, int j) {
  return (i==j);
}

int main () {
  int myints[] = {1,2,3,4,5,1,2,3,4,5};
  std::vector<int> haystack (myints,myints+10);

  int needle1[] = {1,2,3};

  // using default comparison:
  std::vector<int>::iterator it;
  it = std::find_end (haystack.begin(), haystack.end(), needle1, needle1+3);

  if (it!=haystack.end())
    std::cout << "needle1 last found at position " << (it-haystack.begin()) << '\n';

  int needle2[] = {4,5,1};

  // using predicate comparison:
  it = std::find_end (haystack.begin(), haystack.end(), needle2, needle2+3, myfunction);

  if (it!=haystack.end())
    std::cout << "needle2 last found at position " << (it-haystack.begin()) << '\n';

  return 0;
}
```

### 1.9 find_first_of

```cpp
template <class ForwardIterator1, class ForwardIterator2>
ForwardIterator1 find_first_of (ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2);

template <class ForwardIterator1, class ForwardIterator2, class BinaryPredicate>
ForwardIterator1 find_first_of (ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2, BinaryPredicate pred);
```

**Find element from set in range**

Returns an iterator to the first element in the range [first1,last1) that matches any of the elements in [first2,last2). If no such element is found, the function returns last1.

**Example**

```cpp
// find_first_of example
#include <iostream>     // std::cout
#include <algorithm>    // std::find_first_of
#include <vector>       // std::vector
#include <cctype>       // std::tolower

bool comp_case_insensitive (char c1, char c2) {
  return (std::tolower(c1)==std::tolower(c2));
}

int main () {
  int mychars[] = {'a','b','c','A','B','C'};
  std::vector<char> haystack (mychars,mychars+6);
  std::vector<char>::iterator it;

  int needle[] = {'A','B','C'};

  // using default comparison:
  it = find_first_of (haystack.begin(), haystack.end(), needle, needle+3);

  if (it!=haystack.end())
    std::cout << "The first match is: " << *it << '\n';

  // using predicate comparison:
  it = find_first_of (haystack.begin(), haystack.end(),
                      needle, needle+3, comp_case_insensitive);

  if (it!=haystack.end())
    std::cout << "The first match is: " << *it << '\n';

  return 0;
}
```

### 1.10 adjacent_find

```cpp
template <class ForwardIterator>
ForwardIterator adjacent_find (ForwardIterator first, ForwardIterator last);

template <class ForwardIterator, class BinaryPredicate>
ForwardIterator adjacent_find (ForwardIterator first, ForwardIterator last, BinaryPredicate pred);
```

**Find equal adjacent elements in range**

Searches the range [first,last) for the first occurrence of two consecutive elements that match, and returns an iterator to the first of these two elements, or last if no such pair is found.

```cpp
// adjacent_find example
#include <iostream>     // std::cout
#include <algorithm>    // std::adjacent_find
#include <vector>       // std::vector

bool myfunction (int i, int j) {
  return (i==j);
}

int main () {
  int myints[] = {5,20,5,30,30,20,10,10,20};
  std::vector<int> myvector (myints,myints+8);
  std::vector<int>::iterator it;

  // using default comparison:
  it = std::adjacent_find (myvector.begin(), myvector.end());

  if (it!=myvector.end())
    std::cout << "the first pair of repeated elements are: " << *it << '\n';

  //using predicate comparison:
  it = std::adjacent_find (++it, myvector.end(), myfunction);

  if (it!=myvector.end())
    std::cout << "the second pair of repeated elements are: " << *it << '\n';

  return 0;
}
```

### 1.11 count

```cpp
template <class InputIterator, class T>
typename iterator_traits<InputIterator>::difference_type count (InputIterator first, InputIterator last, const T& val);
```

**Count appearances of value in range**

Returns the number of elements in the range [first,last) that compare equal to val.

**Example**

```cpp
// count algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::count
#include <vector>       // std::vector

int main () {
  // counting elements in array:
  int myints[] = {10,20,30,30,20,10,10,20};   // 8 elements
  int mycount = std::count (myints, myints+8, 10);
  std::cout << "10 appears " << mycount << " times.\n";

  // counting elements in container:
  std::vector<int> myvector (myints, myints+8);
  mycount = std::count (myvector.begin(), myvector.end(), 20);
  std::cout << "20 appears " << mycount  << " times.\n";

  return 0;
}
```

### 1.12 count_if

```cpp
template <class InputIterator, class UnaryPredicate>
typename iterator_traits<InputIterator>::difference_type count_if (InputIterator first, InputIterator last, UnaryPredicate pred);
```

**Return number of elements in range satisfying condition**

Returns the number of elements in the range [first,last) for which pred is true.

**Example**

```cpp
// count_if example
#include <iostream>     // std::cout
#include <algorithm>    // std::count_if
#include <vector>       // std::vector

bool IsOdd (int i) { return ((i%2)==1); }

int main () {
  std::vector<int> myvector;
  for (int i=1; i<10; i++) myvector.push_back(i); // myvector: 1 2 3 4 5 6 7 8 9

  int mycount = count_if (myvector.begin(), myvector.end(), IsOdd);
  std::cout << "myvector contains " << mycount  << " odd values.\n";

  return 0;
}
```

### 1.13 mismatch

```cpp
template <class InputIterator1, class InputIterator2>
pair<InputIterator1, InputIterator2> mismatch (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2);
```

**Example**

```cpp
// mismatch algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::mismatch
#include <vector>       // std::vector
#include <utility>      // std::pair

bool mypredicate (int i, int j) {
  return (i==j);
}

int main () {
  std::vector<int> myvector;
  for (int i=1; i<6; i++) myvector.push_back (i*10); // myvector: 10 20 30 40 50

  int myints[] = {10,20,80,320,1024};                //   myints: 10 20 80 320 1024

  std::pair<std::vector<int>::iterator,int*> mypair;

  // using default comparison:
  mypair = std::mismatch (myvector.begin(), myvector.end(), myints);
  std::cout << "First mismatching elements: " << *mypair.first;
  std::cout << " and " << *mypair.second << '\n';

  ++mypair.first; ++mypair.second;

  // using predicate comparison:
  mypair = std::mismatch (mypair.first, myvector.end(), mypair.second, mypredicate);
  std::cout << "Second mismatching elements: " << *mypair.first;
  std::cout << " and " << *mypair.second << '\n';

  return 0;
}
```

### 1.14 equal

```cpp
template <class InputIterator1, class InputIterator2>
bool equal (InputIterator1 first1, InputIterator1 last1, 	InputIterator2 first2);

template <class InputIterator1, class InputIterator2, class BinaryPredicate>
bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred);
```

**Test whether the elements in two ranges are equal**

Compares the elements in the range [first1,last1) with those in the range beginning at first2, and returns true if all of the elements in both ranges match.

**Example**

```cpp
// equal algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::equal
#include <vector>       // std::vector

bool mypredicate (int i, int j) {
  return (i==j);
}

int main () {
  int myints[] = {20,40,60,80,100};               //   myints: 20 40 60 80 100
  std::vector<int>myvector (myints,myints+5);     // myvector: 20 40 60 80 100

  // using default comparison:
  if ( std::equal (myvector.begin(), myvector.end(), myints) )
    std::cout << "The contents of both sequences are equal.\n";
  else
    std::cout << "The contents of both sequences differ.\n";

  myvector[3]=81;                                 // myvector: 20 40 60 81 100

  // using predicate comparison:
  if ( std::equal (myvector.begin(), myvector.end(), myints, mypredicate) )
    std::cout << "The contents of both sequences are equal.\n";
  else
    std::cout << "The contents of both sequences differ.\n";

  return 0;
}
```

### 1.15 is_permutation

```cpp
template <class ForwardIterator1, class ForwardIterator2>
bool is_permutation (ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2);

template <class ForwardIterator1, class ForwardIterator2, class BinaryPredicate>
bool is_permutation (ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, BinaryPredicate pred);
```

**Test whether range is permutation of another**

Compares the elements in the range [first1,last1) with those in the range beginning at first2, and returns true if all of the elements in both ranges match, even in a different order.

**Example**

```cpp
// is_permutation example
#include <iostream>     // std::cout
#include <algorithm>    // std::is_permutation
#include <array>        // std::array

int main () {
  std::array<int,5> foo = {1,2,3,4,5};
  std::array<int,5> bar = {3,1,4,5,2};

  if ( std::is_permutation (foo.begin(), foo.end(), bar.begin()) )
    std::cout << "foo and bar contain the same elements.\n";

  return 0;
}
```

### 1.16 search

```cpp
template <class ForwardIterator1, class ForwardIterator2>
ForwardIterator1 search (ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2);

template <class ForwardIterator1, class ForwardIterator2, class BinaryPredicate>
ForwardIterator1 search (ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2, BinaryPredicate pred);
```

**Search range for subsequence**

Searches the range [first1,last1) for the first occurrence of the sequence defined by [first2,last2), and returns an iterator to its first element, or last1 if no occurrences are found.

The elements in both ranges are compared sequentially using operator== (or pred, in version (2)): A subsequence of [first1,last1) is considered a match only when this is true for all the elements of [first2,last2).

### 1.17 search_n

```cpp
template <class ForwardIterator, class Size, class T>
ForwardIterator search_n (ForwardIterator first, ForwardIterator last, Size count, const T& val);

template <class ForwardIterator, class Size, class T, class BinaryPredicate>
ForwardIterator search_n ( ForwardIterator first, ForwardIterator last, Size count, const T& val, BinaryPredicate pred );
```

**Search range for elements**

Searches the range [first,last) for a sequence of count elements, each comparing equal to val (or for which pred returns true).

The function returns an iterator to the first of such elements, or last if no such sequence is found.

```cpp
// search_n example
#include <iostream>     // std::cout
#include <algorithm>    // std::search_n
#include <vector>       // std::vector

bool mypredicate (int i, int j) {
  return (i==j);
}

int main () {
  int myints[]={10,20,30,30,20,10,10,20};
  std::vector<int> myvector (myints,myints+8);

  std::vector<int>::iterator it;

  // using default comparison:
  it = std::search_n (myvector.begin(), myvector.end(), 2, 30);

  if (it!=myvector.end())
    std::cout << "two 30s found at position " << (it-myvector.begin()) << '\n';
  else
    std::cout << "match not found\n";

  // using predicate comparison:
  it = std::search_n (myvector.begin(), myvector.end(), 2, 10, mypredicate);

  if (it!=myvector.end())
    std::cout << "two 10s found at position " << int(it-myvector.begin()) << '\n';
  else
    std::cout << "match not found\n";

  return 0;
}
```

## 2 Modifying sequence operations

## 3 Partitions

## 4 Sorting

### 4.1 sort

```cpp
template <class RandomAccessIterator>
void sort (RandomAccessIterator first, RandomAccessIterator last);

template <class RandomAccessIterator, class Compare>
void sort (RandomAccessIterator first, RandomAccessIterator last, Compare comp);
```

**Sort elements in range**

Sorts the elements in the range [first,last) into ascending order.

The elements are compared using operator< for the first version, and comp for the second.

**Example**

```cpp
// sort algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector

bool myfunction (int i,int j) { return (i<j); }

struct myclass {
  bool operator() (int i,int j) { return (i<j);}
} myobject;

int main () {
  int myints[] = {32,71,12,45,26,80,53,33};
  std::vector<int> myvector (myints, myints+8);               // 32 71 12 45 26 80 53 33

  // using default comparison (operator <):
  std::sort (myvector.begin(), myvector.begin()+4);           //(12 32 45 71)26 80 53 33

  // using function as comp
  std::sort (myvector.begin()+4, myvector.end(), myfunction); // 12 32 45 71(26 33 53 80)

  // using object as comp
  std::sort (myvector.begin(), myvector.end(), myobject);     //(12 26 32 33 45 53 71 80)

  // print out content:
  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;

```

### 4.2 is_sorted

```cpp
template <class ForwardIterator>
bool is_sorted (ForwardIterator first, ForwardIterator last);

template <class ForwardIterator, class Compare>
bool is_sorted (ForwardIterator first, ForwardIterator last, Compare comp);
```

**Check whether range is sorted**

Returns true if the range [first,last) is sorted into ascending order.

The elements are compared using operator< for the first version, and comp for the second.

```cpp
// is_sorted example
#include <iostream>     // std::cout
#include <algorithm>    // std::is_sorted, std::prev_permutation
#include <array>        // std::array

int main () {
  std::array<int,4> foo {2,4,1,3};

  do {
    // try a new permutation:
    std::prev_permutation(foo.begin(),foo.end());

    // print range:
    std::cout << "foo:";
    for (int& x:foo) std::cout << ' ' << x;
    std::cout << '\n';

  } while (!std::is_sorted(foo.begin(),foo.end()));

  std::cout << "the range is sorted!\n";

  return 0;
}
```

## 5 Binary search

### 5.1 binary_search

```cpp
template <class ForwardIterator, class T>
bool binary_search (ForwardIterator first, ForwardIterator last, const T& val);

template <class ForwardIterator, class T, class Compare>
bool binary_search (ForwardIterator first, ForwardIterator last, const T& val, Compare comp);
```

**Test if value exists in sorted sequence**

Returns true if any element in the range [first,last) is equivalent to val, and false otherwise.

The elements are compared using operator< for the first version, and comp for the second. Two elements, a and b are considered equivalent if (!(a\<b) && !(b\<a)) or if (!comp(a,b) && !comp(b,a)).

The elements in the range shall already be sorted according to this same criterion (operator\< or comp), or at least partitioned with respect to val.

```cpp
// binary_search example
#include <iostream>     // std::cout
#include <algorithm>    // std::binary_search, std::sort
#include <vector>       // std::vector

bool myfunction (int i,int j) { return (i<j); }

int main () {
  int myints[] = {1,2,3,4,5,4,3,2,1};
  std::vector<int> v(myints,myints+9);                         // 1 2 3 4 5 4 3 2 1

  // using default comparison:
  std::sort (v.begin(), v.end());

  std::cout << "looking for a 3... ";
  if (std::binary_search (v.begin(), v.end(), 3))
    std::cout << "found!\n"; else std::cout << "not found.\n";

  // using myfunction as comp:
  std::sort (v.begin(), v.end(), myfunction);

  std::cout << "looking for a 6... ";
  if (std::binary_search (v.begin(), v.end(), 6, myfunction))
    std::cout << "found!\n"; else std::cout << "not found.\n";

  return 0;
}
```

## 6 Merge 

## 7 Heap

## 8 Min/max

### 8.1 min

```cpp
template <class T>
const T& min (const T& a, const T& b);

template <class T, class Compare>
const T& min (const T& a, const T& b, Compare comp);	
```

**Return the smallest**

Returns the smallest of a and b. If both are equivalent, a is returned.

### 8.2 max

```cpp
template <class T>
const T& max (const T& a, const T& b);

template <class T, class Compare>
const T& max (const T& a, const T& b, Compare comp);
```

**Return the largest**

Returns the largest of a and b. If both are equivalent, a is returned.

### 8.3 minmax

**Return smallest and largest elements**

Returns a pair with the smallest of a and b as first element, and the largest as second. If both are equivalent, the function returns make_pair(a,b).

**Example**

```cpp
// minmax example
#include <iostream>     // std::cout
#include <algorithm>    // std::minmax

int main () {
  auto result = std::minmax({1,2,3,4,5});

  std::cout << "minmax({1,2,3,4,5}): ";
  std::cout << result.first << ' ' << result.second << '\n';
  return 0;
}
```

**Return smallest and largest elements**

Returns a pair with the smallest of a and b as first element, and the largest as second. If both are equivalent, the function returns make_pair(a,b).

### 8.4 min_element

```cpp
template <class ForwardIterator>
ForwardIterator min_element (ForwardIterator first, ForwardIterator last);

template <class ForwardIterator, class Compare>
ForwardIterator min_element (ForwardIterator first, ForwardIterator last, Compare comp);
```

**Return smallest element in range**

Returns an iterator pointing to the element with the smallest value in the range [first,last).

### 8.5 max_element

```cpp
// min_element/max_element example
#include <iostream>     // std::cout
#include <algorithm>    // std::min_element, std::max_element

bool myfn(int i, int j) { return i<j; }

struct myclass {
  bool operator() (int i,int j) { return i<j; }
} myobj;

int main () {
  int myints[] = {3,7,2,5,6,4,9};

  // using default comparison:
  std::cout << "The smallest element is " << *std::min_element(myints,myints+7) << '\n';
  std::cout << "The largest element is "  << *std::max_element(myints,myints+7) << '\n';

  // using function myfn as comp:
  std::cout << "The smallest element is " << *std::min_element(myints,myints+7,myfn) << '\n';
  std::cout << "The largest element is "  << *std::max_element(myints,myints+7,myfn) << '\n';

  // using object myobj as comp:
  std::cout << "The smallest element is " << *std::min_element(myints,myints+7,myobj) << '\n';
  std::cout << "The largest element is "  << *std::max_element(myints,myints+7,myobj) << '\n';

  return 0;
}
```

### 8.6 minmax_element

```cpp
template <class ForwardIterator>
pair<ForwardIterator,ForwardIterator> minmax_element (ForwardIterator first, ForwardIterator last);

template <class ForwardIterator, class Compare>
pair<ForwardIterator,ForwardIterator> minmax_element (ForwardIterator first, ForwardIterator last, Compare comp);
```

**Return smallest and largest elements in range**

Returns a pair with an iterator pointing to the element with the smallest value in the range [first,last) as first element, and the largest as second.

```cpp
// minmax_element
#include <iostream>     // std::cout
#include <algorithm>    // std::minmax_element
#include <array>        // std::array

int main () {
  std::array<int,7> foo {3,7,2,9,5,8,6};

  auto result = std::minmax_element (foo.begin(),foo.end());

  // print result:
  std::cout << "min is " << *result.first;
  std::cout << ", at position " << (result.first-foo.begin()) << '\n';
  std::cout << "max is " << *result.second;
  std::cout << ", at position " << (result.second-foo.begin()) << '\n';

  return 0;
}
```

## 9 Other

