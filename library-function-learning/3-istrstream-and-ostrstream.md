# istrstream and ostrstream

## 1 istrstream

```cpp
istrstream::istrstream(char * buffer);
istrstream::istrstream(char * buffer, int n);
```

**Example**
```cpp
istrstream strin(ch);
```

使字符数组与字符串输入流建立关联。

## 2 ostrstream

```cpp
ostrstream::ostrstream(char * buffer, int n, int mode = ios::out);
```

**Example**

```cpp
ostrstream strout(ch, 20);
```

建立输出字符串刘对象strout，并于字符数组ch建立关联。