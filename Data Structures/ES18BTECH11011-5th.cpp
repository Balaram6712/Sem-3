#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Disjointsets
{
	int n;
	int *rank;
	int *parent;
	//constructor for structure
public:
	Disjointsets(int n)
	{//a make set function 
		this->n = n;
		rank = new int[n+1];
		parent = new int[n+1];
		//making the rank zero
		int i=0;
		for(i=0;i<n+1;i++)
		{
			rank[i] = 0;
			parent[i] = i;//retrun element as parent to every element initil
		}//indirectly gives make set for every vertex
	};
	int find(int x)//find set
	{
		if(x != parent[x])
		{
			parent[x] = find(parent[x]);
		}
		return parent[x];
	};
	void unin(int x,int y);
};//class for Disjointsets

class Grp
{
	int V;//instaces
	void dfsuntil(int v,bool visit[]);
	vector < pair<int, pair<int , int> > > edge;  //edge ass vector taken with u,v,w but in this w, (u,v) is in the edge vector
public:
	Grp(int V)
	{
		this->V = V;
	};//constructor
	void add_edge(int u,int v,int w)
	{
		edge.push_back({w, {u, v}});//undirected weighted graph
	};
	int ncomp();
	void kruskal();
};

void Disjointsets::unin(int x,int y)//uninon of two sets
{
	x = find(x);
	y = find(y);
	if(rank[x] < rank[y])
	{
		parent[x] = y;
	}
	else
	{
		parent[y] = x;
	}
	if(rank[x] == rank[y])
	{
		rank[y] = rank[y] + 1;
	}
} 
void Grp::kruskal()
{

	Disjointsets dset(V);//make set for all the vertices
	//vector< pair<int, int> > mst;//to push backthe sotred vertices into a vector
	int a[2][V-1];//array to store the mst and print it
	int y=0;
	sort(edge.begin(), edge.end());//sorting the edges
	vector< pair<int, pair<int , int> > >::iterator it;
	for(it=edge.begin();;)
	{
		int u = it->second.first;
		int v =	it->second.second;//find set and checking which set they belong
		if(dset.find(u) != dset.find(v))
		{
			dset.unin(dset.find(u),dset.find(v));//union of two sets
		//	cout << "(" << u << "," << v<<") ";
	//		mst.push_back(make_pair(u, v));
			a[0][y] = u;
			a[1][y] = v;
			y = y + 1;
		}
		it++;
		if(it==edge.end())
		{
			break;
		}
	}
	int u=0;
	for(u=0;u<y;u++)
	{
		cout << "("<< a[0][u] << "," <<a[1][u] <<") "; 

	//	cout << "(" << mst[u].first << "," <<mst[u].second <<")";
	}
	cout <<endl;
}
int Grp::ncomp()
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
			count = count + 1; 
		}
	}
	return count;
//perform dfs on the prsesnt formed Grp and keep an iterator to count
}  
void Grp::dfsuntil(int v,bool visit[])
{
	visit[v] = true;//marking the vertex as visit
	vector< pair<int, pair<int , int> > >::iterator itr;
	for(itr = edge.begin(); ; )
	{
		if (!visit[itr->second.second])
		{
			dfsuntil(itr->second.second,visit);
		}
		itr++;
		if(itr == edge.end())
		{
			break;
		}
	}//performing dfs to count the number of components in the graph
} 
int main()
{
	int n;
	cout << "Enter the number of vertices:";
	cin >> n;
	Grp gr(n); //creating an object and adding edges
	int a[n][n];
	int i=0;
	int j=0;
	cout << "Enter source destination and distance" << endl;
	while(1)
	{
		char x;
		int u,v,w;
		x = getchar();
		if(x=='E')
		{
			cin >> u >> v >> w;
			gr.add_edge(u,v,w);
		}
		else if(x=='\n')
		{
			char y;
			int u,v,w;
			y = getchar();
			if(y == 'E')
			{
				cin >> u >> v >> w;
				gr.add_edge(u,v,w);
			}
			else if(y == '\n')
			{
				break;
			}
		}
	}
	int t=0;
	int num=0;
    num = gr.ncomp();
    if(num > 1)//if components grater than 1 does not form a MST as all edges not covered
    {
    	cout << "Minimum spanning tree does not exist as the vertices all are not connected"<<endl;
    } 
    else
    {
    	cout << "The spanning tree edges are"<<endl;
    	gr.kruskal();
    }
}