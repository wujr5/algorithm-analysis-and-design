# cstring 库函数

## 1 other

### 1.1 memset

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

### 1.2 strlen

```cpp
size_t strlen ( const char * str );
```

## 2 Copying

### 2.1 memcpy
```cpp
void * memcpy ( void * destination, const void * source, size_t num );
```

### 2.2 memmove
```cpp
void * memmove ( void * destination, const void * source, size_t num );
```

### 2.3 strcpy
```cpp
char * strcpy ( char * destination, const char * source );
```
### 2.4 strncpy
```cpp
char * strncpy ( char * destination, const char * source, size_t num );
```

## 3 Concatenation

### 3.1 strcat
```cpp
char * strcat ( char * destination, const char * source );
```

### 3.2 strncat
```cpp
char * strncat ( char * destination, const char * source, size_t num );
```

## 3 Comparison

### 3.1 memcmp
```cpp
int memcmp ( const void * ptr1, const void * ptr2, size_t num );
```

比较指定长度的内存块的大小。遇到`\0`不结束。

### 3.2 strcmp
```cpp
int strcmp ( const char * str1, const char * str2 );
```

比较两个字符串的大小。遇到`\0`结束。二进制数比较。

### 3.3 strncmp
```cpp
int strncmp ( const char * str1, const char * str2, size_t num );
```

## 4 Searching

### 4.1 memchr
Locate character in block of memory
```cpp
const void * memchr ( const void * ptr, int value, size_t num );
      void * memchr (       void * ptr, int value, size_t num );
```

### 4.2 strchr
Locate first occurrence of character in string
```cpp
const char * strchr ( const char * str, int character );
      char * strchr (       char * str, int character );
```
### 4.3 strrchr
Locate last occurrence of character in string
```cpp
const char * strrchr ( const char * str, int character );
      char * strrchr (       char * str, int character );
```
### 4.4 strstr
Locate substring
```cpp
const char * strstr ( const char * str1, const char * str2 );
      char * strstr (       char * str1, const char * str2 );
```
### 4.5 strtok
Split string into tokens
```cpp
char * strtok ( char * str, const char * delimiters );
```
Example
```cpp
/* strtok example */
#include <stdio.h>
#include <string.h>

int main ()
{
  char str[] ="- This, a sample string.";
  char * pch;
  printf ("Splitting string \"%s\" into tokens:\n",str);
  pch = strtok (str," ,.-");
  while (pch != NULL)
  {
    printf ("%s\n",pch);
    pch = strtok (NULL, " ,.-");
  }
  return 0;
}
```

Output
```cpp
Splitting string "- This, a sample string." into tokens:
This
a
sample
string
```

### 4.6 strcspn

**Get span until character in string**

Scans str1 for the first occurrence of any of the characters that are part of str2, returning the number of characters of str1 read before this first occurrence.

The search includes the terminating null-characters. Therefore, the function will return the length of str1 if none of the characters of str2 are found in str1.

Example

```cpp
/* strcspn example */
#include <stdio.h>
#include <string.h>

int main ()
{
  char str[] = "fcba73";
  char keys[] = "1234567890";
  int i;
  i = strcspn (str,keys);
  printf ("The first number in str is at position %d.\n",i+1);
  return 0;
}
```

Output
```cpp
The first number in str is at position 5
```

### 4.7 strspn

**Get span of character set in string**

Returns the length of the initial portion of str1 which consists only of characters that are part of str2.

The search does not include the terminating null-characters of either strings, but ends there.
```cpp
size_t strspn ( const char * str1, const char * str2 );
```

Example
```cpp
/* strspn example */
#include <stdio.h>
#include <string.h>

int main ()
{
  int i;
  char strtext[] = "129th";
  char cset[] = "1234567890";

  i = strspn (strtext,cset);
  printf ("The initial number has %d digits.\n",i);
  return 0;
}
```

Output
```cpp
The initial number has 3 digits
```

### 4.8 strpbrk
```cpp
const char * strpbrk ( const char * str1, const char * str2 );
      char * strpbrk (       char * str1, const char * str2 );
```

**Locate characters in string**

Returns a pointer to the first occurrence in str1 of any of the characters that are part of str2, or a null pointer if there are no matches.

The search does not include the terminating null-characters of either strings, but ends there.

Example
```cpp
/* strpbrk example */
#include <stdio.h>
#include <string.h>

int main ()
{
  char str[] = "This is a sample string";
  char key[] = "aeiou";
  char * pch;
  printf ("Vowels in '%s': ",str);
  pch = strpbrk (str, key);
  while (pch != NULL)
  {
    printf ("%c " , *pch);
    pch = strpbrk (pch+1,key);
  }
  printf ("\n");
  return 0;
}
```

output
```cpp
Vowels in 'This is a sample string': i i a a e i
```