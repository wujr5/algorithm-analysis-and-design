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

给定多项式f(x)=anxn+an-1xn-1+…+a0x0，如果an≠0，称f(x)是一个n次多项式。

给定多项式f(x)，如果找不到次数至少为1的多项式g(x)和h(x)满足f(x)=g(x)h(x)，称f(x)是质多项式。

为了简化起见，规定多项式的各项的系数只能取0或1。并且重新定义在{0,1}上的加法和乘法：
```cpp
0+0=0, 0+1=1, 1+0=1, 1+1=0
0×0=0, 0×1=0, 1×0=0, 1×1=1
```
问题：对给定的正整数k，求出次数为k的质多项式，满足a^k^*2k+a*^k-1^2(k-1)+…+a^0^*2(0)的值最小。

**问题分析**

* 用求素数的方法求解
* 核心问题是如何实现多项式除法


![image](https://cloud.githubusercontent.com/assets/7693440/11344448/5a878672-924c-11e5-9afd-0e52bb4f369c.png)
![image](https://cloud.githubusercontent.com/assets/7693440/11344454/5ff1d680-924c-11e5-9db4-477c8e27f544.png)
![image](https://cloud.githubusercontent.com/assets/7693440/11344460/664b4368-924c-11e5-97ed-4930a7e3a997.png)


加法

* 0+0=0, 0+1=1, 1+0=1, 1+1=0
	* 0 XOR 0 = 0
	* 0 XOR 1 = 1
	* 1 XOR 0 = 1
	* 1 XOR 1 = 0

* 其逆运算减法也是异或运算

**需要注意的问题**

* 除了次数为1的情况，质多项式都包含常数项1；
* 系数只能为0和1的n次多项式共有2n个；
* 从素数得到的经验：
	* n次质多项式不止一个
	* 第一个n次质多项式离xn不会太远

**程序实现**

```cpp
int bin[31];
int k, now, i;
bool flag;

int weight(int w) {
  int i;
  for (i = 30; i >= 0; --i) {
    if (bin[i] <= w) {
      return i;
    }
  }
}

// 多项式除法
bool divide(int a, int b) {
  int wa, wb;

  wa = weight(a);
  wb = weight(b);
  b = b << (wa - wb);
 while (a != b && wa >= wb) {
    a ^= b;
    while (bin[wa] > a) {
      --wa;
      b >>= 1;
    }
  }
  return (wa >= wb);
}
void init() {
  int i;
  bin[0] = 1;
  for (i = 1; i <= 30; ++i) {
    bin[i] = bin[i - 1] * 2;
  }
}
void print(int p) {
  int i;
  if (k == 1) {
    cout << ‘x’ << endl;
    return;
  }
 for (i = 30; i >= 1; --i) {
    if (bin[i] <= p) {
      p -= bin[i];
      cout << “x^” << i << ‘+’;
    }
  cout << 1 << endl;
}
int main() {
  freopen(“PRIME.IN”, “r”, stdin);
  freopen(“PRIME.OUT”, “w”, stdout);
  init();
  cin >> k;
 while (k != 0) {
    now = bin[k] - 1;
    do {
      now += 2;
      flag = true;
      for (i = 2; i <= bin[(k+1) / 2+1]-1; ++i) {
        if (divide(now, i)) {
          flag = false;
          break;
        }
    } while (!flag);
    print(now);
    cin >> k;
  }
  return 0;
}
```

### 2.5 猴子舞(选讲)

* 猴子舞是由N只猴子同时进行的。开始时，地上有N个圆圈，每个圆圈上站了一只猴子。地上还有N个箭头，每个圆圈恰好是一个箭头的起点和另一个箭头的终点，并且没有一个圆圈同时是某个箭头的起点和终点。表演开始时，所有的猴子同时按它所站的圆圈的箭头的方向跳到另一个圆圈中，这作为一步。当所有的猴子都回到自己原来所站的圆圈时，表演便结束了。

* 求对于N可以达到的最大步数。

**问题分析**

* 建模
![image](https://cloud.githubusercontent.com/assets/7693440/11344539/f98a0128-924c-11e5-833d-100b59629796.png)

* 搜索法
```
枚举所有可能的分解方式，求lcm(最小公倍数）
搜索范围比较大
lcm需要用到高精度乘法
```

* 搜索剪枝
![image](https://cloud.githubusercontent.com/assets/7693440/11344556/1736134c-924d-11e5-959c-1d6bd3a2d7fd.png)

**需要注意的问题**

* 不能有长度为1的圈

**程序实现**

```cpp
const int MAXN = 300;

typedef int TArray[100];

struct TLongint {
  int len;
  TArray data;
};

int nl, sk, num; 
TArray list, index, sindex;
TLongint max;

// 比较两高精度数的大小
bool bigger(TLongint i1, TLongint i2) {
  int pos;
  if (i1.len != i2.len) {
    return (i1.len > i2.len);
  }
  pos = i1.len - 1;
  while (pos >= 0 && i1.data[pos] == i2.data[pos]) {
    --pos;
  }
  if (pos < 0) {
    return false;
  }
  return (i1.data[pos] > i2.data[pos]);
}

// 乘数在integer范围内的高精度乘法
void longmul(TLongint &m, int n) {
  int i, c;
  c = 0;
  for (i = 0; i <= m.len-1; ++i) {
    c += m.data[i] * n;
    m.data[i] = c % 10;
    c /= 10;
  }  

  while (c != 0) {
    m.data[m.len] = c % 10;
    c /= 10;
    ++m.len;
  }
}

// 求一定范围内(<=MAXN)的素数
void getprimes() {
  int i, j;
  bool flag;
  memset(list, 0, sizeof(list));
  list[0] = 6; list[1] = 2; nl = 2;

  for (i = 3; i <= MAXN; ++i) {
    flag = true;
    for (j = 1; j <= nl - 1; ++j) {
      if (i % list[j] == 0) {
        flag = false;
        break;
      }
    }
    if (flag) {
      list[nl] = i;
      ++nl;
    }
  }
  list[nl] = MAXN;
}
// 对目前的搜索方案计算可以得到的步数
void checkresult(int remain, int k) {
  TLongint res;
  int i, j;

  if (remain == 1) return;
  memset(res, 0, sizeof(res));
  res.len = 1;
  res.data[0] = 1;

 for (i = 1; i <= k; ++i) {
    if (index[i] > 0) {
       for (j = 0; j <= index[i] - 1; ++j) {
         longmul(res, list[i]);

 // 特殊处理2和3两个素数
  if (index[0] == 0) {
    if (index[1] == 0 && (remain == 2 || remain > 3)) {
      longmul(res, 2);
    }
    if (index[2] == 0 && remain % 2 == 1) {
      longmul(res, 3);
    }
  } else {
    if (index[1] == 0) longmul(res, 2);
    longmul(res, 3);
  }

 // 特殊处理2和3两个素数
  if (index[0] == 0) {
    if (index[1] == 0 && (remain == 2 || remain > 3)) {
      longmul(res, 2);
    }
    if (index[2] == 0 && remain % 2 == 1) {
      longmul(res, 3);
    }
  } else {
    if (index[1] == 0) longmul(res, 2);
    longmul(res, 3);
  }
  if (val > num) {
    checkresult(num, k - 1);
    return;
  }
  findresult(num, k+1);
  ++index[k];
  if (k < 3) {
    ++index[k];
    val = val * list[k];
  }

  while (val < num - 1) {
    findresult(num - val, k + 1);
    val = val * list[k];
    ++index[k];
  }
  if (val == num) checkresult(0, k);
}

// 含有1元素的搜索
void findresult1(int num, int k) {
  int val;

  val = list[k];
  index[k] = 0;

  if (val > num) {
    if (num == 2 || num == 4) {
      checkresult(num, k - 1);
    }
    return;
  }

  findresult1(num, k + 1);
  if (k == 2) return;
  ++index[k];
  if (k == 1) {
    ++index[k];
    val = val * list[k];
  }

  while (val < num - 1) {
    findresult1(num - val, k + 1);
    val = val * list[k];
    ++index[k];
  }
  if (val == num) checkresult(0, k);
}

void printresult() {
  int i;
  for (i = max.len - 1; i >= 0; --i) {
    cout << max.data[i];
  }
  cout << endl;
}

void process(int num) {
  memset(max, 0, sizeof(max));
  memset(index, 0, sizeof(index));
  findresult(num, 1);

  if (num >= 6) {
    index[0] = 1;
    index[1] = 0;
    index[2] = 0;
    if (num > 6) findresult1(num - 6, 1);
    else checkresult(0, 0);
  }
  printresult();
}

int main() {
  freopen(“DANCE.IN”, “r”, stdin);
  freopen(“DANCE.OUT”, “w”, stdout);
  getprimes();
  cin >> num;

  while (num > 0) {
    process(num);
    cin >> num;
  }
  return 0;
}
```

### 2.6 数制转换

有一种数制的基数是3，权值可取-1,0,1，并分别用符号-,0,1表示，这种数制的101表示十进制数10，即
```cpp
1×32+0×31+1×30=10，
```
这种数制的-0表示十进制数的-3，即
```cpp
-1×31+0×30=-3。
```
要求把给定的有符号整数转换为新数制的数。

**证明存在性**

![image](https://cloud.githubusercontent.com/assets/7693440/11344751/192f6738-924e-11e5-89cf-ad192345109d.png)

**证明唯一性**

![image](https://cloud.githubusercontent.com/assets/7693440/11344773/2c14179a-924e-11e5-8471-62fa8e46922c.png)

![image](https://cloud.githubusercontent.com/assets/7693440/11344781/403cb7c2-924e-11e5-8d0c-342d638269b5.png)

![image](https://cloud.githubusercontent.com/assets/7693440/11344793/58d0bc8e-924e-11e5-9d3b-1a9b5678cd49.png)


**程序实现**

```cpp
int src;
void handle(int x) {
  if (x > 0) {
    if (x % 3 == 0) {
      handle(x / 3);
      cout << 0;

    } else if (x % 3 == 1) {    
      handle((x - 1) / 3);
      cout << 1;
    } else {
      handle((x + 1) / 3);
      cout << '-';
    }
  } else if (x < 0) {
    if (-x % 3 == 0) {
      handle(x / 3);
      cout << 0;
    } else if (-x % 3 == 1) {
      handle((x + 1) / 3);
      cout << '-';
    } else {
      handle((x - 1) / 3);
      cout << 1;
    }
  }
}

int main() {
  freopen(“RADIX.IN”, “r”, stdin);
  freopen(“RADIX.OUT”, “w”, stdout);
  while (cin >> src) {
    if (src == 0) cout << 0;
    else handle(src);
    cout << endl;
  }
  return 0;
}

```

### 2.7 大众批萨

Pizza有A,B,…,P16种口味。可以用一行符号来描述某人接受的pizza。

**+O-H+P：**
表示某位朋友接受一个包含O口味，或不含H口味，或包含P口味的批萨；

**-E-I-D+A+J：**
表示某位朋友接受一个不含E口味或I口味或D口味的，或带有A口味或J口味的批萨。

给出一系列要求，求一种满足条件的Pizza。


**问题分析**

* 将每种批萨口味看成是一个布尔变量，用变量A的取值（True或False）表示批萨是否有A口味；将一个批萨看成是变量A,B,…,P的一组赋值，那么批萨ACFO就是A、C、F和O四个变量取值True，而其他变量取值False的一组赋值；将每条口味约束看成是变量A,B,…,P及其否定的析取式，例如，口味约束+O-H+P可以表示为O∨～H∨P；

* 将每个批萨约束看成是所有口味约束的合取式，考虑以下约束：
```cpp
+A+B
-C-D
+A-B
+C+D
```

* 等价于合取式：
```cpp
(A∨B)∧(～C∨～D)∧(A∨～B)∧(C∨D)
```

* 生成法
	* 将上合取式展开得AC～D∨A～CD∨ABC～D∨A～BC～D∨AB～CD∨A～B～CD
	* 每个析取元为True都可以满足要求，比如第一个析取元为AC～D，即一个包含AC口味且不含D口味的Pizza都是问题的解，包不包含B,E,F,…等口味对问题的解没有影响。

* 枚举法
	* 枚举批萨所有可能的口味组合；
	* 对每种口味组合，扫描批萨约束，判断是否符合要求。
* 用16位二进制数表示Pizza
* 两个16位二进制数表示口味需求
	* +A-B-D+E表示为：
		* Want: 10001000…0
		* Hate: 01010000…0
* 判断某个Pizza是否符合口味需求：
	* (Pizza and Want > 0) or (not Pizza and Hate > 0)

* 筛法
	* Pizza的口味总数为216=65536；
	* 建立口味列表，初始时所有口味都在列表中；
	* 枚举每种需求，用需求去过滤口味列表中的口味
	* 列表中剩下的口味就为问题的解

**程序实现**

```cpp
const int maxPerson = 16;
const int  maxToppings = 16;

short want[maxPerson + 1], hate[maxPerson + 1];
int pizzaID;
short mask, personCount, i;
string s;

int main() {
  freopen(“PIZZA.IN”, “r”, stdin);
  freopen(“PIZZA.OUT”, “w”, stdout);
  // 建立批萨约束
  personCount = 0;  // 初始化人数
  cin >> s;  // 读入批萨约束的字符串
  while (s != “.”) {
	++personCount;
    want[personCount] = 0;
    hate[personCount] = 0;
    for (i = 1; i <= (length(s) - 1) / 2; ++i) {

      mask = 1 << (int(s[2 * i]) - 65);
      if (s[2 * i - 1] == '+‘) {  // 要这种口味?
        want[personCount] |= mask
      } else {
        hate[personCount] |= mask;
      }
    }
    cin >> s;
  }

      mask = 1 << (int(s[2 * i]) - 65);
      if (s[2 * i - 1] == '+‘) {  // 要这种口味?
        want[personCount] |= mask
      } else {
        hate[personCount] |= mask;
      }
    }
    cin >> s;
  }

    // 批萨符合所有的口味约束
    if (i > personCount) break;
    ++pizzaID;
  } while (pizzaID != (1 << maxToppings));
  // 输出结果
  // 没有符合要求的批萨
  if (pizzaID == (1 << maxToppings)) {
    cout << “No pizza can satisfy these requests.”
        << endl;
  } else {

    // 批萨符合所有的口味约束
    if (i > personCount) break;
    ++pizzaID;
  } while (pizzaID != (1 << maxToppings));
  // 输出结果
  // 没有符合要求的批萨
  if (pizzaID == (1 << maxToppings)) {
    cout << “No pizza can satisfy these requests.”
        << endl;
  } else {

    cout << “Toppings: ”;
    //输出批萨的口味}
    for (i = 0; i <= maxToppings - 1; ++i) {
      if (((pizzaID >> i) & 1) == 1) {
        cout << (char) (i + 65);
      }
    }
    cout << endl;
  }
  return 0;
}
```

## 3 Sicily作业

* 1259 求连续素数和
* 1240 十进制少了4的计数
* 1231 求两个素数积
* 1214 数列找规律
* 1203 求一个数的立方的尾数是原数
* 1206 解方程
* 1099 线性方程
* 1020,1014,1119, 1382,1500
