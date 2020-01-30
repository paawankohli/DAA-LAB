#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void DFS(int** mat, int visited[], int v, int node)
{
	if (visited[node] == 1)
		return;

	visited[node] = 1;
	printf("%d  ", node);

	for (int j = 0 ; j < v ; j++)
		if (mat[node][j] && !visited[j])
			DFS(mat, visited, v, j);

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

	printf("DFS: ");
	DFS(mat, visited, v, 0);

	printf("\n");
}