# 中缀表达式转后缀表达式并求值

## 1 中缀转后缀

```cpp
1.遇到操作数：直接输出（添加到后缀表达式中）
2.栈为空时，遇到运算符，直接入栈
3.遇到左括号：将其入栈
4.遇到右括号：执行出栈操作，并将出栈的元素输出，直到弹出栈的是左括号，左括号不输出。
5.遇到其他运算符：加减乘除：弹出所有优先级大于或者等于该运算符的栈顶元素，然后将该运算符入栈
6.最终将栈中的元素依次出栈，输出。
```

## 2 后缀求值

```cpp
将中缀表达式转换成等价的后缀表达式后，求值时，不需要再考虑运算符的优先级，只需从左到右扫描一遍后缀表达式即可。具体求值步骤为：从左到右扫描后缀表达式，遇到运算符就把表达式中该运算符前面两个操作数取出并运算，然后把结果带回后缀表达式；继续扫描直到后缀表达式最后一个表达式。

设置一个栈，开始时，栈为空，然后从左到右扫描后缀表达式，若遇操作数，则进栈；若遇运算符，则从栈中退出两个元素，先退出的放到运算符的右边，后退出的 放到运算符左边，运算后的结果再进栈，直到后缀表达式扫描完毕。此时，栈中仅有一个元素，即为运算的结果。
```

## 3 程序实现

```cpp
#include<iostream>
#include<strstream>
#include<stack>
#include<string>
#include<cstring>
using namespace std;

class InfixToPostfix {
private:
	char infix[2000];
	char space_infix[4000];
	double outcome;
	string postfix;
public:
	InfixToPostfix();
	InfixToPostfix(char*);
	void setSpaceInfix();
	void setPostfix();
	void calculate();
	double getOutcome();
	string getPostfix();
	char* getSpaceInfix();
	
	void update(char*);
};

InfixToPostfix::InfixToPostfix() {
	memset(infix, '\0', sizeof(infix));
	memset(space_infix, '\0', sizeof(space_infix));
	outcome = 0;
	postfix = "";
}

InfixToPostfix::InfixToPostfix(char* inf) {
	memset(infix, '\0', sizeof(infix));
	memset(space_infix, '\0', sizeof(space_infix));
	outcome = 0;
	postfix = "";
	
	strncpy(infix, inf, strlen(inf));
	
	setSpaceInfix();
	setPostfix();
	calculate();
}

void InfixToPostfix::setSpaceInfix() {
	int len = strlen(infix);
	char op[] = "+-*/()";

	for (int i = 0; i < len; i++) {
		if (infix[i] == ' ') continue;

		char* pt = strchr(op, infix[i]);
		if (pt != NULL) {
			space_infix[strlen(space_infix)] = ' ';
			space_infix[strlen(space_infix)] = pt[0];
			space_infix[strlen(space_infix)] = ' ';
		} else {
			space_infix[strlen(space_infix)] = infix[i];
		}
	}
}

void InfixToPostfix::setPostfix() {
	istrstream strin(space_infix);
	postfix = "";
	string temp;
	char op[] = "+-*/()";

	stack<string> opstack;

	while(strin >> temp) {
		if (strchr(op, temp[0]) == NULL) {
			postfix += temp;
			postfix += ' ';
		} else {
			if (opstack.empty() || temp[0] == '(') {
				opstack.push(temp);
			}
			else if (temp[0] == ')') {
				while (!opstack.empty() && opstack.top()[0] != '(') {
					postfix += opstack.top();
					postfix += ' ';
					opstack.pop();
				}
				if (!opstack.empty() && opstack.top()[0] == '(') opstack.pop();
			}
			else if (strchr("+-", temp[0]) != NULL) {
				while (!opstack.empty() && opstack.top()[0] != '(') {
					postfix += opstack.top();
					postfix += ' ';
					opstack.pop();
				}
				opstack.push(temp);
			}
			else if (strchr("*/", temp[0]) != NULL) {
				while (!opstack.empty() && strchr("*/", opstack.top()[0]) && opstack.top()[0] != '(') {
					postfix += opstack.top();
					postfix += ' ';
					opstack.pop();
				}
				opstack.push(temp);
			}
		}
	}

	while (!opstack.empty()) {
		postfix += opstack.top();
		postfix += ' ';
		opstack.pop();
	}
}

void InfixToPostfix::calculate() {
	istrstream strin(postfix.c_str());
	string temp = "";
	stack<double> result;
	char op[] = "+-*/";
	
	while (strin >> temp) {
		if (strchr(op, temp[0])) {
			double opb = result.top();
			result.pop();
			double opa = result.top();
			result.pop();
			
			switch (temp[0]) {
				case '+':
					result.push(opa + opb);
					break;
				case '-':
					result.push(opa - opb);
					break;
				case '*':
					result.push(opa * opb);
					break;
				case '/':
					result.push(opa / opb);
					break;
			}
			
		} else {
			istrstream strin2(temp.c_str());
			double db1 = 0;
			strin2 >> db1;
			result.push(db1);
		}
	}
	
	outcome = result.top();
}

double InfixToPostfix::getOutcome() {
	return outcome;
}

string InfixToPostfix::getPostfix() {
	return postfix;
}

char* InfixToPostfix::getSpaceInfix() {
	return space_infix;
}

void InfixToPostfix::update(char* inf) {
	memset(infix, '\0', sizeof(infix));
	memset(space_infix, '\0', sizeof(space_infix));
	postfix = "";
	outcome = 0;
	
	strncpy(infix, inf, strlen(inf));
	setSpaceInfix();
	setPostfix();
	calculate();
}


int main() {
	char infix[1000];
	InfixToPostfix in2po = InfixToPostfix();
	
	while (cin.getline(infix, 1000)) {
		cout << "The infix to be processed is :" << infix << endl;
		
		in2po.update(infix);
		
		cout << "Space infix: " << in2po.getSpaceInfix() << endl;
		cout << "Postfix: " << in2po.getPostfix() << endl;
		cout << "result: " << in2po.getOutcome() << endl;
		cout << endl;
	}
	
	return 0;
}

```