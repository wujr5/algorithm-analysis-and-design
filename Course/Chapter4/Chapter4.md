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
### 2.2 3n+1数链问题
### 2.3 负权数
### 2.4 质多项式
### 2.5 猴子舞
### 2.6 数制转换
### 2.7 大众批萨

## 3 Sicily作业
