#include <iostream>
#include <queue>
using namespace std;

class Graph {
public:
	int** arcArray;
	char* vertexArray;
	int arcCount;
	int vertexCount;

	Graph(int n):vertexCount(n) {
		arcCount = 0;
		vertexArray = new char [vertexCount];
		arcArray = new int * [vertexCount];
		for (int i = 0; i < vertexCount; i++) {
			arcArray[i] = new int [vertexCount];
		}
		
		init();
		create();
	}
	
	void init() {
		for (int i = 0; i < vertexCount; i++) {
			for (int j = 0; j < vertexCount; j++) {
				arcArray[i][j] = 0;
			}
		}
		cout << "Please input each name of the " << vertexCount << " vertex :" << endl;
		for (int i = 0; i < vertexCount; i++) {
			cin >> vertexArray[i];
		}
	}
	
	void create() {
		cout << "Please input the head vertex and tail vertex and their weight of each arc: " << endl;
		int vertexHead, vertexTail, weight;
		while (cin >> vertexHead >> vertexTail >> weight) {
			arcArray[vertexHead][vertexTail] = weight;
		}
	}
	
	void display() {
		cout << "The graph you input is : " << endl;
		for (int i = 0; i < vertexCount; i++) {
			cout << vertexArray[i] << ": ";
			for (int j = 0; j < vertexCount; j++) {
				if (arcArray[i][j] != 0) {
					cout << vertexArray[j] << "(" << arcArray[i][j] << ") ";
				}
			}
			cout << endl;
		}
	}
};



void BFS() {
	
}

int main() {
	Graph g(5);
	g.display();
	return 0;
}

// input:

/*
a b c d e

1 2 3
1 3 2
1 4 2
0 1 4
2 4 1
4 3 2
3 4 1
2 1 3
*/
