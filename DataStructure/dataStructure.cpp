#include<stdlib.h>
#include<stdio.h>
#include<time.h>

#define MAXSIZE 20
typedef int ELEMTYPE;
typedef struct {
    ELEMTYPE data[MAXSIZE];
    int length;
}SqList;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;

// 获取元素操作 GetElem(L, i, *e)
Status GetElem(SqList L, int i, ELEMTYPE *e){
    if(L.length == 0 || i < 1 || i > L.length)
        return ERROR;
    *e = L.data[i - 1];
    return OK;
}

/* 插入操作 ListInsert(*L, i, e)
   插入算法的思路:
        如果插入位置不合理，抛出异常;
        如果线性表长度大于等于数组长度，则抛出异常或动态增加容量;
        从最后一个元素开始向前遍历到第i个位置，分别将它们都向后移动一个位置;
        将要插入元素填入位置i处;
        表长加1。
*/
Status ListInsert(SqList *L, int i, ELEMTYPE e){
    int k;
    if(L->length == MAXSIZE)
        return ERROR;
    if(i < 1 || i > L->length + 1)
        return ERROR;
    if(i <= L->length){
        for(k = L->length - 1; k >= i - 1; k--)
            L->data[k + 1] = L->data[k];
    }
    L->data[i - 1] = e;
    L->length++;
    return OK;
}

/* 删除操作 ListDelete(*L, i, *e)
   删除算法的思路:
        如果删除位置不合理，抛出异常;
        取出删除元素;
        从删除元素位置开始遍历到最后一个元素位置，分别将它们都向前移动一个位置;
        表长减1。
*/
Status ListDelete(SqList *L, int i, ELEMTYPE *e){
    int k;
    if(L->length == 0)
        return ERROR;
    if(i < 1 || i > L->length)
        return ERROR;
    *e = L->data[i - 1];
    if(i < L->length){
        for(k = i; k < L->length; k++)
            L->data[k - 1] = L->data[k];
    }
    L->length--;
    return OK;
}

// 顺序表存在严重缺陷，从而提出链表结构
typedef struct Node {
    ELEMTYPE data;
    struct Node *next;
} Node;
typedef struct Node *LinkList;  /*定义LinkList*/

/* 单链表的读取 GetElem(L, i, *e)
    获取链表第i个数据的算法思路:
        声明一个指针p指向链表第一个节点，初始化j从1开始;
        当j<i时，就遍历链表，让p的指针向后移动，不断指向下一结点，j累加1;
        若到链表末尾p为空，则说明第i个节点不存在;
        否则直接成功，返回结点p的数据
*/
Status GetLinkListElem(LinkList L, int i, ELEMTYPE *e){
    int j = 1;
    LinkList p;
    p = L->next;
    while(p && j < i){
        p = p->next;
        j++;
    }
    if( !p || j > i)
        return ERROR;
    *e = p->data;
    return OK;
}

