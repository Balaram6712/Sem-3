#include<iostream>
#include<bits/stdc++.h>
#include<limits.h>
#include<stdlib.h>	
#define F 100000000
using namespace std;
//typedef pair<int, int>  int pairpair<int, int> ;	

class Grp
{
	int V;																							//number of vertices as instance of class
	void dfsuntil(int v,bool visit[]);																//function for computing the dfs for the graph created
	void dfs2(int y,bool vis[]);
	list< pair<int, int> > *ad;																		//vertices weight and vertex stored in adjoinlist
public:
	Grp(int V)																						//constructor for graph
	{
		this->V = V;																				//constructor for V
		ad = new list< pair<int, int> > [V];														//creating adojint lists
	};
	void add_edge(int u,int v,int w)																//method to add edge to graph
	{
			ad[u].push_back(make_pair(v,w));
			ad[v].push_back(make_pair(u,w));
	};
	int ncomp();																					//method to find the number of components
	int cncom();
	void shortestpaths(int sr);
};

class Dirgraph
{
	int N;
	list< pair<int, int> > *aj;
public:
	Dirgraph(int N)													
	{
		this->N = N;
		aj = new list< pair<int, int> > [N];
	};
	void add(int p,int q,int r)
	{
			aj[p].push_back(make_pair(q,r));
	};
	void paths(int sc);	
};

void Dirgraph::paths(int sc)
{	
	priority_queue<  pair<int, int> ,  vector< pair<int, int> > , greater< pair<int, int> > > mq;						//min priority queue
	vector<int> dist(N, F); 																							//for every vertex making disttance as infinity
	mq.push(make_pair(0, sc));																							//dist[sc]=0
	dist[sc] = 0;
	int D=0;
	bool convi[N];
	int w=0;
	for(w=0;w<N;w++)
	{
		convi[w] = false;
	}
	while(!mq.empty())																									//while queue is not empty
	{
		int u = mq.top().second;																						//cout << "poping out of queues" << endl;
		mq.pop();
		list< pair<int, int>>::iterator io;																				//for all the edges we need to iterate for the opped element
		for(io = aj[u].begin();io !=aj[u].end();io++)
		{
			int v = (*io).first;																						//node value
			int weight = (*io).second;
			convi[v] = true;																					//weight value 
			if( dist[u] + weight < dist[v])
			{	
				dist[v] = dist[u] + weight;																								//decreasing key value in the queue
				mq.push(make_pair(dist[v], v));																			//updated ditance value and vertex updating
			}
		}
	}																													//code for printing
	int i=0;
	for(i=0;i<N;++i)
	{
		if(dist[i] != F && (convi[i]))
		{
			cout << sc << " " << i << " " << dist[i] << endl;			
		}
		else if (dist[i] == F && (convi[i]))
		{
			cout << sc << " "<<  i << "not reachable" << endl;
		}
	}	
}

void Grp::shortestpaths(int sr)
{
	priority_queue<  pair<int, int> ,  vector< pair<int, int> > , greater< pair<int, int> > > mpq;			
	vector<int> dis(V, F); 
	mpq.push(make_pair(0, sr));
	dis[sr] = 0;
	int C=0;
	while(!mpq.empty())
	{
		int u = mpq.top().second;
		mpq.pop();
		list< pair<int, int>>::iterator itr;
		for(itr = ad[u].begin(); ;)
		{
		//	cout << "checking edges for a vertex and decreasing key" << endl;
			int v = (*itr).first;//node value
			int weight = (*itr).second;//weight value 
			if( dis[u] + weight < dis[v])
			{
				//updating th distance
				dis[v] = dis[u] + weight;
				//decreasing key value in the queue
				mpq.push(make_pair(dis[v], v));//updated ditance value and vertex updating
			}
			itr++ ;
			C = C + 1;
			if(itr == ad[u].end())
			{
				break;
			}
		}
	}//code for printing
	int i=0;
	for(i=0;i<V;++i)// c OR V
	{
		cout << sr << " " << i << " " << dis[i] << endl;
	}	
}
void heapify(int i,int a[] ,int n[])	//heapify the array
{
   int small;
   small = i;
   int left;
   int right;
   left = 2*i+1;
   right = 2*i+2;
   if((right < n[0]) && (a[right] < a[small]))
   {
   		small = right;
   }
   if((left < n[0]) && (a[left] < a[small]))
   {
   		small = left;
   }
   if(small != i)
   {
   		int temp;
   		temp = a[i];
   		a[i] = a[small];
   		a[small] = temp;
   		heapify(small,a,n);
   }
}//not used

