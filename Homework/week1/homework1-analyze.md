# 第一章作业及分析

## 1 [1020 Big Integer](http://222.200.185.45/show_problem.php?pid=1020)

### 1.1 考点分析

考察的内容是取模运算的基本定理：

```cpp
(a + b) % p = (a % p + b % p) % p
(a * b) % p = ((a % p) * (b % p)) % p
```

因此，一个大数，就可以看成是，从高位数开始，不断执行乘以10然后加上下一个低位数，直到最后一位数。比如：

```cpp
1234 = (1 * 10 + 2) * 10 + 3) * 10 + 4
```

以此类推，便得到如下算法：

```cpp
1. 初始化结果result为0
2. 从最高位数字开始，result = (result * 10 + nextNumBit) % molduloNum
3. 执行result = (result * 10 + nextNumBit) % molduloNum直到nextNumBit是最后一位数字
```

### 1.2 伪代码

```cpp
function BIG-NUMBER-MOLDULO(str, mod) returns a moldulo
	inputs: str, the string of the big bumber
    		mod, the moldulo number
    
    result <-- 0
    for i = 0 to str.size() do
    	result <-- (result * 10 + str[i]) % mod
    
    return result
```

### 1.3 源程序

```cpp
#include<iostream>
#include<string>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		int num[1000];
		cin >> n;
		cout << "(";
		for (int j = 0; j < n; j++) {
			cin >> num[j];
		}
		string k;
		cin >> k;
		for (int j = 0; j < n; j++) {
			int result = 0;
			for (int r = 0; r < k.size(); r++) {
				int tem = k[r] - '0';
				result = result * 10 + tem;
				result %= num[j];
			}
			if (j != n - 1) cout << result << ",";
			else cout << result << ")" << endl;
		}
	}
}

```

### 1.4 时间复杂度分析



### 1.5 空间复杂度分析
