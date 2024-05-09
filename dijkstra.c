#include <limits.h>
#include <stdio.h>
#include <stdbool.h>

int vertices;

int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < vertices; v++) {
        if (sptSet[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void printSolution(int dist[]) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < vertices; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
}

void dijkstra(int graph[vertices][vertices], int src) {
    int dist[vertices];
    bool sptSet[vertices];

    for (int i = 0; i < vertices; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < vertices - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;

        for (int v = 0; v < vertices; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist);
}

int main()
{
	int edges , i , j , u , v , w ;
	printf("Enter number of vertices and edges: ");
	scanf("%d%d",&vertices,&edges);
	int graph[vertices][vertices];
	for(i=0;i<vertices;i++)
	{
		for(j=0;j<vertices;j++)
		{
			graph[i][j]=0;
		}
	}
 
	printf("\nEnter source, destination and weight:\n");
	for(i=0;i<edges;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		graph[u][v]=w;
		graph[v][u]=w;
	}
	printf("Adjency Matrix of the input graph:\n");
	for(i=0;i<vertices;i++)
	{
		printf("\n");
		for(j=0;j<vertices;j++)
		{
			printf("%d  ",graph[i][j]);
		}
		printf("\n");
	}
	dijkstra(graph, 0);
	return 0;
}