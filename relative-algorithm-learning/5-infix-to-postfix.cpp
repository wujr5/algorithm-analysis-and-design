#include<iostream>
#include<strstream>
#include<stack>
#include<string>
using namespace std;

string infixToPostfix(char * infix) {
	string postfix = "";
	istrstream strin(infix);
	string temp = "";
	while(strin >> temp) {
		cout << temp << endl;
	}
	
	return "";
}

int main() {
	infixToPostfix("wu jia rong");
	return 0;
}
