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

void BFS(Graph g, int source) {
	const int MAX_NUM = 1000000;
	const int NOT_A_NUMBER = -1000000;
	enum Color {WHITE, GRAY, BLACK};
	int* distance = new int[g.vertexCount];
	int* father = new int[g.vertexCount];
	int* color = new int[g.vertexCount];

	for (int i = 0; i < g.vertexCount; i++) {
		distance[i] = MAX_NUM;
		father[i] = NOT_A_NUMBER;
		color[i] = WHITE;
	}

	queue<int> BFSqueue;

	distance[source] = 0;
	father[source] = NOT_A_NUMBER;
	color[source] = GRAY;

	BFSqueue.push(source);

	while (!BFSqueue.empty()) {
		int u = BFSqueue.front();
		BFSqueue.pop();

		for (int i = 0; i < g.vertexCount; i++) {
			if (g.arcArray[u][i] != 0 && color[i] == WHITE) {
				color[i] = GRAY;
				distance[i] = distance[u] + 1;
				father[i] = u;
				BFSqueue.push(i);
			}
		}
		color[u] = BLACK;
	}

	cout << "distance:" << endl;
	for (int i = 0; i < g.vertexCount; i++) {
		cout << "distance[" << i << "] = " << distance[i] << endl;
	}

	cout << "father:" << endl;
	for (int i = 0; i < g.vertexCount; i++) {
		cout << "father[" << i << "] = " << father[i] << endl;
	}
}

int main() {
	Graph g(5);
	g.display();

	BFS(g, 0);
	BFS(g, 1);
	BFS(g, 2);
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
2 1 3 NULL
*/
