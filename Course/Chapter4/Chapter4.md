# 第四章 数论

## 1 知识点

### 1.1 自然数和整数

**自然数**

* 有一个起始的自然数0；
* 任何一个自然数都有后继；
* 0不是任何自然数的后继；
* 不同的自然数有不同的后继；
* 存在一组与自然数有关的命题。假设此命题对起始的自然数0成立，如果该命题对任一自然数成立可以推导出对其后继也成立，则此命题对所有自然数都成立。

**整数**

* 负整数与自然数一起构成整数

**整除**

* 一个整数a能被另一个整数d整除，记做d|a，意味着存在某个整数k，有a=kd。
* 如果a >0且 d|a，则IdI <= IaI ；
* 如果d|a，则我们称a是d的倍数（Multiple）；
* 如果d|a且d>0,则称d是a的约数（Divisor）；
* 一个整数a的约数最小为1，最大为IaI ，每个整数a都可被其平凡约数1和a整除； a的非平凡约数也称为a的因子（Factor）；

> 例：30的约数为1，3，5，6，10，15，30，其中3，5，6，10，15为30的因子

**整除的性质** 

* 如果d|a，则对于任意整数k有d|ka
* 如果d|a且d|b，则d|(a±b)
* 如果b|a 且a|b ，则a=b
* 如果a|b且b|c，则a|c
* 整除关系具有传递性，由于它显然也具有自反性和反对称性，所以它是一个偏序关系。

**几种特殊的整除的例子**

* 若2能整除a的最末位，则2|a；若4能整除a的最后两位，则4|a；若8能整除a的最末三位，则8|a；……
* 若5能整除a的最末位，则5|a；若25能整除a的最后两位，则25|a；若125能整除a的最末三位，则125|a ；……
* 若3能整除a的各位数字之和，则3|a；若9能整除a的各位数字之和，则9|a
* 若11能整除a的偶数位数字之和与奇数位数字之和的差，则11|a

### 1.2 最大公约数

**公约数**

* 如果d是a的约数并且也是b的约数，则d是a与b的公约数(Common Divisor)
* 1是任意两个整数的公约数

**最大公约数（Greatest Common Divisor ）**

* 所有公约数中最大的一个，记做gcd(a,b) 

**最大公约数的性质**

* gcd(a,ka)=|a|
* 对任意整数a与b，如果d|a且d|b，则d|gcd(a,b)
* 对所有整数a和b以及任意非负整数n，gcd(an,bn)=ngcd(a,b)
* 对所有正整数d,a和b，如果d|ab并且gcd(a,d)=1，则d|b
* 如果q和r是a除以b的商和余数，即a=bq+r，则gcd(a,b)=gcd(b,r)

**另一种不用除法的gcd算法（a>=b)**

* 1)若a=b,则gcd(a,b)=a;
* 2)若a,b均为偶数，则gcd(a,b)=2xgcd(a/2,b/2);
* 3)若a为偶数,b为奇数,则gcd(a,b)=gcd(a/2,b);
* 4)若a,b均为奇数，则gcd(a,b)=gcd(a-b,b);

### 1.3 最小公倍数

**公倍数**

* 如果m是a的倍数并且也是b的倍数，则m是a与b的公倍数 

**最小公倍数**

* 所有公倍数中最小的那个，记做`lcm(a,b)`

**最小公倍数的性质**

```cpp
lcm(a,b) = a * b / gcd(a,b);
```

### 1.4 辗转相除法求最大公约数

**原理**

* 如果q和r是a除以b的商和余数，即a=bq+r，则gcd(a,b)=gcd(b,r)

**举例**

```cpp
gcd(1001,767)
=gcd(767,234)
=gcd(234,65)
=gcd(65,39)
=gcd(39,26)
=gcd(26,13)
=gcd(13,0)
=13
```

**代码**

辗转相除法求最大公约数

```cpp
// 要求a,b不同时为0
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

```

利用最大公约数求最小公倍数

```cpp 
int lcm(int a, int b) {
	if (a * b == 0) {
    	return 0;
    }
    return a * b / gcd(a, b);
}
```

### 1.5 同余

**同余**

* 设m是正整数，a,b是整数，如果m|(a-b)，则称a和b关于模m同余，记作a≡b(mod m)或者说，如果a,b除以m的余数相等，则称a和b关于模m同余

**同余的性质**

