#include <iostream>
using namespace std;

//枚举类型，图的种类 DG：有向图；WDG：带权值的有向图；
//UDG: 无向图；WUDG: 带权值的无向图
enum GraphKind {DG, WDG, UDG, WUDG};

//vertexType顶点类型，VRType：顶点之间的关系类型，InfoType：弧的信息类型
template <typename VertexType, typename VRType, typename InfoType>
class MGraph {
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
