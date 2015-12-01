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