/* 单链表的插入 ListInsert(*L, i, e)
    单链表第i个数据插入节点的算法思路:
        声明一指针p指向链表头结点，初始化j从1开始;
        当j<i时，就遍历链表，让p的指针向后移动，不断指向下一节点，j累加1;
        若到链表末尾p为空，则说明第i个节点不存在;
        否则查找成功，在系统中生成一个空结点s;
        将数据元素e赋值给s->data;
        单链表的插入标准语句s->next=p->next;p->next=s;
        返回成功。
*/
Status LinkListInsert(LinkList *L, int i, ELEMTYPE e){
    int j = 1;
    LinkList p, s;
    p = *L;
    while( p && j < i){
        p = p->next;
        ++j;
    }
    if( !p || j > i)
        return ERROR;
    // 当前位于了第i-1个结点
    s = (LinkList)malloc(sizeof(Node)); // 生成新结点
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

/* 单链表的删除 ListDelete(*L, i, *e)
    单链表第i个数据删除结点的算法思路:
        声明一指针p指向链表头指针，初始化j从1开始;
        当j<i时，就遍历链表，让p的指针向后移动，不断指向下一个结点，j累加1;
        若到链表末尾p为空，则说明第i个结点不存在;
        否则查找成功，将欲删除的节点p->next赋值给q;
        单链表的删除标准语句p->next=q->next;
        将q结点中的数据赋值给e，作为返回;
        释放q结点，返回成功。
*/
Status LinkListDelete(LinkList *L, int i, ELEMTYPE *e){
    int j = 1;
    LinkList p, q;
    p = *L;
    while( p->next && j < i){
        p = p->next;
        j++;
    }
    if( !(p->next) || j > i )
        return ERROR;
    q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
    return OK;
}

/* 单链表的整表创建 CreateListHead(*L, n)
    单链表整表创建的算法思路:
        声明一指针p和计数器变量i;
        初始化一空链表L;
        让L的头结点的指针指向NULL，即建立一个带头结点的单链表;
        循环:
            生成一新结点赋值给p;
            随机生成一数字赋值给p的数据域p->data;
            将p插入到头结点与前一新结点之间。
*/
void CreateListHead(LinkList *L, int n){
    LinkList p;
    srand(time(0));
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;
    for(int i = 0; i < n; i++){
        p = (LinkList)malloc(sizeof(Node));
        p->data = rand()%100+1;
        p->next = (*L)->next;
        (*L)->next = p;
    }
}

void CreateListTail(LinkList *L, int n){
    LinkList p, r;
    srand(time(0));
    *L = (LinkList)malloc(sizeof(Node));
r = *L; // r为指向尾部的结点
    for(int i = 0; i < n; i++){
        p = (Node *)malloc(sizeof(Node));
        p->data = rand()%100+1;
        r->next = p;
        r = p;
    }
    r->next = NULL;
}

/* 单链表的整表删除 ClearList(*L)
    单链表整表删除的算法思路：
        声明一结点p和q;
        将第一个结点赋值给p;
        循环:
            将下一结点赋值给q;
            释放p;
            将q赋值给p。
*/
Status ClearList(LinkList *L){
    LinkList p, q;
    p = (*L)->next;
    while(p){
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = NULL;
    return OK;
}

/* --------静态链表-------- */
typedef struct {
    ELEMTYPE data;
    int cur;
}Component, StaticLinkList[MAXSIZE];

/* 初始化静态链表 */
Status InitList(StaticLinkList space){
    for (int i = 0; i < MAXSIZE - 1; i++)
        space[i].cur = i + 1;
    space[MAXSIZE - 1].cur = 0;
    return OK;
}

/* 手动实现静态链表版的malloc()方法 */
int Malloc_SLL(StaticLinkList space){
    int i = space[0].cur;
    if(space[0].cur)
        space[0].cur = space[i].cur;
    return i;
}

int ListLength(StaticLinkList L){
    int j = 0;
    int i = L[MAXSIZE - 1].cur;
    while(i){
        i = L[i].cur;
        j++;
    }
    return j;
}

/* 静态链表的插入操作 */
Status StaticListInsert(StaticLinkList L, int i, ELEMTYPE e){
    if(i < 1 || i > ListLength(L) + 1)
        return ERROR;
    int k = MAXSIZE - 1; // 此时是第一个有data位置的下标
    int j = Malloc_SLL(L);
    if(j){
        L[j].data = e;
        for(int l = 1; l < i; i++)
            k = L[k].cur; // 找到第i-1个位置的后继
        L[j].cur = L[k].cur;
        L[k].cur = j;
        return OK;
    }
    return ERROR;
}

/* 将下标为k的空闲结点回收到备用链表 */
void Free_SSL(StaticLinkList space, int k){
    space[k].cur = space[0].cur;
    space[0].cur = k;
}

/* 静态链表的删除操作 */
Status StaticListDelete(StaticLinkList L, int i){
    if(i < 1 || i > ListLength(L))
        return ERROR;
    int k = MAXSIZE - 1;
    for(int j = 1; j < i; j++)
        k = L[k].cur;
    int j = L[k].cur;
    L[k].cur = L[j].cur;
    Free_SSL(L, j);
    return OK;
}

/* --------循环链表-------- */
/* --------双向链表-------- */


/* 第4章 栈与队列 */
typedef int SElemType;
typedef struct 
{
    SElemType data[MAXSIZE];
    int top;
}SqStack;

/* 进栈操作 push */
Status Push(SqStack *S, SElemType e)
{
    if (S->top == MAXSIZE - 1)
        return ERROR;
    S->top++;
    S->data[S->top] = e;
    return OK;
}

/* 出栈操作 pop */
Status Pop(SqStack *S, SElemType *e)
{
    if (S->top == -1)
        return ERROR;
    *e = S->data[S->top];
    S->top--;
    return OK;
}

/* 两栈共享空间结构 */
typedef struct 
{
    SElemType data[MAXSIZE];
    int top1;
    int top2;
}SqDoubleStack;

/* 插入元素e为新的栈顶元素 */
Status SqDoubleStack_Push(SqDoubleStack *S, SElemType e, int stackNumber)
{
    if(S->top1 + 1 == S->top2)
        return ERROR;
    if (stackNumber == 1)
        S->data[++S->top1] = e;
    else if(stackNumber == 2)
        S->data[++S->top2] = e;
    return OK;
}

Status SqDoubleStack_pop(SqDoubleStack *S, SElemType *e, int stackNumber)
{
    if(stackNumber == 1)
    {
        if(S->top1 == -1)
            return ERROR;
        *e = S->data[S->top1];
        S->top1--;
    }
    else if(stackNumber == 2)
    {
        if(S->top2 == -1)
            return ERROR;
        *e = S->data[S->top2];
        S->top2++;
    }
    return OK;
}

/* 链栈结构 */
typedef struct StackNode
{
    SElemType data;
    struct StackNode *next;
}StackNode, *LinkStackPtr;
typedef struct LinkStack
{
    LinkStackPtr top;
    int count;
}LinkStack;

/* 链栈结构的入栈操作 */
Status LinkStack_Push(LinkStack *S, SElemType e)
{
    LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
    s->data = e;
    s->next = S->top;
    S->top = s;
    S->count++;
    return OK;
}

/* 链栈是否为空的判断 */
Status StackEmpty(LinkStack *S)
{
    if(S->top == NULL)
        return OK;
    else 
        return ERROR;
}

/* 链栈结构的出栈操作 */
Status LinkStack_pop(LinkStack *S, SElemType *e)
{
    LinkStackPtr p;
    if(StackEmpty(S))
        return ERROR;
    *e = S->top->data;
    p = S->top;
    S->top = S->top->next;
    free(p);
    S->count--;
    return OK;
}/* 由上无循环可见，链栈结构的入栈和出栈操作时间复杂度均为O(1) */

#include<string>
#include<iostream>
#include<vector>
using namespace std;
/* 第5章 串 */

/* 子串查找操作之————朴素模式匹配算法 */
int Index(string S, string T, int pos)
{
    int i = pos, j = i;
    while(i <= S.length() && j <= T.length())
    {
        if(S[i] == T[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 2;
            j = 1;
        }
    }
    if(j == T.length())
        return i - T.length();
    else
        return 0;
}

/* 子串查找操作之————KMP模式匹配算法 */
void get_next(string T, int *next){
    int suffix = 1;
    int prefix = 0;
    next[1] = 0;
    while(suffix < T.length())
    {
        if(prefix == 0 || T[suffix] == T[prefix])
        {
            suffix++;
            prefix++;
            next[suffix] = prefix;
        }
        else
            prefix = next[prefix];
    }
}

/* KMP模式匹配算法改进 */
void get_nextval(string T, int *nextval)
{
    int i = 1; // i:后缀末尾的位置
    int j = 0; // j:前缀末尾的位置 && 包括后缀末尾的子串的最大公共子串长度
    nextval[1] = 0;
    while (i < T.size())
    {
        if(j == 0 || T[i] == T[j])
        {
            i++;
            j++;
            if(T[i] != T[j])    // 当前字符与前缀字符不同
                nextval[i] = j; // 当前的j为nextval在i位置的值，即下一次i位置回溯就回溯到j位置的意思
            else
                nextval[i] = nextval[j]; // 当前字符与前缀字符相同，则回溯位置为前缀字符的回溯位置
        }
        else
            j = nextval[j]; // 字符不同，j值回溯，即在模式串T中，当前字符和前缀字符不同，则继续往前查找相同字符
    }
}

int index_KMP(string S, string T, int pos)
{
    int suffix = pos; // 控制S的下标
    int prefix = 0; // 控制T的下标
    int next[255];
    // next[0] = 0;
    get_nextval(T, next); // 或者get_next(T, next)
    // for(int k = 0; k < T.size(); k++){
    //     cout << next[k];
    // } // nextval[6] = { 0 0 1 0 2 2 }
    // cout << endl;
    while(suffix <= S.length() && prefix <= T.length())
    { // S[9] = { a a b a a b a a f }
      // T[6] = { a a b a a f }
        if(prefix == 0 || S[suffix] == T[prefix])
        {
            // cout << "S[" << suffix << "]:" << S[suffix] << "  T[" << prefix << "]:"<< T[prefix] << endl;
            suffix++;
            prefix++;
        }
        else
            prefix = next[prefix]; // 模式串回溯
    }
    if(prefix > T.length())
        return suffix - T.length();
    else
        return 0;
}

// 另一种KMP算法的写法，但index_KMP也要一起改动
void getNext(string T, int *next){
    int j = 0;
    next[0] = 0; // 以上是初始化过程
    for(int i = 0; i < T.size(); i++)
    { // 前后缀不相等的情况
        while(j > 0 && T[i] != T[j])
            j = next[j - 1];
        // 前后缀相等的情况
        if(T[i] == T[j])
            j++;
        // next的更新
        next[j] = j;
    }
}

int indexKPM(string S, string T, int pos)
{
    int i = pos; // 待匹配串S的指针
    int j = 0;   // 模式串T的指针
    int next[255];
    getNext(T, next);
    while (i < S.size() && j < T.size())
    {
        if(S[i] == T[j])
        {
            i++;
            j++;
        }
        else
            j = next[j - 1];
    }
    if(j >= T.size())
        return i - T.size() + 1;
    else
        return 0;
}

/* 第6章 树 */

/* 树的存储结构
    双亲表示法、孩子表示法、孩子兄弟表示法
*/

// 双亲表示法
/* #define MAX_TREE_SIZE 100
typedef int TElemType;
typedef struct PTNode{
    TElemType data;
    int parent;
}PTNode;
typedef struct {
    PTNode nodes[MAX_TREE_SIZE];
    int root, num;
}PTree; */

// 孩子表示法
/* #define MAX_TREE_SIZE 100
typedef int TElemType;
// 孩子链表
typedef struct CTNode {
    int child;
    struct CTNode *next;
} *ChildPtr;

// 表头数组的表头结点
typedef struct {
    TElemType data;
    int parent;
    ChildPtr firstchild;
} CTBox;

// 树的结构
typedef struct {
    CTBox nodes[MAX_TREE_SIZE];
    int root, num;
} CTree; */

// 孩子兄弟表示法————发现每个结点的第一个孩子存在则唯一，它的右兄弟存在则唯一
// 故设置第一个指针指向结点双亲，第二个指针指向第一个孩子firstchild，第三个指针指向右兄弟rightsib
typedef char TElemType;
typedef struct CSNode {
    TElemType data;
    struct CSNode *parent, *firstchild, *rightsib;
}CSNode, *CSTree;

// 二叉链表的结点结构
typedef struct BiTNode {
    TElemType data;
    struct BiTNode *lchild, *parent, *rchild;
}BiTNode, *BiTree;

// 访问和次序:前序遍历、中序遍历、后序遍历
// 二叉树的建立
void CreateBiTree(BiTree *T)
{
    TElemType ch;
    scanf("%c", &ch);
    if(ch == '#')
        *T = NULL;
    else
    {
        *T = (BiTree)malloc(sizeof(BiTNode));
        if(!*T)
            exit(OVERFLOW);
    }
    (*T)->data = ch;
    CreateBiTree(&(*T)->lchild);
    CreateBiTree(&(*T)->rchild);
}

/* 遍历输出二叉树 */
void pre_order(BiTree *T) 
{
    BiTree *p = T;
    if(*p != NULL)
    {
        cout << (*p)->data << " ";
        pre_order(&(*p)->lchild);
        pre_order(&(*p)->rchild);
    }
}

// 线索二叉树结构
typedef enum {Link, Thread} PointerTag; // Link==0表示指向左右孩子指针,
                                        // Thread==1表示指向前驱或后继的线索
typedef struct BiThrNode
{
    TElemType data;
    struct BiThrNode *lchild, *rchild;
    PointerTag LTag;
    PointerTag RTag;
}BiThrNode, *BiThrTree;

BiThrTree pre; // 全局变量，始终指向刚刚访问过的结点
/* 中序遍历进行中序线索化 */
void InThreading(BiThrTree p)
{
    if(p)
    {
        InThreading(p->lchild); // 递归左子树线索化
        if(!p->lchild)
        {
            p->LTag = Thread;
            p->lchild = pre;
        }
        if(!pre->rchild)
        {
            pre->LTag = Thread;
            pre->rchild = p;
        }
        pre = p;
        InThreading(p->rchild);
    }
}

/* 中序遍历线索二叉树 */
/* T指向头结点，头结点左链lchild指向根节点，头结点右链rchild指向中序遍历的尾结点 */
Status InOrderTraverse_Thr(BiThrTree T)
{
    BiThrTree p;
    p = T->lchild; // p指向根节点
    while(p != T) // 空树或遍历结束时
    {
        while(p->LTag == Link) // 当LTag==0时循环到中序序列第一个结点
            p = p -> lchild;
        printf("%c", p->data);
        while(p->RTag == Thread && p->rchild != T) // p->rchild==T表示p到了中序的尾节点
        {
            p = p->rchild;
            printf("%c", p->data);
        }
        p = p->rchild;
    }
    return OK;
}

/*  第7章 图  */

/* 图的存储结构
    邻接矩阵、邻接表、十字链表、邻接多重表、边集数组
 */

/* 邻接矩阵 ———— 顶点数组和边权数组组成*/
typedef char VertexType;
typedef int EdgeType;
#define MAXVEX 100
#define INFINITY 65535
typedef struct {
    VertexType vexs[MAXVEX];
    EdgeType arc[MAXVEX][MAXVEX];
    int numVextexes, numEdges;
}MGraph;

/* 建立无向网图的邻接矩阵表示 O(n+n^2+e)=O(n^2) 只适合稠密图*/
void CreateMGraph(MGraph *G)
{
    printf("输入顶点数和边数:\n");
    scanf("%d, %d", &G->numVextexes, &G->numEdges);

    // 读入顶点信息，建立顶点表 O(n)
    for(int i = 0; i < G->numVextexes; i++)
        scanf("%c", &G->vexs[i]);
    
    // 邻接矩阵初始化 O(n^2)
    for(int i = 0; i < G->numVextexes; i++)
    {
        for(int j = 0; j < G->numVextexes; j++)
            G->arc[i][j] = INFINITY;
    }
    
    // 读入numEdges条边，建立邻接矩阵 O(e)
    int i, j, w;
    for(int k = 0; k < G->numVextexes; k++)
    {
        printf("输入边(vi, vj)的下标i，下标j和权w:\n");
        scanf("%d, %d, %d", &i, &j, &w);
        G->arc[i][j] = w;
        G->arc[j][i] = G->arc[i][j];
    }
}

/*  邻接表 ———— 边主导，顶点下标和边特征组成  */
typedef char VertexType;
typedef int EdgeType;

typedef struct EdgeNode { // 边表节点
    int adjvex; // 邻接点域，存储该顶点对应的下标值
    EdgeType weight; // 存储权值，非网图可以注释掉
    struct EdgeNode *next; // 链域，指向下一个邻接点
}EdgeNode;

typedef struct VertexNode { // 顶点表结点
    VertexType data; // 顶点域，存储顶点信息
    EdgeNode *firstedge; // 边表头指针
}VertexNode, AdjList[MAXVEX];

typedef struct {
    AdjList AdjList;
    int numVertexes, numEdges; // 当前图中顶点数和边数
}GraphAdjList;

/*  建立图的邻接表(Adjacency List)结构  O(n+e) */
void CreateALGraph(GraphAdjList *G)
{
    printf("输入顶点数和边数:\n");
    scanf("%d, %d", &G->numVertexes, &G->numEdges);

    // 读入顶点信息，建立顶点表 O(n)
    for(int i = 0; i < G->numVertexes; i++)
    {
        scanf("%c", &G->AdjList[i].data);
        G->AdjList[i].firstedge = NULL;
    }

    // 建立边表 O(e)
    int i, j;
    EdgeNode *e;
    for(int k = 0; k < G->numEdges; k++)
    {
        printf("输入边(vi, vj)上的顶点序号:\n");
        scanf("%d, %d", &i, &j);

        // 向内存申请空间，生成边表结点，”头插法“调整边表的链接关系
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex = j; // 邻接序号为j
        e->next = G->AdjList[i].firstedge; // 将e指针指向当前顶点指向的结点
        G->AdjList[i].firstedge = e; // 将当前顶点的指针指向e

        // 无向图的反向相同操作
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex = i; // 邻接序号为i
        e->next = G->AdjList[j].firstedge;
        G->AdjList[j].firstedge = e;
    }
}

/*  十字链表(Orthogonal List) 
        ———— 解决”邻接表只能轻松获取出度，逆邻接表只能轻松获取入度“的问题 */

/* 图的最小生成树生成 */
/*  普里姆算法Prime  
        ———— 从顶点的角度出发，只关注图中边的权重，每次取权值最小的边 */
void MiniSpanTree_Prim(MGraph G)
{
    int min, i, j, k; // min：用于存最小边；i：起点；j：终点；k：下一轮起点
    int adjvex[MAXVEX]; // 相关顶点的下标————存新起点能抵达的较短路径终点
    int lowcost[MAXVEX]; // 相关顶点间边的权值
    adjvex[0] = 0; // 初始化第一个顶点坐标为v0
    lowcost[0] = 0; // 将v0顶点纳入最小生成树
    
    // 循环初始化除顶点v0外的全部顶点
    for(i = 1; i < G.numVextexes; i++)
    {
        lowcost[i] = G.arc[0][i]; // v0顶点与之有边的权值存入数组
        adjvex[i] = 0;
    }

    /* 构造最小生成树 */
    for(i = 1; i < G.numVextexes; i++)
    {
        min = INFINITY;
        j = 1; k = 0;
        
        // 从顶点vi直达图其它所有点的距离
        while(j < G.numVextexes)
        {
            if(lowcost[j] != 0 && lowcost[j] < min) // 不是已经纳入生成树的点 
                                                    // 且到顶点vj的边权值比最小值还小
            {
                min = lowcost[j];
                k = j;
            }
            j++;
        }
        printf("%d %d", adjvex[k], k);
        lowcost[k] = 0; // 纳入生成树
        for(j = 1; j < G.numVextexes; j++)
        {
            // 每纳入一个顶点，对lowcost进行一次更新
            if(lowcost[j] != 0 && G.arc[k][j] < lowcost[j])
            {
                lowcost[j] = G.arc[k][j];
                adjvex[j] = k;
            }
        }
    }
}

/* 克鲁斯卡尔Kruskal算法 
        ———— 从边的角度出发，借助边集数组存储结构，构建生成树时主要考虑环路问题 */
#define MAXEGDE 15
typedef struct {
    int begin;
    int end;
    int weight;
} Edge;
int Find(int *parent, int f);

void MiniSpanTree_Kruskal(MGraph G)
{
    int i, n, m;
    Edge edges[MAXEGDE]; // 定义边集数组edges
    int parent[MAXVEX]; // 判断是否形成环路
    /* 这里默认边集数组按权值升序排列 */
    /* 初始化环路数组parent为0 */
    for(int i = 0; i < G.numVextexes; i++)
        parent[i] = 0;
    
    /* 循环边集数组 */
    for(i = 0; i < G.numVextexes; i++)
    {
        n = Find(parent, edges[i].begin);
        m = Find(parent, edges[i].end);
        /* 判断是否形成环路 */
        if(n != m)
        {
            parent[n] = m; // 更新边的环路关系
            printf("(%d, %d)%d", edges[i].begin, edges[i].end, edges[i].weight);
        }
    }
}

/* 路径的连接关系 */
int Find(int *parent, int f)
{
    while(parent[f] > 0)
        f = parent[f];
    return f;
}

/* 图的最短路径算法 */
/* 迪杰斯特拉Dijkstra算法
        ———— 在已确认顶点的距离的基础上遍历比较以更新相邻顶点的最短路径距离 */
#define MAXVEX 9 // n个顶点
typedef int Patharc[MAXVEX];
typedef int ShortestPathTable[MAXVEX];

void shortestPath_Dijkstra(MGraph G, int v0, Patharc *P, ShortestPathTable *D)
{
    int v, w, k, min; // v:起点下标；w:终点下标；k:final数组下标；min:最短路径
    int final[MAXVEX];
    /* 初始化 */
    for(v = 0; v < G.numVextexes; v++)
    {
        final[v] = 0;
        (*D)[v] = G.arc[v0][v];
        (*P)[v] = -1;
    }
    (*D)[v0] = 0;
    final[v0] = 1;

    /* 主循环 
       时间复杂度————O(n^2)
    */
    for(v = 1; v < G.numVextexes; v++)
    {
        min = INFINITY;
        /* 寻找离v0最近的顶点
           若要求任意两顶点之间的最短路径，只需令v0为需求起点再跑一次Dijkstra即可
           时间复杂度————O(n^3) 
        */
        for(w = 0; w < G.numVextexes; w++)
        {
            if(!final[w] && (*D)[w] < min)
            {
                k = w;
                min = (*D)[w];
            }
        }

        final[k] = 1;
        /* 修正当前最短路径及距离 */
        for(k = 0; k < G.numVextexes; k++)
        {
            if(!final[k] && min + G.arc[k][w] < (*D)[w])
            {
                (*D)[w] = min + G.arc[k][w];
                (*P)[w] = k;
            }
        }
    }
}

/* 弗洛伊德Flpyd算法
        ———— 便于求所有顶点到所有其它顶点的最短路径算法 */
typedef int Pathmatrix[MAXVEX][MAXVEX];
typedef int ShortPathTable[MAXVEX][MAXVEX];

void ShortestPath_Floyd(MGraph G, Pathmatrix *P, ShortPathTable *D)
{
    int v, w, k;
    for(v = 0; v < G.numVextexes; ++v)
    {   
        // 初始化
        for(w = 0; w < G.numVextexes; ++w)
        {
            (*D)[v][w] = G.arc[v][w];
            /* 默认状态下不知道前驱是谁，就设置为自己。
            这里有点像不知道最小是谁的情况下，就先设置个最安全稳妥的值 */
            (*P)[v][w] = w;
        }
    }
    // 时间复杂度O(n^3)
    for(k = 0; k < G.numVextexes; ++k)
    {
        for(v = 0; v < G.numVextexes; ++v)
        {
            for(w = 0; w < G.numVextexes; ++w)
            {   
                /* 修正最短距离 和 目标顶点的前驱顶点矩阵 */
                if((*D)[v][w] > (*D)[v][k] + (*D)[k][w])
                {
                    (*D)[v][w] = (*D)[v][k] + (*D)[k][w];
                    (*P)[v][w] = (*P)[v][k];
                }
            }
        }
    }
}

/* 拓扑排序
    ———— 针对AOV(Activity On Vertex Network)网：顶点表示活动的有向图
    基本思路：
        从AOV网中选择一个入度为0的顶点输入，然后删去此顶点，并删除以此顶点为尾的弧，
        继续重复此步骤，知道输出全部顶点或者AOV网中不存在入度为0的顶点为止
 */
typedef struct VertexNode_topology { // 顶点表结点
    int in; // 顶点的入度
    VertexType data; // 顶点域，存储顶点信息
    EdgeNode *firstedge; // 边表头指针
}VertexNode_topology, AdjList_topology[MAXVEX];

typedef struct {
    AdjList_topology AdjList_topology;
    int numVertexes, numEdges; // 当前图中顶点数和边数
}GraphAdjList_topology;

Status TopologicalSort(GraphAdjList_topology GL)
{
    /* 时间复杂度O(n+e) */
    int gettop, k;
    int top = 0; // 栈顶指针，栈指针下标
    int count = 0; // 记录入度为0的顶点个数，以和GL.numnumVertexes比较判断是否存在环
    int *stack; // 建栈存储入度为0的顶点
    stack = (int*)malloc(GL.numVertexes * sizeof(int)); // 一次初始化足够空间的栈结构
    // 遍历所有节点，把起始节点入栈
    for(int i = 0; i < GL.numVertexes; i++)
    {
        if(GL.AdjList_topology[i].in == 0)
            stack[++top] = i; // 将入度为0的顶点入栈
    }
    while(top != 0)
    {
        EdgeNode *e;
        gettop = stack[top--]; // 栈顶元素出栈研究
        printf("%d -> ", GL.AdjList_topology[gettop].data);
        count++;
        for(e = GL.AdjList_topology[gettop].firstedge; e; e = e->next)
        {
            k = e->adjvex;
            if(!(--GL.AdjList_topology[k].in))
                stack[++top] = k;
        }
        /* 判断是否确实为合法AOV网 */
        if(count < GL.numVertexes)
            return ERROR;
        else 
            return OK;
    }
}

/* 关键路径 
    ———— 针对AOE(Activity On Edge Network)网：顶点表示事件、边权表示活动持续时间的有向图
    ———— 拓扑排序考虑的是工程先后顺序的问题，关键路径强调的是寻求工程最短时间的算法 
    即，分析拓扑关系，并且找到当中最关键的流程，该流程所需时间就是最短时间
    算法原理：
        关键是找到所有活动的”最早开始时间earliest_time“和”最晚开始时间lastest_time“，如果相等则是关键路径，否则不是
        事件的最早发生时间earliest_time_of_vertex;
        事件的最晚发生时间lastest_time_of_vertex;
        活动的最早开工时间earliest
*/
/* 设置为全局变量，是为了接下来能够在拓扑序的基础上求关键路径 */
int *etv, *ltv; //事件最早发生时间和最迟发生时间
int *stack2; //存储拓扑序列的栈
int top2; //用于stack2的指针

Status TopologicalSort_CriticalPath(GraphAdjList_topology GL)
{
    EdgeNode *e;    
    int i, k, gettop;
    int count; //是否完整排序全图的signal
    
    /* 初始化入度为0的栈 */
    int top = 0; //stack栈顶指针
    int *stack; //升序遍历，降序存储入度为0的栈
    stack = (int *)malloc(GL.numVertexes*sizeof(int));
    for(int i = 0; i < GL.numVertexes; i++)
        if(GL.AdjList_topology[i].in == 0)
            stack[++top] = i;
    
    /* 初始化最早发生时间为0 */
    etv = (int *)malloc(GL.numVertexes*sizeof(int));
    for(int i = 0; i < GL.numVertexes; i++)
        etv[i] = 0;
    
    /* 生成拓扑序列 */
    stack2 = (int *)malloc(GL.numVertexes*sizeof(int));
    int top2 = 0;
    while(top != 0)
    {
        gettop = stack[top--];
        count++;
        stack2[++top2] = gettop;
        for(e = GL.AdjList_topology[gettop].firstedge; e; e = e->next)
        {
            k = e->adjvex;
            if(!(--GL.AdjList_topology[k].in))
                stack2[++top] = k;
            if((etv[gettop] + e->weight) > etv[k])
                etv[k] = etv[gettop] + e->weight;
        }
    }

    /* 判断是否已经全图扫描并实现完整拓扑序列 */
    if(count < GL.numVertexes)
        return ERROR;
    else
        return OK;
}

/* 关键路径算法：
    在拓扑序的基础上求关键路径 */
void CriticalPath(GraphAdjList_topology GL)
{
    EdgeNode *e;
    TopologicalSort_CriticalPath(GL);
    int ete, lte;
    int gettop, k;
    
    /* 初始化 */
    ltv = (int *)malloc(GL.numVertexes*sizeof(int));
    for(int i = 0; i < GL.numVertexes; i++)
        ltv[i] = etv[GL.numVertexes - 1];
    
    /* 计算ltv=latest_time_of_vertex */
    while (top2 != 0)
    {
        gettop = stack2[top2--];
        for(e = GL.AdjList_topology[gettop].firstedge; e; e = e->next)
        {
            k = e->adjvex;
            if(ltv[k] - e->weight < ltv[gettop])
                ltv[gettop] = ltv[k] - e->weight;
        }
    }/* 到这里已经有了etv、ltv */

    /* 比较lte、ete是否相等，判断是否为关键路径 */
    for(int j = 0; j < GL.numVertexes; j++)
    {
        for(e = GL.AdjList_topology[j].firstedge; e; e = e->next)
        {
            k = e->adjvex; // vk是到达事件
            ete = etv[j];
            lte = ltv[k] - e->weight;
            if(ete == lte)
            {
                printf("<v%d, v%d>length: %d , ",
                GL.AdjList_topology[k].data,
                GL.AdjList_topology[k].data, 
                e->weight);
            }
        }
    }
}

/* 第8章 查找 */
/* 顺序表查找优化————哨兵机制
    将哨兵置为顺序表头或顺序表尾，免去越界判断 */
int Sequential_Search2(int *a, int n, int key)
{
    int i = n;
    a[0] = key;
    while(a[i] != key)
        i--;
    return i;
}

/* 有序表的查找
    折半查找、插值查找、斐波那契查找 */
/* 折半查找 */
int Binary_Search(int *a, int n, int key)
{
    int low, high, mid;
    low = 1;
    high = n;
    while(low <= high)
    {
        mid = (low + high)/2;
        if(key < a[mid])
            high = mid - 1;
        else if(key > a[mid])
            low = mid + 1;
        else
            return mid;
    }
    return 0;
}

/* 插值查找
    关键在于插值公式: mid = low + (high-low)*(key-a[low])/(a[high]-a[low])
与折半查找相比，只是mid的计算公式进行了优化，适合"关键字分布比较均匀的查找表"，不适合极端不均的数据 */

/* 斐波那契查找
    利用黄金分割的原理
    算法核心：
        当key = a[mid]时，查找就成功；
        当key < a[mid]时，新范围是第low个到第mid-1个，此时范围个数为F[k-1]+1个；
        当key > a[mid]时，新范围是第mid+1个到第high个，此时范围个数为F[k-2]-1个 */
/* 求斐波那契数列 */
int *F; // 斐波那契查找中的全局变量，用来存储斐波那契数列的动态数组
void Fibonacci(int *F, int n)
{
    if(n < 1) 
        F[0] = 0;
    else if(n == 1)
    {
        F[0] = 0; F[1] = 1;
    }
    else
    {
        F[0] = 0; F[1] = 1; F[2] = 1;
    }

    int res = 1, pre = 1, temp = 0;
    for(int i = 3; i < n; i++)
    {
        temp = res;
        res = pre + res;
        pre = temp;
        F[i] = res;
    }
}

int Fibonacci_Search(int *a, int n, int key)
{
    int low, high, mid, k;
    low = 1;
    high = n;
    k = 0;
    while(n > F[k] - 1)
        k++;
    F = (int *)malloc((F[k] - 1 - n)*sizeof(int));
    Fibonacci(F, n);

    for(int i = n; i < F[k] - 1; i++)
        a[i] = a[n];
    while(low <= high)
    {
        mid = low + F[k-1] - 1;
        if(key < a[mid])
        {
            high = mid - 1;
            k = k - 1;
        }
        else if(key > a[mid])
        {
            low = mid + 1;
            k = k - 2;
        }
        else
        {
            if(mid <= n)
                return mid;
            else
                return n;
        }
    }
    return 0;
}

/* 线索索引表
    线性索引、树形索引、多级索引 */
/* 线性索引：稠密索引、分块索引、倒排索引in-verted index
    倒排索引内涵：不是由记录来确定属性值，而是由属性值来确定记录的位置 */

/* 树形索引：二叉排序树
    二叉排序树的查找、插入、删除操作 */
Status SearchBST(BiTree T, int key, BiTree f, BiTree *p)
{
    if(!T)
    {
        *p = f;
        return false;
    }
    else if(key == T->data)
    {
        *p = T;
        return true;
    }
    else if(key < T->data)
        return SearchBST(T->lchild, key, T, p);
    else 
        return SearchBST(T->rchild, key, T, p);
}

Status InsertBST(BiTree *T, int key)
{
    BiTree p, s;
    if(!(SearchBST(*T, key, NULL, &p)))
    {
        s = (BiTree)malloc(sizeof(BiTNode));
        s->data = key;
        s->lchild = NULL;
        s->rchild = NULL;
        if(!p)
            *T = s;
        else if(key < p->data)
            p->lchild = s;
        else
        {
            p->rchild = s;
            return TRUE;
        }
    }
    else
        return FALSE;
}

Status Delete(BiTree *p)
{
    BiTree q, s;
    /* 只有左子树的情况 */
    if((*p)->rchild == NULL)
    {
        q = *p;
        *p = (*p)->lchild;
        free(q);
    }
    /* 只有右子树的情况 */
    else if((*p)->lchild == NULL)
    {
        q = *p;
        *p = (*p)->rchild;
        free(q);
    }
    /* 既有左子树又有右子树的情况 */
    else
    {
        q = *p;
        s = (*p)->lchild;
        /* 用顺序表的前驱替代删除节点 */
        while(s->rchild)
        {
            q = s;
            s = s->rchild;
        }
        (*p)->data = s->data;
        /* 重接子树 */
        if(q != *p)
            q->rchild = s->lchild;
        else
            q->lchild = s->lchild;
        free(s);
    }
    return TRUE;
}

Status DeleteBST(BiTree *T, int key)
{
    if(!*T)
        return FALSE;
    else
    {
        if(key == (*T)->data)
            return Delete(T);
        else if(key < (*T)->data)
            return DeleteBST(&(*T)->lchild, key);
        else
            return DeleteBST(&(*T)->rchild, key);
    }
}

/* 动态查找表 ———— 查找、插入、删除操作的时间复杂度均为O(logn)
   二叉排序树因为树的结构不稳定（取决于根节点在序列中位置的影响，
   导致树的深度不确定，造成对树的查找等操作时间复杂度从O(logn)~O(n)不定。
   引出 平衡二叉树(AVL) ———— 每一个节点的左子树和右子树的高度差至多为1，
        最小不平衡子树 ———— 距离插入结点最近的，且平衡因子的绝对值大于1的节点为根的子树 */
/* 平衡二叉树的构造逻辑：每当插入一个结点时，先检查是否因插入而破坏了树的平衡性，若是，则找出最 小不平衡子树。在保持二叉排序树特性的前提下，调整最小不平衡子树
中各结点之间的链接关系，进行相应的旋转，使之成为新的平衡子树
   算法核心：当最小不平衡子树根 结点的平衡因子BF是大于1时，就右旋，小于-1时就左旋；
   插入结点后，最小不平衡子树的BF与它的子 树的BF符号相反时，就需要
   对结点先进行一次旋转以使得符号相同后，再反向旋转一次才能够完成平衡操作 */
typedef struct BiTNode_AVL
{
    int data;
    int bf; // 结点的平衡因子
    struct BiTNode_AVL *lchild, *rchild;
}BiTNode_AVL, *BiTree_AVL;

/* 右旋操作 */
void R_Rotate(BiTree_AVL *P)
{
    BiTree_AVL L; // 新根节点指针
    L = (*P)->lchild;
    (*P)->lchild = L->rchild;
    L->rchild = *P;
    *P = L;
}

/* 类似的有左旋操作 */
void L_Rotate(BiTree_AVL *P)
{
    BiTree_AVL R; // 新根节点指针
    R = (*P)->rchild;
    (*P)->rchild = R->lchild;
    R->lchild = *P;
    *P = R;
}
/* 有了左旋和右旋基本操作之后，AVL的平衡分为四种类型：LL, LR, RL, RR */
/* 左平衡旋转处理函数 */
#define LH 1
#define EH 0
#define RH -1
void LeftBalance(BiTree_AVL *T)
{
    BiTree_AVL Lr, L;
    L = (*T)->lchild;
    switch (L->bf)
    {
    /* 单右旋LL */
    case LH:
        (*T)->bf = L->bf = EH;
        R_Rotate(T);
        break;
    /* 双旋LR：先左旋，再右旋转 */
    case RH:
        Lr = L->rchild;
        switch (Lr->bf)
        {
        case LH:
            (*T)->bf = RH;
            L->bf = EH;
            break;
        case EH:
            (*T)->bf = L->bf = EH;
            break;
        case RH:
            (*T)->bf = EH;
            L->bf = LH;
            break;
        }
        Lr->bf = EH;
        L_Rotate(&(*T)->lchild);
        R_Rotate(T);
    }
}

/* 同理有 右平衡旋转处理函数 */
void RightBalance(BiTree_AVL *T)
{
    BiTree_AVL Rr, R;
    R = (*T)->rchild;
    switch (R->bf)
    {
    /* 单左旋RR */
    case RH:
        (*T)->bf = R->bf = EH;
        L_Rotate(T);
        break;
    /* 双旋RL：先右旋，再左旋转 */
    case LH:
        Rr = R->lchild;
        switch (Rr->bf)
        {
        case RH:
            (*T)->bf = LH;
            R->bf = EH;
            break;
        case EH:
            (*T)->bf = R->bf = EH;
            break;
        case LH:
            (*T)->bf = EH;
            R->bf = RH;
            break;
        }
        Rr->bf = EH;
        R_Rotate(&(*T)->rchild);
        L_Rotate(T);
    }
}

/* 若在平衡的二叉排序树T中不存在和e有相同关键字的结点，则插入一个数据元素为e的新结点并返回1，否则返回0。
   若因插入而使二叉排序树 失去平衡，则作平衡旋转处理，布尔变量taller 反映T长高与否。 */
Status InsertAVL(BiTree_AVL *T, int e, Status *taller)
{
    if(!*T)
    {
        *T = (BiTree_AVL)malloc(sizeof(BiTree_AVL));
        (*T)->data = e;
        (*T)->lchild = (*T)->rchild = NULL;
        (*T)->bf = EH;
        *taller = TRUE;
    }
    else
    {
        if(e == (*T)->data)
        {
            *taller = FALSE;
            return FALSE;
        }
    }

    if(e < (*T)->data)
    {
        if(!InsertAVL(&(*T)->lchild, e, taller))
            return FALSE;
        if(*taller) // 已经将e插入到平衡二叉树T中
        {
            switch ((*T)->bf)
            {
            // 本来就是左子树更高，现在插入新元素后更高，需要对T进行左平衡旋转处理
            case LH: 
                LeftBalance(T);
                *taller = FALSE;
                break;
            case EH:
                (*T)->bf = LH;
                *taller = TRUE;
                break;
            case RH:
                (*T)->bf = EH;
                *taller = FALSE;
                break;
            }
        }
        else
        {
            if(InsertAVL(&(*T)->rchild, e, taller))
                return FALSE;
            switch ((*T)->bf)
            {
            case LH:
                (*T)->bf = EH;
                *taller = FALSE;
                break;
            case EH:
                (*T)->bf = RH;
                *taller = TRUE;
                break;
            case RH:
                RightBalance(T);
                *taller = FALSE;
                break;
            }
        }
    }
    return TRUE;
}

/* 多路查找树
    2-3树、2-3-4树、B树、B+树、B-树 */
/* B树为什么除了根节点外每个分支节点至少有「m/2」棵子树？？？ */

/* 散列表的查找（哈希表）
    选择散列函数的参考因素：
        1、计算散列地址所需的时间
        2、关键字的长度
        3、散列表的大小
        4、关键字的分布
        5、记录查找的频率 */
#define SUCCESS 1
#define UNSECCESS 0
#define HASHSIZE 12
#define NULLKEY -32768
typedef struct 
{
    int *elem;
    int count;
}HashTable;
int m = 0;

Status InitHashTable(HashTable *H)
{
    int i;
    m = HASHSIZE;
    H->count = m;
    H->elem = (int *)malloc(m * sizeof(int));
    for(i = 0; i < m; i++)
        H->elem[i] = NULLKEY;
    return OK;
}

int Hash(int key)
{
    /* 除留余数法 */
    return key % m;
}

/* 插入关键字进散列表 */
void InsertHash(HashTable *H, int key)
{
    int addr = Hash(key);
    /* 如果不为空，则冲突 */
    while(H->elem[addr] != NULLKEY)
        addr = (addr + 1) % m;
    H->elem[addr] = key;
}

/* 散列表查找关键字 */
Status SearchHash(HashTable *H, int key, int *addr)
{
    *addr = Hash(key);
    while(H->elem[*addr] != key)
    {
        *addr = (*addr + 1) % m;
        if(H->elem[*addr] == NULLKEY || *addr == Hash(key))
            return UNSECCESS;
    }
    return SUCCESS;
}

/* 第9章 排序
    简单算法：冒泡排序、简单选择排序、直接插入排序
    改进算法：希尔排序、堆排序、归并排序、快速排序
    交换排序类：冒泡排序->快速排序
    选择排序类：简单选择排序->堆排序
    插入排序类：直接插入排序->希尔排序 */
/* 顺序表结构 */
#define NEWMAXSIZE 10
typedef struct 
{
    /* r[0]用作哨兵或临时变量 */
    int r[NEWMAXSIZE + 1];
    int length;
}NewSqList;

void Swap(NewSqList *L, int a, int b)
{
    int temp = L->r[a];
    L->r[a] = L->r[b];
    L->r[b] = temp;
}

/* 冒泡排序 */
void BubbleSort(NewSqList *L)
{
    for(int i = 1; i < L->length; i++)
    {
        for(int j = L->length - 1; j >= i; j--)
        {
            if(L->r[j] > L->r[j + 1])
                Swap(L, i, j + 1);
        }
    }
}

/* 冒泡排序优化 */
void BubbleSort2(NewSqList *L)
{
    Status flag = TRUE; // 标记是否经过交换
    for(int i = 1; i < L->length && flag; i++) //设置轮询次数
    {
        flag = FALSE;
        for(int j = L->length - 1; j >= i; j--)
        {
            if(L->r[j] > L->r[j + 1])
            {
                Swap(L, j, j + 1);
                flag = TRUE;
            }
        }
    }
}

/* 简单选择排序算法
    ———— 每次排好一个最小值 */
void SelectSort(NewSqList *L)
{
    for(int i = 1; i < L->length; i++)
    {
        int min = i;
        for(int j = i + 1; j <= L->length; j++)
        {
            if(L->r[min] > L->r[j])
                min = j;
        }
        if(i != min)
            Swap(L, i, min);
    }
}

/* 直接插入排序 */
void InsertSort(NewSqList *L)
{
    int j;
    for(int i = 2; i < L->length; i++)
    {
        if(L->r[i] < L->r[i - 1])
        {
            L->r[0] = L->r[i];
            for(j = i - 1; L->r[j] < L->r[0]; j--)
            {
                /* 记录后移 */
                L[j + 1] = L[j];
            }
            L->r[j + 1] = L->r[0];
        }
    }
}

/* 希尔排序 */
void ShellSort(NewSqList *L)
{
    int j;
    int increment = L->length;
    do
    {
        /* 增量序列 */
        increment = increment / 3 + 1;
        for(int i = increment + 1; i < L->length; i++)
        {
            if(L->r[i] < L->r[i - increment])
            {
                L->r[0] = L->r[i];
                for(j = i - increment; j > 0 && L->r[0] < L->r[j]; j -= increment)
                    L->r[j + increment] = L->r[j];
            }
            L->r[j + increment] = L->r[0];
        }
    } while (increment > 1);
}

/* 堆排序 时间复杂度O(nlogn)
    ———— 大根堆、小根堆 */
/* L[s..m]中只有L[s]不满足大根堆条件，调整L[s]使得s...m成为大根堆 */
void HeapAdjust(NewSqList *L, int s, int m)
{
    int j, temp;
    temp = L->r[s];
    for(j = 2 * s; j <= m; j *= 2)
    {
        if(j < m && L->r[j] < L->r[j + 1])
            ++j;
        if(L->r[s] > L->r[j])
            break;
        L->r[s] = L->r[j];
        s = j;
    }
    L->r[s] = temp; 
}

void HeapSort(NewSqList *L)
{
    int i;
    /* 先把L排列成大根堆 */
    for(i = L->length / 2; i > 0; i--)
        HeapAdjust(L, i, L->length);
    for(i = L->length; i > 1; i--)
    {
        Swap(L, 1, i);
        HeapAdjust(L, 1, i - 1);
    }
}

/* 归并排序 时间复杂度O(logn) 空间复杂度O(n + logn)*/
/* 递归实现法 */
void Merge(int SR[], int TR[], int i, int m, int n)
{
    int j, k, l; // j:右待归并数组的下标；k:TR数组的下标；l:剩余部分的增量；
    for(j = m + 1, k = i; i <= m && j <= n; k++)
    {
        if(SR[i] < SR[j])
            TR[k] = SR[i++];
        else
            TR[k] = SR[j++];
    }
    /* 将剩下的部分填充到TR[]中 */
    if(i <= m)
    {
        for(l = 0; l <= m - i; l++)
            TR[k + l] = SR[i + l];
    }
    if(j <= n)
    {
        for(l = 0; l <= n - j; l++)
            TR[k + l] = SR[j + l];
    }
}

void MSort(int SR[], int TR1[], int s, int t)
{
    int m;
    int TR2[MAXSIZE + 1];
    if(s == t)
        TR1[s] = SR[t];
    else
    {
        m = (s + t) / 2;
        MSort(SR, TR2, s, m);
        MSort(SR, TR2, m + 1, t);
        Merge(TR2, TR1, s, m, t);
    }
}

void MergeSort(NewSqList *L)
{
    MSort(L->r, L->r, 1, L->length);
}
/* 非递归实现法
    ———— 递归法改为迭代法
    优化：避免递归时深度为log2n的栈空间，空间只是用到申请归并临时用的TR数组。
         因此，空间复杂度为O(n)。 */
void MergePass(int SR[], int TR[], int s, int n)
{ // n代表线性表长度，s代表线性表调整起始位置
    int i = 1;
    int j;
    while(i <= n - 2 * s + 1)
    {
        Merge(SR, TR, i, i+s-1, i+2*s-1);
        i = i + 2 * s;
    }
    /* 归并最后两个序列 */
    if(i < n - s + 1)
        Merge(SR, TR, i, i + s - 1, n);
    /* 若最后只剩下单个子序列 */
    else
        for(j = i; j <= n; j++)
            TR[j] = SR[j];
}
/* 迭代法实现归并排序 */
void MergeSort2(NewSqList *L)
{
    int *TR = (int *)malloc(L->length * sizeof(int));
    int k = 1;
    while(k < L->length)
    {
        MergePass(L->r, TR, k, L->length);
        k = 2 * k;
        MergePass(TR, L->r, k, L->length);
        k = 2 * k;
    }
}

/* 快速排序 时间复杂度O(nlogn) 空间复杂度O(logn)*/
int Partition(NewSqList *L, int low, int high)
{
    int pivotkey;
    /* 子表的第一个记录作枢轴记录 */
    pivotkey = L->r[low];
    while (low < high)
    {
        while (low < high && L->r[high] >= pivotkey)
            high--;
        Swap(L, low, high);
        while(low < high && L->r[low] <= pivotkey)
            low++;
        Swap(L, low, high);
    }
    return low;
}
/* 优化不必要的交换 
    ———— pivotkey一直在和L->r[low]或L->r[high]交换，可以用L->r[0]来暂存
         当需要交换的时候，直接替代 */
int Partition1(NewSqList *L, int low, int high)
{
    int pivotkey;
    pivotkey = L->r[low];
    L->r[0] = pivotkey;
    while(low < high)
    {
        while(low < high && L->r[high] >= pivotkey)
            high--;
        L->r[low] = L->r[high];
        while (low < high && L->r[low] <= pivotkey)
            low++;
        L->r[high] = L->r[low];
    }
    /* 将枢轴数值替换回L->r[low] */
    L->r[low] = L->r[0];
    return low;
}
/* 当数据很多的时候，快排的递归操作反复函数跳转的性能影响不显著；
   但当数据很少的时候，这种递归操作会对性能造成显著影响。
   改进：当high-low不大于某个常数时，用直接排序 */
#define MAX_LENGTH_INSERT_SORT 7 /* 数组长度阈值 */
void QSort(NewSqList *L, int low, int high)
{
    int pivot; // 支点
    if((high - low) > MAX_LENGTH_INSERT_SORT)
    {
        pivot = Partition(L, low, high);
        QSort(L, low, pivot - 1);
        QSort(L, pivot + 1, high);
    }
    else
        InsertSort(L);
}
/* 优化递归操作，因为当待排序序列长度很长，且序列划分极端不平衡时，
   递归深度趋近于n，而不是logn。
   同时，递归需要消耗栈空间，函数参数越多，每次递归耗费的空间也越多。
   因此，要减少递归，从而大大提高性能 */
void QSort1(NewSqList *L, int low, int high)
{
    int pivot;
    if((high - low) > MAX_LENGTH_INSERT_SORT)
    {
        while (low < high)
        {
            pivot = Partition1(L, low, high);
            QSort1(L, low, pivot - 1);
            low = pivot + 1;
        }
    }
    else
        InsertSort(L);
}
void QuickSort(NewSqList *L)
{
    QSort(L, 1, L->length);
}