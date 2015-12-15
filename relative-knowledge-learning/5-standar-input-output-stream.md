# 标准输入输出流的输入方输出式汇简单汇总

以下给出常用的c++的标准输入输出的简单汇总。

> 来自《C++程序设计 - 谭浩强》

在iostream头文件中定义的流对象：cin（标准输入）, cout（标准输出流）, cerr（标准错误流）, clog（标准错误流）

## 1 标准输入流

### 1.1 cin流

```cpp
cin >> variable;
```

如果读入正常，返回true，否则返回false。

### 1.2 用于字符输入的流成员函数

#### 1.2.1 cin.get读入一个字符

用法1：

```cpp
char c = cin.get();
```
功能与getchar()相同。

用法2：

```cpp
char c;
cin.get(c);
```

读取成功返回非0值，否则返回0值。

用法3：

```cpp
char c[100];
cin.get(c, 10, '\n');
```

读取n-1个字符，赋值给制定的字符数组。

#### 1.2.2 getline读取一行字符

```cpp
char c[100];
cin.getline(c, 10, '\n');
```

用法与`cin.get(char*, int, char)`相似。

### 1.3 istream类的其他成员函数

#### 1.3.1 eof

解释：end of file.
`cin.eof()`：判断是否到达文件末尾。

#### 1.3.2 peek

观察下一个字符。
`cin.peek()`;

#### 1.3.3 putback

```cpp
cin.putback(char c);
```

`cin.putback(c)`：将前面用get或者getline函数从输入流中读取的字符ch返回到输入流，插入到当前位置，供后面读取。

## 2 标准输出流

### 2.1 cout流

```cpp
cout << something;
```

### 2.2 格式输出

#### 2.2.1 使用控制符控制输入输出

<iomanip>

```cpp
dec // 基数为10
hex // 基数为16
oct // 基数为8
setbase(n) // 设置基数，只能是8, 16, 10
setfill(n) // 设置填充字符 
setprecision(n) // 设置精度
setw(n) // 设置字符宽度
setiosflags(ios::) 
	fixed // 固定小数位数显示
	scientific // 科学计数法（指数）形式表示
	left // 左对齐
	right // 右对齐
	skipws // 忽略前导空格
	uppercase // 科学计数法：E，十六进制：X
	showpos // 输出正数时给出“+”号
resetioflags() // 终止某个输出格式
```

#### 2.2.2 用流对象的成员函数控制输出格式

```cpp
cout.precision(n)
cout.width(n)
cout.fill(c)
cout.setf() // -> setiosflags
cout.unset() // -> resetioflags
```

### 2.3 用流成员函数put输出字符

```cpp
cout.put(char);
```

与c语言中的`putchar`功能相同。
