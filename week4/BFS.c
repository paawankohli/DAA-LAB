#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "intQueue.h"

void BFS(int** mat, int visited[], int v, int node)
{
	que q;
	q.front = q.rear = -1;

	push(&q, node);

	while (isEmpty(&q) == 0)
	{
		int currNode = pop(&q);
		visited[currNode] = 1;
		printf("%d  ", currNode);

		for (int j = 0 ; j < v ; j++)
			if (mat[currNode][j] && !visited[j])
				push(&q, currNode);
	}
}


int** inputElements(int** mat, int vertex, int edges)
{
	for (int i = 0 ; i < vertex ; i++)
		for (int j = 0 ; j < vertex ; j++)
			mat[i][j] = 0;

	for (int i = 0 ; i < edges ; i++)
	{
		printf("Insert starting vertex, terminating vertex of edge %d: \n", i + 1);

		int a, b;
		scanf("%d %d", &a, &b);

		mat[a][b] = 1;
		mat[b][a] = 1;
	}

	return mat;
}

int main()
{
	int** mat;
	int e, v;

	printf("Insert no of vertex: ");
	scanf("%d", &v);

	mat = (int**)malloc(v * sizeof(int*));
	for (int  i = 0 ; i < v ; i++)
		mat[i] = (int*)malloc(v * sizeof(int));

	printf("Insert no of edges: ");
	scanf("%d", &e);

	mat = inputElements(mat, v, e);

	int visited[v];
	for (int  i = 0 ; i < v ; i++)
		visited[i] = 0;

	printf("BFS: ");
	BFS(mat, visited, v, 0);

	printf("\n");
}