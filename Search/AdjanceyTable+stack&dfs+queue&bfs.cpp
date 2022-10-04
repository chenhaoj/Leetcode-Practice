#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

// 邻接表-边表
struct AdjanceyList
{
    int adjanceyNode;
    AdjanceyList *nextarc;
};

// 邻接表-顶点表
struct headerList
{
    int headerNode;
    AdjanceyList *firstarc;
};

class graphAdjanceyList
{
public:
    graphAdjanceyList(int nodeNum) {
        this->nodeNum = nodeNum;
        this->hvexArray = new headerList[nodeNum]();
        if(hvexArray == NULL) {
            cout << "out of space" << endl;
            exit(1);
        }
        // 链表初始化
        for(int i=0;i<nodeNum;++i) {
            hvexArray[i].headerNode = -1;
            hvexArray[i].firstarc = NULL;
        }
    }

    ~graphAdjanceyList() {
        if(hvexArray != NULL) {
            delete[] hvexArray;
        }
        if(!adjvector.empty()) {
            for(vector<AdjanceyList*>::iterator it=adjvector.begin();it!=adjvector.end();it++) {
                delete (*it);
            }
        }
    }

    void addEdge(int tail, int head) {
        AdjanceyList *adjvex = new AdjanceyList();
        adjvex->nextarc = NULL;
        adjvex->adjanceyNode = head; // 邻接顶点信息
        if((hvexArray+tail)->headerNode == -1) {// 头列表
            (hvexArray+tail)->headerNode = tail;
            (hvexArray+tail)->firstarc = adjvex;
        }
        else {// 邻接表
            AdjanceyList *tempAdjList = (hvexArray+tail)->firstarc;
            while(tempAdjList->nextarc != NULL) {
                tempAdjList = tempAdjList->nextarc;
            }
            tempAdjList->nextarc = adjvex;
        }
        adjvector.push_back(adjvex);
    }

    headerList *getList() {
        return hvexArray;
    }

    void printGraph() {
        for(int i = 0; i < nodeNum; i++) {
            AdjanceyList *it = hvexArray[i].firstarc;
            cout << hvexArray[i].headerNode << ":";
            while(it != NULL) {
                cout << "-->" << it->adjanceyNode;
                it = it->nextarc;
            }
            cout << endl;
        }
    }
private:
    vector<AdjanceyList*> adjvector;// 用vector来管理邻接顶点的内存
    headerList *hvexArray;
    int nodeNum;
};

void dfs(graphAdjanceyList &graph, int start, int nodeNum) {
    stack<int> s;
    vector<bool> visited(nodeNum, false); // 记录顶点是否被访问过
    s.push(start);
    cout << start;
    visited[start] = true;
    while(!s.empty()) {
        int currentNode = s.top();
        AdjanceyList *temp = graph.getList()[currentNode].firstarc;
        while(temp!=NULL) {
            if(visited[temp->adjanceyNode]!=false) {
                temp = temp->nextarc;
            }
            else {
                cout << "-->" << temp->adjanceyNode;
                visited[temp->adjanceyNode] = true;
                s.push(temp->adjanceyNode);
                break;
            }
        }
        if(temp==NULL) {
            s.pop();
        }
    }
    cout << endl;
}

void bfs(graphAdjanceyList &graph, int start, int nodeNum) {
    queue<int> q;
    vector<bool> visited(nodeNum, false);
    q.push(start);
    cout << start;
    visited[start] = true;
    while(!q.empty()) {
        int currentNode = q.front();
        AdjanceyList *temp = graph.getList()[currentNode].firstarc;
        while(temp!=NULL) {
            if(visited[temp->adjanceyNode]==false) {
                cout << "-->" << temp->adjanceyNode;
                visited[temp->adjanceyNode] = true;
                q.push(temp->adjanceyNode);
            }
            temp = temp->nextarc;
        }
        q.pop();
    }
    cout << endl;
}

int main() {
    // ./mapTree.png
    graphAdjanceyList graph_adjlist(8);
    graph_adjlist.addEdge(0,1);
    graph_adjlist.addEdge(0,2);
    graph_adjlist.addEdge(1,0);
    graph_adjlist.addEdge(1,3);
    graph_adjlist.addEdge(1,4);
    graph_adjlist.addEdge(2,0);
    graph_adjlist.addEdge(2,5);
    graph_adjlist.addEdge(2,6);
    graph_adjlist.addEdge(3,1);
    graph_adjlist.addEdge(3,7);
    graph_adjlist.addEdge(4,1);
    graph_adjlist.addEdge(4,7);
    graph_adjlist.addEdge(5,2);
    graph_adjlist.addEdge(5,6);
    graph_adjlist.addEdge(6,2);
    graph_adjlist.addEdge(6,5);
    graph_adjlist.addEdge(7,3);
    graph_adjlist.addEdge(7,4);
    // graph_adjlist.printGraph();
    cout << "dfs:";
    dfs(graph_adjlist, 0, 8);
    cout << "bfs:";
    bfs(graph_adjlist, 0, 8);
    return 0;
}