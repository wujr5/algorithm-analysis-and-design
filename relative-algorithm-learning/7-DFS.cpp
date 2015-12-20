#include <iostream>
using namespace std;

class Graph {
public:
	char* vertexArray;
	int** arcArray;
	int vertexCount;
	int arcCount;
	
	Graph(int n) {
		vertexCount = n;
		arcCount = 0;
		vertexArray = new int[vertexCount];
		arcArray = new int*[vertexCount];
		for (int i = 0; i < vertexCount; i++) {
			arcArray[i] = new int [vertexCount];
		}
		
		cout << "Input the " << n << " vertexes' name: " << endl;
		for (int i = 0; i < vertexCount; i++) {
			cin >> vertexArray[i];
		}
		
		cout << "Input the head and tail and weight of each arc: " << endl;
		int vHead, vTail, weight;
		while (cin >> vHead >> vTail >> weight) {
			arcArray[vHead][vTail] = weight;
		}
	}
};

void DFS(Graph g, int source) {
	
}

int main() {
	Graph g(5);
	
}
