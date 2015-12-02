# 第一章作业及分析

## 1 [1020 Big Integer](http://222.200.185.45/show_problem.php?pid=1020)

### 1.1 考点分析

### 1.2 伪代码

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

