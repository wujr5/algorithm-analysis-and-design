# istream

## 1 getcount
```cpp
streamsize gcount() const;
```

**Get character count**

Returns the number of characters extracted by the last unformatted input operation performed on the object.

The unformatted input operations that modify the value returned by this function are: get, getline, ignore, peek, read, readsome, putback and unget.

Notice though, that peek, putback and unget do not actually extract any characters, and thus gcount will always return zero after calling any of them.

```cpp
cin.getcount();
```

## 2 get

```cpp
single character (1):
    int get();
    istream& get (char& c);
c-string (2):
    istream& get (char* s, streamsize n);
    istream& get (char* s, streamsize n, char delim);
stream buffer (3):
    istream& get (streambuf& sb);
    istream& get (streambuf& sb, char delim);
```

## 3 getline

```cpp
istream& getline (char* s, streamsize n );
istream& getline (char* s, streamsize n, char delim );
```

```cpp
// istream::getline example
#include <iostream>     // std::cin, std::cout

int main () {
  char name[256], title[256];

  std::cout << "Please, enter your name: ";
  std::cin.getline (name,256);

  std::cout << "Please, enter your favourite movie: ";
  std::cin.getline (title,256);

  std::cout << name << "'s favourite movie is " << title;

  return 0;
}
```

## 4 ignore

```cpp
istream& ignore (streamsize n = 1, int delim = EOF);
```

**Extract and discard characters**

Extracts characters from the input sequence and discards them, until either n characters have been extracted, or one compares equal to delim.

```cpp
// istream::ignore example
#include <iostream>     // std::cin, std::cout

int main () {
  char first, last;

  std::cout << "Please, enter your first name followed by your surname: ";

  first = std::cin.get();     // get one character
  std::cin.ignore(256,' ');   // ignore until space

  last = std::cin.get();      // get one character

  std::cout << "Your initials are " << first << last << '\n';

  return 0;
}
```

## 5 getline(string)

```cpp
(1)	istream& getline (istream& is, string& str, char delim);
(2)	istream& getline (istream& is, string& str);
```

**Get line from stream into string**

Extracts characters from is and stores them into str until the delimitation character delim is found (or the newline character, '\n', for (2)).

The extraction also stops if the end of file is reached in is or if some other error occurs during the input operation.

If the delimiter is found, it is extracted and discarded (i.e. it is not stored and the next input operation will begin after it).

Note that any content in str before the call is replaced by the newly extracted sequence.

Each extracted character is appended to the string as if its member push_back was called.

**Example**

```cpp
// extract to string
#include <iostream>
#include <string>

main ()
{
  std::string name;

  std::cout << "Please, enter your full name: ";
  std::getline (std::cin,name);
  std::cout << "Hello, " << name << "!\n";

  return 0;
}
```