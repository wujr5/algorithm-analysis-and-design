# 图十大基础算法

## 1 BFS 广度优先搜索

伪代码：

```cpp
BFS(G, s)
	for each vertex u ∈ V[G]-{s}
		do color[u] ← WHITE
			d[u] ← ∞
			π[u] ← NIL

  //除了源顶点s之外，第1-4行置每个顶点为白色，置每个顶点u的d[u]为无穷大，
  //置每个顶点的父母为NIL。
	color[s] ← GRAY

  //第5行，将源顶点s置为灰色，这是因为在过程开始时，源顶点已被发现。
	d[s] ← 0       //将d[s]初始化为0。
	π[s] ← NIL     //将源顶点的父顶点置为NIL。

	Q ← Ø
	ENQUEUE(Q, s)  //入队

  //第8、9行，初始化队列Q，使其仅含源顶点s。
	while Q ≠ Ø
		do u ← DEQUEUE(Q)    					//出队
			for each v ∈ Adj[u]        //for循环考察u的邻接表中的每个顶点v
				do if color[v] = WHITE then
					color[v] ← GRAY  		//置为灰色
					d[v] ← d[u] + 1     //距离被置为d[u]+1
					π[v] ← u            //u记为该顶点的父母
					ENQUEUE(Q, v)       //插入队列中

			color[u] ← BLACK      	//u 置为黑色
```

C++实现：

```cpp
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
```

