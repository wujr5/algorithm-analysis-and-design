# 图的表示

## 1 邻接矩阵表示法

**完整实现**
```cpp
#include <iostream>
using namespace std;

//枚举类型，图的种类 DG：有向图；WDG：带权值的有向图；
//UDG: 无向图；WUDG: 带权值的无向图
enum GraphKind {DG, WDG, UDG, WUDG};

//vertexType顶点类型，VRType：顶点之间的关系类型，InfoType：弧的信息类型
template <typename VertexType, typename VRType, typename InfoType>
class MGraph {
private:
  struct ArcCell {
		VRType adj;   //顶点关系类型。对于无权图，用1或0表示;表示相邻与否；对带权图，为权值类型
		InfoType info;  //该弧相关的信息的变量
	};
	VertexType *vvec;          	//顶点向量
	ArcCell **arcs;    			//邻接矩阵
	int vexnum;                 //图的当前顶点个数
	int arcnum;                 //图的弧数
	GraphKind kind;             //图的种类标志

public:
	MGraph(int vexNum, GraphKind __kind) : vexnum(vexNum), arcnum(0), kind(__kind) {
		vvec = new VertexType[vexnum]; //分配顶点向量数组
		arcs = new ArcCell *[vexnum]; //动态分配二维数组， 注意二维数组的动态分配
		for (int i = 0; i < vexnum; i++) {
			arcs[i] = new ArcCell[vexnum]; //为每一行动态分配空间
		}
	}

	void Create() {
		switch (kind) {
			case DG:
				CreateDG();    //构造一个有向图
				break;
			case WDG:
				CreateWDG();    //构造一个带权有向图
				break;
			case UDG:
				CreateUDG();    //构造一个无向图
				break;
			case WUDG:
				CreateWUDG();   //构造一个带权无向图
				break;
			default:
				return;
		}
	}

	//初始化顶点数组和邻接矩阵
	void Init() {
		cout << "请输入每个顶点的关键字：" << endl;
		VertexType val;
		for (int i = 0; i < vexnum; i++) {
			cin >> val;
			vvec[i] = val;
		}
		for (int i = 0; i < vexnum; i++) {
			ArcCell ac;
			ac.adj = 0;
			ac.info = NULL;
			for (int j = 0; j < vexnum; j++) {
        arcs[i][j] = ac;
			}
		}
	}

	//构造一个有向图
	void CreateDG() {
		Init();
		int vhead, vtail;
		cout << "请依次输入每条边的开始顶点和结束顶点：" << endl;
		while (cin >> vhead >> vtail) {
			arcnum++;
			arcs[vhead][vtail].adj = 1;
		}
	}

	//构造一个带权有向图
	void CreateWDG() {
		Init();
		int vhead, vtail;
		InfoType w;
		cout << "请依次输入每条边的开始顶点和结束顶点和权值：" << endl;
		while (cin >> vhead >> vtail >> w) {
			arcnum++;
			arcs[vhead][vtail].adj = w;
		}
	}

	//构造一个无向图
	void CreateUDG() {
		Init();
		int vhead, vtail;
		cout << "请依次输入每条边的开始顶点和结束顶点：" << endl;
		while (cin >> vhead >> vtail) {
			arcnum += 2;
			arcs[vhead][vtail].adj  = 1;
			arcs[vtail][vhead].adj  = 1;
		}
	}

	//构造一个带权无向图
	void CreateWUDG() {
		Init();
		int vhead, vtail;
		InfoType w;
		cout << "请依次输入每条边的开始顶点和结束顶点和权值：" << endl;
		while (cin >> vhead >> vtail >> w) {
			arcnum += 2;
			arcs[vhead][vtail].adj = w;
			arcs[vtail][vhead].adj = w;
		}
	}

	void displayGraph() {
		cout << "总共有" << vexnum << "个顶点，"
			 << arcnum << "条边" << endl;
		for (int i = 0; i < vexnum; i++) {
			cout << "第" << i+1 << "个顶点是：" << vvec[i]
			     << "相邻的边有: ";
		    for (int j = 0; j < vexnum; j++) {
				if (arcs[i][j].adj != 0)
					cout << vvec[j] << "(" << arcs[i][j].adj << ") ";
		    }
			cout << endl;
		}
	}
};

int main() {
	cout << "构造无向图：" << endl;
	MGraph<char, int, int> udgGraph(8, UDG);
	udgGraph.Create();
	udgGraph.displayGraph();

	cout << "构造带权无向图：" << endl;
	MGraph<char, int, int> wudgGraph(9, WUDG);
	wudgGraph.Create();
	wudgGraph.displayGraph();

	cout << "构造有向图：" << endl;
	MGraph<char, int, int> dgGraph(6, DG);
	udgGraph.Create();
	udgGraph.displayGraph();

	cout << "构造带权有向图：" << endl;
	MGraph<char, int, int> wdgGraph(6, WDG);
	wdgGraph.Create();
	wdgGraph.displayGraph();

	system("pause");
	return 0;
}
```

**简单实现**

```cpp
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
```

邻接矩阵的图的表示方法简单直观，但对稀疏矩阵来说，可能会浪费较多的空间。也不利于遍历。

## 2 邻接表表示法

**完整实现**

