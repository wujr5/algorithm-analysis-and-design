// 有向带权图的简单的邻接矩阵表示

#include <iostream>
using namespace std;

struct Arc { // 弧节点，记录边信息
	bool isAdjacent; // 记录顶点之间是否相邻
	int weight; // 记录弧所代表的权值
};

class Graph {
	private:
		char* vertexArray; //顶点向量
		Arc** arcArray; //邻接矩阵
		int vertexCount; //图的当前节点个数
		int arcCount; //图的弧数

	public:
		Graph(int n):vertexCount(n) {
			vertexArray = new char[vertexCount];
			arcArray = new Arc*[vertexCount];
			for (int i = 0; i < vertexCount; i++) {
				arcArray[i] = new Arc[vertexCount];
			}
			init();
			create();
		}

		void init() {
			cout << "Please input every vertex's name: " << endl;
			for (int i = 0; i < vertexCount; i++) {
				cin >> vertexArray[i];
			}
			for (int i = 0; i < vertexCount; i++) {
				Arc arc;
				arc.isAdjacent = false;
				arc.weight = 0;
				for (int j = 0; j < vertexCount; j++) {
					arcArray[i][j] = arc;
				}
			}
		}

		void create() {
			cout << "Please input every arc's head vertex and tail vertex and its weight" << endl;
			int vertexHead, vertexTail, arcWeight;
			while (cin >> vertexHead >> vertexTail >> arcWeight) {
				arcCount++;
				arcArray[vertexHead][vertexTail].isAdjacent = true;
				arcArray[vertexHead][vertexTail].weight = arcWeight;
			}
		}

		void display() {
			cout << "There are " << vertexCount << " vertexes, "<< arcCount << " arcs" << endl;
			for (int i = 0; i < vertexCount; i++) {
				cout << "The " << i+1 << "th vertex is:" << vertexArray[i] << ", the adjacent vertex are: ";
				for (int j = 0; j < vertexCount; j++) {
					if (arcArray[i][j].isAdjacent) {
						cout << vertexArray[j] << "(" << arcArray[i][j].weight << ") ";
					}
				}
				cout << endl;
			}
		}
};

int main() {
	Graph g = Graph(5);
	g.display();
	return 0;
}
