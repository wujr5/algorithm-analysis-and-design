# cstring 库函数

## 1.1 memset

```cpp
void * memset ( void * ptr, int value, size_t num );
```

**例子**

```cpp
/* memset example */
#include <stdio.h>
#include <string.h>

int main () {
  char str[] = "almost every programmer should know memset!";
  memset (str, '-', 6);
  puts(str);
  return 0;
}
```

**output**

```cpp
------ every programmer should know memset!
```
