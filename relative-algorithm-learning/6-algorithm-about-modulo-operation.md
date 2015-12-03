# 取模运算涉及的算法

## 1 取模与取余的区别

对于整型数a，b来说，取模运算或者求余运算的方法都是：
```cpp
1.求整数商：c = a / b;
2.计算模或者余数：r = a - c * b;
```
求模运算和求余运算在**第一步不同**: 取余运算在取c的值时，**向0方向舍入**(fix()函数)；而取模运算在计算c的值时，向**负无穷方向**舍入(floor()函数)。

## 2 定义

* 给定一个正整数p，任意一个整数n，一定存在等式 ：
n = kp + r ；

* 其中 k、r 是整数，且 0 ≤ r < p，则称 k 为 n 除以 p 的商，r 为 n 除以 p 的余数。
* 对于正整数 p 和整数 a,b，定义如下运算：
	* 取模运算：a % p（或a mod p），表示a除以p的余数。
	* 模p加法： ，其结果是a+b算术和除以p的余数。
	* 模p减法： ，其结果是a-b算术差除以p的余数。
	* 模p乘法： ，其结果是 a * b算术乘法除以p的余数。
* 说明：
	1. 同余式：正整数a，b对p取模，它们的余数相同，记做 或者a ≡ b (mod p)。
	2. n % p 得到结果的正负由被除数n决定,与p无关。例如：7%4 = 3， -7%4 = -3， 7%-4 = 3， -7%-4 = -3。

## 3 基本性质

1. 若p|(a-b)，则a≡b (% p)。例如 11 ≡ 4 (% 7)， 18 ≡ 4(% 7)
2. (a % p)=(b % p)意味a≡b (% p)
3. 对称性：a≡b (% p)等价于b≡a (% p)
4. 传递性：若a≡b (% p)且b≡c (% p) ，则a≡c (% p)

## 4 运算规则

模运算与基本四则运算有些相似，但是除法例外。其规则如下：

```cpp
(a + b) % p = (a % p + b % p) % p （1）
(a - b) % p = (a % p - b % p) % p （2）
(a * b) % p = (a % p * b % p) % p （3）
a ^ b % p = ((a % p)^b) % p （4）
```

**结合律：**
```cpp
((a + b) % p + c) % p = (a + (b + c) % p) % p （5）
((a * b) % p * c) % p = (a * (b * c) % p) % p （6）
```

**交换律：**
```cpp
(a + b) % p = (b + a) % p （7）
(a * b) % p = (b * a) % p （8）
```
**分配律：**
```cpp
(a+b) % p = ( a % p + b % p ) % p （9）
((a +b)% p * c) % p = ((a * c) % p + (b * c) % p) % p （10）
```

## 5 重要定理

```cpp
若a≡b (% p)，则对于任意的c，都有(a + c) ≡ (b + c) (%p)；（11）
若a≡b (% p)，则对于任意的c，都有(a * c) ≡ (b * c) (%p)；（12）
若a≡b (% p)，c≡d (% p)，则 (a + c) ≡ (b + d) (%p)，(a - c) ≡ (b - d) (%p)，
(a * c) ≡ (b * d) (%p)，(a / c) ≡ (b / d) (%p)； （13）
```

## 6 应用

### 6.1 判别奇偶数

```cpp
bool IsEven(int n) {
	return(n%2==0);
}
```

### 6.2 判别素数

判断某个自然数是否是素数最常用的方法就是试除法——用比该自然数的平方根小的正整数去除这个自然数，若该自然数能被整除，则说明其非素数。

```cpp
bool IsPrime(unsigned int n) {
	unsigned maxFactor = sqrt(n);//n的最大因子
	for(unsigned int i = 2; i <= maxFactor; i++) {
		if(n % i == 0) {//n能被i整除，则说明n非素数
			return false;
		}
	}
	return true;
}
```

### 6.3 求最大公约数

求最大公约数最常见的方法是欧几里德算法（又称辗转相除法），其计算原理依赖于定理：gcd(a,b) = gcd(b,a mod b)

**递归**

```cpp
unsigned int gcd(unsigned int a,unsigned int b) {
	if(b == 0) return a;
	return gcd(b,a % b);
}
```

**迭代**

```cpp
unsigned int gcd(unsigned int a,unsigned int b) {
	unsigned int temp;
	while(b != 0) {
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}
```

### 6.4 模幂运算

例如，我们想知道3333^5555的末位是什么。

根据运算规则（4）a^b % p = ((a % p)^b) % p ，我们知道3333^5555（%10）= 3^5555（%10）。

根据运算规则（3） (a * b) % p = (a % p * b % p) % p，3^5555（%10）相当于把5555个3 % 10的结果相乘。或者在处理的过程中，不断对中间相乘得到的结果对10取模，然后作为处理结果，继续往下处理。

利用这些规则我们可以有效地计算X^N(% P)。简单的算法是将result初始化为1，然后重复将result乘以X，每次乘法之后应用%运算符（这样使得result的值变小，以免溢出），执行N次相乘后，result就是我们要找的答案。

这样对于较小的N值来说，实现是合理的，但是当N的值很大时，需要计算很长时间，是不切实际的。下面的结论可以得到一种更好的算法。

```cpp
如果N是偶数，那么X^N =（X*X）^[N/2]；
如果N是奇数，那么X^N = X*X^(N-1) = X *（X*X）^[N/2]；
其中[N]是指小于或等于N的最大整数。
```

```cpp
unsigned int PowerMod(unsigned int x, unsigned int n, unsigned int p) {
	if (n == 0) {
		return 1;
	}
	unsigned int temp = PowerMod((x * x) % p, n / 2, p);//递归计算（X*X）^[N/2]
	if((n & 1) != 0) { //判断n的奇偶性
		temp = (temp * x) % p;
	}
	return temp;
}
```

### 6.5 《孙子问题(中国剩余定理)》

```cpp
unsigned int ResidueTheorem(const unsigned int devisor[], const unsigned int remainder[], int length) {
	unsigned int product = 1;	//所有除数之乘积
    for(int i = 0; i < length; i++) { //计算所有除数之乘积
    	product *= devisor[i]; //公倍数数组，表示除该元素（除数）之外其他除数的公倍数
    }
	unsigned int *  commonMultiple = new unsigned int (length);
    for (int i = 0; i < length; i++) {//计算除该元素（除数）之外其他除数的公倍数
    	commonMultiple[i] = product / devisor[i];
    }
    unsigned int dividend = 0;//被除数，就是函数要返回的值
    for(int i = 0; i < length; i++) {//计算被除数，但此时得到的不是最小被除数
    	unsigned int tempMul = commonMultiple[i];//按照剩余理论计算合适的公倍数，使得tempMul%devisor[i]==1
        while(tempMul % devisor[i] != 1) {
            tempMul += commonMultiple[i];
        }
        dividend += tempMul * remainder[i];//用本除数得到的余数乘以其他除数的公倍数
    }
    delete[] commonMultiple;
    return(dividend % product); //返回最小被除数
}
```

### 6.6 凯撒密码

凯撒密码（caeser）是罗马扩张时期朱利斯·凯撒（Julius Caesar）创造的，用于加密通过信使传递的作战命令。

它将字母表中的字母移动一定位置而实现加密。注意26个字母循环使用，z的后面是a。

例如，当密匙为k = 3，即向后移动3位时，若明文为”How are you!”，则密文为”Krz duh btx!”。

## 7 SOJ相关题目

1. [1020](http://222.200.185.45/1020)