```cpp
#include <iostream>
using namespace std;

//枚举类型，图的种类 DG：有向图；WDG：带权值的有向图；
//UDG: 无向图；WUDG: 带权值的无向图
enum GraphKind {DG, WDG, UDG, WUDG};

template<typename VertexType, typename InfoType>
class ALGraph {
public:
	ALGraph(int verNum, GraphKind _kind):vexnum(verNum), arcnum(0), kind(_kind) {
		for (int i = 0; i < MAX_VERTEX_NUM; i++)
			vertices[i].firstarc = NULL;
	}

	//构造图，进行选择
	void Create() {
		switch (kind) {
			case DG:
				CreateDG();    //构造一个有向图
				break;
			case WDG:
				CreateWDG();    //构造一个带权有向图
				break;
			case UDG:
				CreateUDG();    //构造一个无向图
				break;
			case WUDG:
				CreateWUDG();   //构造一个带权无向图
				break;
			default:
				return;
		}
	}

	//打印邻接链表
	void displayGraph() {
		for (int i = 0; i < vexnum; i++) {
			cout << "第" << i+1 << "个顶点是：" << vertices[i].data << " 邻接表为: ";
			ArcNode *arcNode = vertices[i].firstarc;

			while (arcNode != NULL) {
				cout << " -> " << vertices[arcNode->adjvex].data << "(" << arcNode->info << ")";
				arcNode = arcNode->nextarc;
			}

			cout << endl;
		}
	}

private:
	//const数据成员必须在构造函数里初始化
	static const int MAX_VERTEX_NUM = 20;  //最大顶点个数
	struct ArcNode {         //表结点
		int adjvex;        //该弧所指向的顶点的位置
		ArcNode *nextarc;  //指向下一条弧的指针
		InfoType info;     //该弧相关信息的指针
	};

	struct VNode {          //头结点
		VertexType data;    //顶点信息
		ArcNode *firstarc;  //指向第一条依附于该顶点的弧的指针
	};

	/*VNode AdjList[MAX_VERTEX_NUM];*/
	/* AdjList[MAX_VERTEX_NUM] vertices;*/

	VNode vertices[MAX_VERTEX_NUM];
	int vexnum;             //图的当前顶点数
	int arcnum;             //图的弧数
	GraphKind kind;         //图的种类

	//初始化邻接链表的表头数组
	void InitVertics() {
		cout << "请输入每个顶点的关键字：" << endl;
		VertexType val;
		for (int i = 0; i < vexnum; i++) {
			cin >> val;
			vertices[i].data = val;
		}
	}

	//插入一个表结点
	void insertArc(int vHead, int vTail, InfoType w) {
		//构造一个表结点
		ArcNode *newArcNode = new ArcNode;
		newArcNode->adjvex = vTail;
		newArcNode->nextarc = NULL;
		newArcNode->info = w;

		//arcNode 是vertics[vHead]的邻接表
		ArcNode *arcNode = vertices[vHead].firstarc;
		if (arcNode == NULL) vertices[vHead].firstarc = newArcNode;
		else {
			while (arcNode->nextarc != NULL) {
				arcNode = arcNode->nextarc;
			}
			arcNode->nextarc = newArcNode;
		}
		arcnum++;
	}

	//构造一个有向图
	void CreateDG() {
		InitVertics();
		int vhead, vtail;
		cout << "请依次输入每条边的开始顶点和结束顶点：" << endl;
		while (cin >> vhead >> vtail) {
			insertArc(vhead, vtail, 0);
		}
	}

	//构造一个带权有向图
	void CreateWDG() {
		InitVertics();
		int vhead, vtail;
		InfoType w;
		cout << "请依次输入每条边的开始顶点和结束顶点和权值：" << endl;
		while (cin >> vhead >> vtail >> w) {
			insertArc(vhead, vtail, w);
		}
	}

	//构造一个无向图
	void CreateUDG() {
		InitVertics();
		int vhead, vtail;
		cout << "请依次输入每条边的开始顶点和结束顶点：" << endl;
		while (cin >> vhead >> vtail) {
			insertArc(vhead, vtail, 0);
			insertArc(vtail, vhead, 0);
		}
	}

	//构造一个带权无向图
	void CreateWUDG() {
		InitVertics();
		int vhead, vtail;
		InfoType w;
		cout << "请依次输入每条边的开始顶点和结束顶点和权值：" << endl;
		while (cin >> vhead >> vtail >> w) {
			insertArc(vhead, vtail, w);
			insertArc(vtail, vhead, w);
		}
	}
};

int main() {
	cout << "构造一个8个顶点的无向图:" << endl;
	ALGraph<char, int> udgGraph(8, UDG);
	udgGraph.Create();
	udgGraph.displayGraph();

	cout << "构造一个9个顶点的带权无向图:" << endl;
	ALGraph<char, int> wudgGraph(9, WUDG);
	wudgGraph.Create();
	wudgGraph.displayGraph();

	cout << "构造一个6个顶点的有向图:" << endl;
	ALGraph<char, int> dgGraph(6, DG);
	dgGraph.Create();
	dgGraph.displayGraph();

	cout << "构造一个9个顶点的带权有向图:" << endl;
	ALGraph<char, int> wdgGraph(9, WDG);
	wdgGraph.Create();
	wdgGraph.displayGraph();

	system("pause");
	return 0;
}
```

**简单实现**

```cpp
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
```