* a≡a(mod m)
* 如果a≡b(mod m)，则b≡a(mod m)
* 如果a≡b(mod m)且b≡c(mod m)， a≡c(mod m)
* 如果a≡b(mod m)且c≡d(mod m)，则a±c≡b± d(mod m)， ac≡bd(mod m)
* 如果a≡b(mod m)，则an≡bn(mod m)，n∈N
* 如果ac≡bc(mod m)，则a≡b(mod (m/gcd(c,m))
* 如果a≡b(mod m)且d|m，则a≡b(mod d)
* 如果a≡b(mod m)，则ad≡bd(mod m)
* 如果a≡b(mod mi)，i=1,2,…,n，l=lcm(m1,m2,…,mn)，则a≡b(mod l)
* 如果p为素数，则ap ≡ a(mod p)；如果gcd(a,p)=1，则ap-1 ≡ 1(mod p)

### 1.6 素数和合数

**基础**

* 素数
	* 自然数中，除了1之外，只能被1和该数自身整除的数
* 大于1的正整数ρ，如果仅有的正因子是1和ρ则称ρ为素数（prime）。大于1又不是素数的正整数称为合数（compound）。如果n是合数，那么n必有一个小于或等于sqrt(n) 的素因子。
* 其他
	* 2是最小的素数
	* 2是唯一一个偶素数
* 算术基本定理
	* 每个正整数都可以惟一地表示成素数的乘积，其中素数因子从小到大依次出现（这里的“乘积”可以有0个、1个或多个素因子）。

**筛法求素数**

```cpp
const int MAX = 10000;
bool prime[MAX + 1];
void searchprime() {
	memset(prime, true, sizeof(prime));
	prime[1] = false;
	for (int i = 2; i <= (int) floor(sqrt(MAX)); ++i) {
    	if (prime[i]) {
			int j = i * 2;
            while (j <= MAX) {
        		prime[j] = false;
        		j += i;
            }
        }
	}
}
```

**素数的判定**

* 原始的判定方法，根据素数的定义
* 改进的判定方法1，x可以分解为两个整数a,b的积，即 x=a*b，a≤b，那么a ≤sqrt(x)
* 改进的判定方法2，其实2到x的平方根中那些合数也是没有必要用来判断的。如果事先生成一个素数表，循环的次数还可以降低。利用素数表来求解。

**原始的素数判定方法**

```cpp
bool isPrime(int x) {
    for (int i = 2; i < x; ++i) {
    	if (x % i == 0) {
   			return false;
    	}
    }
    return true;
}
```

**改进的素数判定方法1**

```cpp
bool isPrime(int x) {
    for (int i = 2; i <= (int) floor(sqrt(x)); ++i) {
    	if (x % i == 0) {
      		return false;
    	}
    }
    return true;
}
```

**改进的素数判定方法2**

```cpp
bool isPrime(int x) {
    int i = 0;
    // list[]是预先生成好的素数表
    while (list[i] * list[i] <= x) {  // 慎防乘积溢出
        if (x % list[i] == 0) {
        	return false;
        }
        ++i;
    }
    return true;
}
```

## 2 解题样例

### 2.1 K尾相等数

**描述**

* 对于一个自然数K（K>1），若存在自然数M和N（M>N），使得K^M^和K^N^均大于或等于1,000，且它们的末尾三位数相等，则称M和N是一对“K尾相等数”。

* 求M+N值最小的K尾相等数。

**分析**

对于一个数，它的幂是无穷无尽的，但是我们可以注意到末尾三位数只有1,000个，也就是表明一定会有重复的末尾三位数，当一个数的末尾三位数一定时，它的下一次幂的末尾三位数也一定了。也就是说当第一次重复出现大于等于1,000的末尾三位数时，这就是我们要求的M和N。 

**注意问题**

* K^M^和K^N^要大于或等于1,000
	* 25: 25 625 15625 390625
	* 对应的末位：25 625 625 625
* K要做预处理
	* K mod 1000
	* 1025：1025 1050625 1103812890625 1159693418212890625
	* 对应的末位：25 625 625 625

**程序实现**

```cpp
int i, j, k, n, p1, i1, ti, bj;
int time[1001];

int main() {
  cin >> n;
  memset(time, 0, sizeof(time));
  
  i = n;
  k = 1;
  j = 0;
  ti = 0;
  bj = 0;
  
  if (i >= 1000) {
    bj = 1;
    i = i % 1000;
  }
  
  do {
    ti = ti + 1;
    k = i * k;
    if (k >= 1000 || bj == 1) {
      k = k % 1000;
      if (time[k] == 0) time[k] = ti;
      else j = k;
      bj = 1;
    }
  } while (j == 0);
  
  cout << time[j] + ti;
  return 0;
}
```

### 2.2 3n+1数链问题

有这样一个问题，如下：
```
1. 输入一个正整数n；
2. 如果n=1则结束；
3. 如果n是奇数则n变为3*n+1，否则n变为n/2；
4. 转入第2步。
```
例如对于输入的正整数22，则数列为：
```
22  11  34  17  52  26  13  40  20  10  5  16  8  4  2  1
```
对于任意一个正整数，经过以上算法最终会推到1。对于给定的正整数n，我们把显示出来的数的个数定义为n的链长，例如22的链长为16。

对于任意一对正整数i和j，求i、j之间的最长链长。

**问题分析**

这是一道很简单的题目，无大多其他的技巧，只需要按照题目的要求一步步做下去即可。对于每一个正整数，可以很容易求得它的数链长度。

**要注意的问题**

* i、j之间包括i和j
	* 题目的例子i=1, j=10

![image](https://cloud.githubusercontent.com/assets/7693440/11343688/1d664c1e-9248-11e5-9c64-6b40a452a7f0.png)

* 进一步的优化
	* 记录下1至10000所有的链长

**程序实现**

```cpp
int  a, b, maxlen;

int linklen(int x) {
  int l = 1;
  while (x != 1) {
    ++l;
    if (x & 1) x = x * 3 + 1;  // 如果X为奇数，则X=3X+1
    else x = x / 2;  // 如果X为偶数，则X=X/2
  }
  return l;
}

void run {
  int i, l;
  for (i = a; i <= b; ++i) {
    l = linklen(i);
    if (l > maxlen) maxlen = l;
  }
}

int main() {
  freopen("LINK.IN", "r", stdin);
  freopen("LINK.OUT", "w", stdout);
  cin >> a >> b;
  maxlen = 0;
  run();
  cout << maxlen;
  return 0;
}
```

### 2.3 负权数

对R进制数N，其绝对值可以用各位的数码乘以R的幂：
```cpp
N=an×R^n+a(n-1)×R^(n-1)+…+a0×R0 //a0,a1,a2...an一次排列的权值
```
来表示。这里的R可以是正数也可以是负数。当R是负数时，我们称之为负权数。 
举例来说，10进制数-15用-2进制数来表示就是
```cpp
110001：-15=1×(-2)^5+1×(-2)^4+1×(-2)^0
```
求10进制数的R进制的形式。

**问题分析**

当R≥2时，通过连除求余的方法可以得到任意一个十进制正整数N的R进制形式：

![image](https://cloud.githubusercontent.com/assets/7693440/11343940/800ecc0a-9249-11e5-94b6-35f72a5d8911.png)

![image](https://cloud.githubusercontent.com/assets/7693440/11344041/08604eb2-924a-11e5-9131-f1a435421598.png)

* 例：N=53, R=-2
    * 53(10)=110101(2)
    * 53 = 1×|-2|5+ 1×|-2|4+ 1×|-2|2+ 1×|-2|0
    * 1×|-2|5 =1×(-2)6 +1×(-2)5 
    * 1×|-2|4 =1×(-2)4，1×|-2|2 =1×(-2)2，1×|-2|0 =1×(-2)0
    * 53 = 1×(-2)6 +1×(-2)5 +1×(-2)4+1×(-2)2+1×(-2)0
    * 53(10) = 1110101(-2)

![image](https://cloud.githubusercontent.com/assets/7693440/11344163/967814d2-924a-11e5-82eb-3956d3910788.png)

**要注意的问题**

进位问题
```cpp
N = 6, R = -2
1. 6(10) = 110(2)
2. 6 = 1× |-2|^2 + 1 × |-2|^1
3. 1×|-2|^1 = 1×(-2)^2+1×(-2)^1
4. 1×|-2|^2 = 1×(-2)^2
5. 6(10) = 210(-2)?
6. 2×(-2)^2 = 1×|-2|^3=1×(-2)^4+1×(-2)^3
7. 6(10) = 11010(-2)
```

**程序实现**

```cpp
int n, r, len;
int a[17];

void comput() {
  int i, p, n1, r1;
  n1 = abs(n);
  r1 = abs(r);
  len = -1;
  memset(a, 0, sizeof(a));
  // 通过连除求余得到|N|的|R|进制形式
  while (n1 > 0) {
    ++len;
    a[len] = n1 % r1;
    n1 = n1 / r1;
  }
 // 以下是将|N|的|R|进制形式转化成N的R进制形式，具体数学原理见②③④⑤⑥⑦式
  if (n > 0) p = 1;
  else p = 0;
  while (p <= len) {
    if (a[p] > 0) {
      // 向A[P+1]位进1
      ++a[p+1];
      i = p + 1;
      // 进位
      while (a[i] >= r1) {
        a[i] -= r1;
        ++i;
        ++a[i];
      }
     // 若进位导致长度增加则更新长度
      if (i > len) len = i;
      a[p] = r1 - a[p];
    }
    p += 2;
  }
}

// 打印
void print() {
  int i;
  for (i = len; i >= 0; --i) {
    if (a[i] < 10) cout << a[i];
    else cout << (char) (a[i] + 55);
  }
  cout << endl;
}

void run() {
  // 若读到数据文件的结束符号，程序结束
  while (cin >> n >> r) {
     // 无论在什么进制，0仍是0
    if (n == 0) cout << 0 << endl;
    else {
      comput();
      print();
    }
  }
}

int main() {
  freopen(“NEGATIVE.IN”, “r”, stdin);
  freopen(“NEGATIVE.OUT”, “w”, stdout);
  run();
  return 0;
}
```

### 2.4 质多项式
### 2.5 猴子舞
### 2.6 数制转换
### 2.7 大众批萨

## 3 Sicily作业
