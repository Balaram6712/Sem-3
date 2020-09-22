#include<stdio.h>


void addedge(int N,int i,int j,int w,int d,int adj[][N])//int n,
{
	if(d)
	{
		adj[i][j] = w;
	}
	else
	{
		adj[i][j] = w;
		adj[j][i] = w;
	}
}

void neighbours(int N,int v,int adj[][N])
{
	int i=0;
	int k=0;
	int a[k];
	for(i=0;i<N;i++)
	{
		if(adj[v][i]!=0)
		{
			a[k] = i;
			k = k + 1;
		}
	}
	printf("Neighbours of V are: ");
	for(i=0;i<k;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
void vertices(int N,int adj[][N])
{
	int i=0;
  	int j=0;
	int flag = 0;
	printf("The vertices are:\n");
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(adj[i][j] == 0)
			{
				flag = 1;
			}
			else if(adj[i][j])
			{
        		flag = 0;
				break;
			}
		}
		if(flag==0)
		{
			printf("%d ",i);
		}
	}

//what are values in the nodes in the graph
}
void edge_weight(int N,int v1, int v2,int adj[][N])//int n,
{
	if(adj[v1][v2]!=0)
	{
		printf("%d\n",adj[v1][v2]);	
	}
	else
	{
		printf("No edge between v1 and v2\n");
	}
}

int contains(int N,int v,int adj[][N])
{ 
	int j=0;
	if(v>=0 && v < N)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

int contains_edge(int N,int v1,int v2,int adj[][N])
{
	if(adj[v1][v2] != 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	int N;
	printf("Enter the number of vertices: ");
	scanf("%d",&N);

	int ad[N][N];
  	int g=0;
  	int f=0;
  	for(g=0;g<N;g++)
  	{
    	for(f=0;f<N;f++)
    	{
      		ad[g][f] = 0;
    	}
  	}
	int u,v,w;
    int i=0;
    int d;
	int e;
	printf("Directed or Undirected:\n");
	printf("Enter 1 if directed Enter 0 if undirected:");
	scanf("%d",&d);
    printf("Input:\n");
	printf("Enter source destination and edge weight for an edge\n");
	int fg=0;
	int p=0;
	if(d==1)
	{
		while(1)
		{
			char x;
			x = getchar();
			if(x == 'E')
			{
				scanf("%d",&u);
				scanf("%d",&v);
				scanf("%d",&w);
				addedge(N,u,v,w,d,ad);
			}
			else if(x == '\n')
			{
				char y;
				y = getchar();
				if(y == 'E')
				{
					scanf("%d",&u);
					scanf("%d",&v);
					scanf("%d",&w);
					addedge(N,u,v,w,d,ad);
				}
				else if(y == '\n')
				{
					break;
				}
			}			
		}
	}
	else if(d==0)
	{
		while(1)
		{
			char x;
			x = getchar();
			if(x == 'E')
			{
				scanf("%d",&u);
				scanf("%d",&v);
				scanf("%d",&w);				
       			addedge(N,u,v,w,d,ad);
			}
			else if(x =='\n')
			{
				char y;
				y = getchar();
				if(y == 'E')
				{	
					scanf("%d",&u);
					scanf("%d",&v);
					scanf("%d",&w);				
       				addedge(N,u,v,w,d,ad);
				}
				else if(y == '\n')
				{
					break;
				}	
			}
		}
	}
	
	int v1;
	int v2;
	printf("Enter a number between 1 to 5 to perform functionality input\n");
    printf("Enter 1 to dispaly all neighbors of v\n");
   	printf("Enter 2 to display all vertices in Graph\n");
   	printf("Enter 3 to display the weight of the edge between v1 and v2\n");
    printf("Enter 4 to display whether Graph contains a vertex v\n");
   	printf("Enter 5 to display whether Graph contains an edge between v1 and v2\n");
	while(1)
   	{
   			char fun;
    		fun = getchar();
    		if(fun == '1')
    		{
    			printf("Enter the vertex v to know its neighbours:");
    			scanf("%d",&v1);
    			neighbours(N,v1,ad);
    			printf("\n");
    		}
    		else if(fun == '2')
    		{
    			vertices(N,ad);
    			printf("\n");
    		}
    		else if(fun == '3')
    		{
    			printf("Enter the vertices v1 and v2:");
    			scanf("%d",&v1);
    			scanf("%d",&v2);
    			edge_weight(N,v1,v2,ad);
			}
    		else if(fun == '4')
    		{
    			printf("Enter the vertex v:");
				scanf("%d",&v1);
    			if(contains(N,v1,ad) == 1)
    			{
    				printf("YES\n")	;
    			}
    			else if(contains(N,v1,ad) == 0) 
    			{
    				printf("NO\n");
    			}
    		}
        	else if(fun == '5')
    		{
    			printf("Enter the vertices v1 and v2:");
    			scanf("%d",&v1);
    			scanf("%d",&v2);
				if(contains_edge(N,v1,v2,ad)==1)
				{
					printf("YES\n");
				}			
				else if(contains_edge(N,v1,v2,ad)==0)
				{
					printf("NO\n");
				}
			}
    		else if(fun == '\n')
    		{
    	   		char fun2;
				fun2 = getchar();
    			if(fun2 == '1')
    			{
    				printf("Enter the vertex v to know its neighbours:");
    				scanf("%d",&v1);
    				neighbours(N,v1,ad);
    				printf("\n");
    			}
    			else if(fun2 == '2')
    			{
    				vertices(N,ad);
    				printf("\n");
    			}
    			else if(fun2 == '3')
    			{
    				printf("Enter the vertices v1 and v2:");
    				scanf("%d",&v1);
    				scanf("%d",&v2);
    				edge_weight(N,v1,v2,ad);
				}
    			else if(fun2 == '4')
    			{
    				printf("Enter the vertex v:");
					scanf("%d",&v1);
    				if(contains(N,v1,ad) == 1)
    				{
    					printf("YES\n")	;
    				}
    				else if(contains(N,v1,ad) == 0) 
    				{
    					printf("NO\n");
    				}
    			}
        		else if(fun2 == '5')
    			{
    				printf("Enter the vertices v1 and v2:");
    				scanf("%d",&v1);
    				scanf("%d",&v2);
					if(contains_edge(N,v1,v2,ad))
					{
						printf("YES\n");
					}			
					else if(contains_edge(N,v1,v2,ad))
					{
						printf("NO\n");
					}
				}
				else if(fun2 == '\n')
				{
					break;
				}
    		}	 
    }
}
