#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
 
int vertices=9 , edges;
int u , v , w , i , j ;
int min , min_w=0 , parent[9], ne=1 ,a,b;
 
int find(int i)
{
	while(parent[i])
	{
		i = parent[i];
	}
	return i;
}
 
int uni(int i , int j)
{
	if(i!=j)
	{
		parent[j]=i;
		return 1;
	}
	return 0;
}
 
void  kruskal(int graph[vertices][vertices])
{
	printf("The edges  of minimum spanning tree are:\n");
	while(ne<vertices)
	{
		for(i=0 , min= INT_MAX  ; i<vertices ;i++)
		{
			for(j=0;j<vertices; j++)
			{
				if(graph[i][j]<min)
				{
					min = graph[i][j];
					a = u = i;
					b = v = j;
				}
			}
		}
		u = find(u);
		v = find(v);
		if(uni(u,v))
		{
			printf("%d edge (%d,%d) =%d\n", ne++ , a , b , min);
			min_w+= min;
		}
		graph[a][b] = graph[b][a] = INT_MAX;
	}
	printf("\n\tMinimum Weight = %d", min_w);
}
 
int main()
{
	printf("Enter the number of vertices and edges : ");
	scanf("%d%d",&vertices , &edges);
	int graph[vertices][vertices];
	for(i=0;i<vertices;i++)
	{
		for(j=0;j<vertices;j++)
		{
			graph[i][j]=INT_MAX;
		}
	}
 
	int source , destination;
 
	printf("Enter the source , destination , weight :\n");
	for(i=0;i<edges;i++)
	{
		scanf("%d%d%d",&source,&destination,&w);
		graph[source][destination]= w;
		graph[destination][source]= w;
	}
 
	kruskal(graph);
	return 0;
}