void buildingminheap(int a[],int n[])	//building a heap
{
	int i=(n[0]/2)-1;
	for(int j=i;j>=0;j--)
	{
		heapify(j,a,n);
	}
}

int extractmin(int a[],int n[]) 		//extracting min of a heap
{
	int min;
	min = a[0];
	a[0] = a[n[0]-1];
	n[0] = n[0]-1;
	heapify(0,a,n);
	return min;
}
int Grp::cncom()	//counting components
{
	bool *vis = new bool[V];
	int v;
	int count=0;
	for(v=0;v<V;v++)
	{
		vis[v] = false;
	}
	for(v=0;v<V;v++)
	{
		if(vis[v] == false)
		{
			dfs2(v,vis);
			count = count + 1; 
		}
	}
	return count;
} 	

int Grp::ncomp()		//	counting components and printing the pasth as well
{
	bool *visit = new bool[V];
	int v;
	int count=0;
	for(v=0;v<V;v++)
	{
		visit[v] = false;
	}
	for(v=0;v<V;v++)
	{
		if(visit[v] == false)
		{
			dfsuntil(v,visit);
			cout << endl;
			count = count + 1; 
		}
	}	
	return count;
}  

void Grp::dfs2(int y,bool vis[])	//dfs
{
	vis[y] = true;
	list< pair<int, int>>::iterator it;
	for(it = ad[y].begin(); it != ad[y].end(); it++)
	{
		if (!vis[(*it).first])
		{
			dfs2((*it).first,vis);
		}
	}
}
void Grp::dfsuntil(int v,bool visit[])
{
	visit[v] = true;//marking the vertex as visit
//	a[y] = v;
//	y = y + 1;
	cout << v << " ";
	list< pair<int, int>>::iterator it;
	for(it = ad[v].begin(); it != ad[v].end(); it++)
	{
		if (!visit[(*it).first])
		{
			dfsuntil((*it).first,visit);
		}
	}
} 

int main()
{
	int V;
	int N;
	cout << "Enter number of vertices:";
	cin >> V;
	N = V;
	Grp gr(V);//graph for undirected
	Dirgraph gv(N);//graph for directed
	cout << "Input:" << endl;
	cout << "Enter source destination and weight" << endl;
	int i=0;
	while(1)
	{
		char x;
		int u,v,w;
		x = getchar();
		if(x == 'E')
		{
			cin >> u >> v >> w;
			gr.add_edge(u,v,w);
			gv.add(u,v,w);
		}
		else if(x == '\n')
		{
			char y;
			int u,v,w;
			y = getchar();
			if(y == 'E')
			{
				cin >> u >> v >> w;
				gr.add_edge(u,v,w);
				gv.add(u,v,w);
			}
			else if(y == '\n')
			{
				break;
			}
		}
	}
	char fun;
	cout << endl;
	cout << "Functionality input:" << endl;
	cout << "Enter 'F' to Find:" << endl;
	cout << "Enter 'S ' to find shortes paths:" << endl;
	cout << "Enter two new lines to exit from functionality input" << endl;
	int num;
	while(1)
	{
		char fun;
		fun = getchar();
		if(fun == 'F')
		{
			num = gr.cncom();
			cout << num << " Components" << endl;
			gr.ncomp();
		}
	 	if(fun == 'S')
		{
			int s;
			cout << "Enter source point:";//shortest path print the distances in the connected graph
			cin >> s;
			gv.paths(s);
		}
		else if(fun == '\n')
		{
			char fun2;
			fun2 = getchar();
			if(fun2 == 'F')
			{
				num = gr.cncom();
				cout << num << " Components" << endl;
				gr.ncomp();
			}
			else if(fun2 == 'S')
			{
				int s;
				cout << "Enter source point:";//shortest path print the distances in the connected graph
				cin >> s;
				gv.paths(s);
			}
			else if(fun2 == '\n')
			{
				break;
			}
		}
	}
}
