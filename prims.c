#include<stdio.h>
#include<limits.h>
 
int vertices;
 
int min_key(int k[] , int mst[])
{
	int minimum = INT_MAX ,min ,i;
	for(i=0;i<vertices ;i++)
	{
		if(mst[i]==0 && k[i]<minimum)
		{
			minimum = k[i];
			min =i;
		}
	}
	return min;
}
 
void prims(int g[vertices][vertices])
{
	int parent[vertices];
	int k[vertices];
	int mst[vertices];
	int edge , count , i ,v;
	for(i=0;i<vertices ;i++)
	{
		k[i]= INT_MAX;
		mst[i]=0;
	}
	k[0]=0;
	parent[0]=-1;
	for(count =0 ; count <vertices ;count++)
	{
		edge = min_key(k , mst);
		mst[edge] = 1;
 
		for(v =0 ; v<vertices ;v++)
		{
			if(g[edge][v] && mst [v] == 0 && g[edge][v]<k[v])
			{
				parent[v] = edge;
				k[v] = g[edge][v];
			}
		}
	}
	printf("Minimum Spanning Tree:\n");
	printf("\nEdge \t Weight\n");
	for(i= 1 ; i<vertices ;i++)
	{
		printf("%d <-> %d  %d \n", parent[i],i,g[i][parent[i]]);
	}
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
 
	printf("\n Enter source, destination and weight:\n");
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
	prims(graph);
	return 0;
}