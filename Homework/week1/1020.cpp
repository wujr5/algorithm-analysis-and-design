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

