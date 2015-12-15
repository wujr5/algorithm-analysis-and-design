#include <iostream>
using namespace std;

struct ArcNode {
	int adjacentVertex;
	ArcNode* nextArc;
	int weight;
};

struct VertexNode {
	char name;
	ArcNode* firstArc;
};

class Graph {
	private:
		static const int MAX_VERTEX_NUM  = 20;
		VertexNode vertexArray[MAX_VERTEX_NUM];
		int vertexCount;
		int arcCount;

	public:
		Graph(int n):vertexCount(n), arcCount(0) {
			for (int i = 0; i < MAX_VERTEX_NUM; i++) {
				vertexArray[i].firstArc = NULL;
			}
			initVertexArray();
			create();
			display();
		}

		void initVertexArray() {
			cout << "Please enter the name of every vertex: " << endl;
			for (int i = 0; i < vertexCount; i++) {
				cin >> vertexArray[i].name;
			}
		}

		void insertArc(int vertexHead, int vertexTail, int weight) {
			ArcNode* newArcNode = new ArcNode;
			newArcNode->adjacentVertex = vertexTail;
			newArcNode->nextArc = NULL;
			newArcNode->weight = weight;

			ArcNode *arcNode = vertexArray[vertexHead].firstArc;
			if (arcNode == NULL) vertexArray[vertexHead].firstArc = newArcNode;
			else {
				while (arcNode->nextArc != NULL) {
					arcNode = arcNode->nextArc;
				}
				arcNode->nextArc = newArcNode;
			}
			arcCount++;
		}

		void create() {
			cout << "Please input the start vertex and end vertex and the weight of every arc:" << endl;
			int vertexHead, vertexTail, weight;
			while (cin >> vertexHead >> vertexTail >> weight) {
				insertArc(vertexHead, vertexTail, weight);
			}
		}

		void display() {
			for (int i = 0; i < vertexCount; i++) {
				cout << "The " << i + 1 << "th vertex is: " << vertexArray[i].name << ", its adjacent vertex are: ";

				ArcNode* arcNode = vertexArray[i].firstArc;

				while (arcNode != NULL) {
					cout << "->" << vertexArray[arcNode->adjacentVertex].name << "(" << arcNode->weight << ") ";
					arcNode = arcNode->nextArc;
				}
				cout << endl;
			}
		}
};

int main() {
	Graph g(5);
	return 0;
}
