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
