#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//首先创立一个邻接表

#define MAXVEX 9
typedef char VertexType; //每个节点所包含的数据
typedef int Tdgetype;	//	边的权值的大小

typedef struct EdgeNode
{
	int adjvex;  //储存该值顶点的下标
	 //EdgeType info ;//储存权值,该代码示例不需要
	struct EdgeNode* next; // 下一个节点的地址
}EdgeNode;

typedef struct VertexNode
{
	VertexType data;
	EdgeNode* firstedge;
}VertexNode , AdjList[MAXVEX];

typedef struct
{
	AdjList adjList;
	int numNodes, numEdges; //保存当前的定点数和边数
}GraphAdjList;

#define MAXSIZE 9
//初始化一个队列


typedef struct
{
	int data[MAXSIZE];
	int front;//头指针的位置
	int rear;//尾指针的位置
	int size;//用来表示当前队列中的元素个数
}Queue;

void InitQueue(Queue* Q)
{
	Q->front = 0;
	Q->rear = 0;
	Q->size = 0;
}

//判断队列是否为空
bool IsEmpty(Queue* Q)
{
	//为空则返回true,不为空则返回false
	if (Q->size == 0)
		return true;
	else
		return false;
}

void EnQueue(Queue* Q, int data)
{
	if (Q->size == MAXSIZE)
	{
		//此时队列中为满
		printf("Queue is full\n");
		exit(EXIT_FAILURE);
	}
	Q->data[Q->rear] = data;
	Q->size++;
	Q->rear = (Q->rear + 1) / MAXSIZE;

}

int  DeQueue(Queue* Q)
{
	if (Q->size == 0)
	{
		printf("Queue is empty\n");
		exit(EXIT_FAILURE);
	}
	
	int data = Q->data[Q->front];
	Q->front = (Q->front + 1) / MAXSIZE;
	Q->size--;
	return data;

}

void CreatALGraph(GraphAdjList * Graph)
{
	printf("请输入你需要的顶点个数: ");
	scanf("%d", &Graph->numNodes);

	// 初始化邻接表
	for (int i = 0; i < Graph->numNodes; i++)
	{
		Graph->adjList[i].firstedge = NULL;
	}

	printf("请输入你需要的边数: ");
	scanf("%d", &Graph->numEdges);

	for (int i = 0; i < Graph->numEdges; i++)
	{
		printf("请输入第%d条边依附的两个顶点的序号（用空格分隔）: ", i + 1);
		int v1, v2;
		scanf("%d %d", &v1, &v2); // 假设输入的是顶点的序号，从0开始

		// 为两条边添加节点到邻接表
		EdgeNode* node1 = (EdgeNode*)malloc(sizeof(EdgeNode));
		node1->adjvex = v2;
		node1->next = Graph->adjList[v1].firstedge;
		Graph->adjList[v1].firstedge = node1;

		EdgeNode* node2 = (EdgeNode*)malloc(sizeof(EdgeNode)); // 对于无向图，需要在另一个方向也创建边
		if (node2 == NULL)
		{
			printf("Memory allocation is failed\n");
			exit(EXIT_FAILURE);
		}

		node2->adjvex = v1;
		node2->next = Graph->adjList[v2].firstedge;
		Graph->adjList[v2].firstedge = node2;
	}

	printf("图已创建完成。\n");

}

//接下来是对邻接表的广度优先算法

bool visited[MAXSIZE];

void BFSTraverse(GraphAdjList GL)
{
	int i;
	EdgeNode* p;
	Queue Q;
	for (i = 0; i < GL.numNodes; i++)
	{
		visited[i] = false;
	}
	InitQueue(&Q);

	for (i = 0; i < GL.numNodes; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			printf("%c", GL.adjList[i].data);
			EnQueue(&Q, i);
			while (!IsEmpty(&Q))
			{
				DeQueue(&Q);
				p = GL.adjList[i].firstedge;
				while (p)
				{
					if (!visited[p->adjvex])
					{
						visited[p->adjvex] = true;
						printf("%c", GL.adjList[p->adjvex]);
						EnQueue(&Q, p->adjvex);
					}
					p = p->next;
				}
			}
		}

	}
}


int main()
{


	return 0;
}
