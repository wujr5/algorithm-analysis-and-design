# cstring 库函数

## 1.1 memset

```cpp
void * memset ( void * ptr, int value, size_t num );
```

value其实会被视为unsigned char，然后以字节，也就是8位为单位，逐个byte更新ptr的值。对把int，float，double的数组清0，或者char数组设置字符，或者bool数组设置true or false有用。

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
