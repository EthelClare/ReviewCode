#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//���ȴ���һ���ڽӱ�

#define MAXVEX 9
typedef char VertexType; //ÿ���ڵ�������������
typedef int Tdgetype;	//	�ߵ�Ȩֵ�Ĵ�С

typedef struct EdgeNode
{
	int adjvex;  //�����ֵ������±�
	 //EdgeType info ;//����Ȩֵ,�ô���ʾ������Ҫ
	struct EdgeNode* next; // ��һ���ڵ�ĵ�ַ
}EdgeNode;

typedef struct VertexNode
{
	VertexType data;
	EdgeNode* firstedge;
}VertexNode , AdjList[MAXVEX];

typedef struct
{
	AdjList adjList;
	int numNodes, numEdges; //���浱ǰ�Ķ������ͱ���
}GraphAdjList;

#define MAXSIZE 9
//��ʼ��һ������


typedef struct
{
	int data[MAXSIZE];
	int front;//ͷָ���λ��
	int rear;//βָ���λ��
	int size;//������ʾ��ǰ�����е�Ԫ�ظ���
}Queue;

void InitQueue(Queue* Q)
{
	Q->front = 0;
	Q->rear = 0;
	Q->size = 0;
}

//�ж϶����Ƿ�Ϊ��
bool IsEmpty(Queue* Q)
{
	//Ϊ���򷵻�true,��Ϊ���򷵻�false
	if (Q->size == 0)
		return true;
	else
		return false;
}

void EnQueue(Queue* Q, int data)
{
	if (Q->size == MAXSIZE)
	{
		//��ʱ������Ϊ��
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
	printf("����������Ҫ�Ķ������: ");
	scanf("%d", &Graph->numNodes);

	// ��ʼ���ڽӱ�
	for (int i = 0; i < Graph->numNodes; i++)
	{
		Graph->adjList[i].firstedge = NULL;
	}

	printf("����������Ҫ�ı���: ");
	scanf("%d", &Graph->numEdges);

	for (int i = 0; i < Graph->numEdges; i++)
	{
		printf("�������%d���������������������ţ��ÿո�ָ���: ", i + 1);
		int v1, v2;
		scanf("%d %d", &v1, &v2); // ����������Ƕ������ţ���0��ʼ

		// Ϊ��������ӽڵ㵽�ڽӱ�
		EdgeNode* node1 = (EdgeNode*)malloc(sizeof(EdgeNode));
		node1->adjvex = v2;
		node1->next = Graph->adjList[v1].firstedge;
		Graph->adjList[v1].firstedge = node1;

		EdgeNode* node2 = (EdgeNode*)malloc(sizeof(EdgeNode)); // ��������ͼ����Ҫ����һ������Ҳ������
		if (node2 == NULL)
		{
			printf("Memory allocation is failed\n");
			exit(EXIT_FAILURE);
		}

		node2->adjvex = v1;
		node2->next = Graph->adjList[v2].firstedge;
		Graph->adjList[v2].firstedge = node2;
	}

	printf("ͼ�Ѵ�����ɡ�\n");

}

//�������Ƕ��ڽӱ�Ĺ�������㷨

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
