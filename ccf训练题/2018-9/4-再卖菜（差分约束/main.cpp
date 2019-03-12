#include<bits/stdc++.h>
using namespace std;


//spfa求最长路 
#define INF 1000000

class edge{
	public:
	int from,to,cost;
	edge(int f,int t,int c):from(f),to(t),cost(c) {}
};


int b[305];
vector<vector<edge> > graph(305);

bool inq[305];
int visitcount[305];
int d[305];  //即所描述的和函数s[] 

int main()
{
	freopen("a.txt","r",stdin);
	
	memset(inq,0,sizeof(inq));
	memset(visitcount,0,sizeof(visitcount));
	for(auto &ditem:d)
		ditem=0;  
			
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>b[i];
	graph[0].push_back(edge(0,2,2*b[1]));
	graph[2].push_back(edge(2,0,-2*b[1]-1));
	for(int i=0;i<=n-3;i++)
		graph[i].push_back(edge(i,i+3,3*b[i+2]));
	for(int i=3;i<=n;i++)
		graph[i].push_back(edge(i,i-3,-3*b[i-1]-2));
	graph[n-2].push_back(edge(n-2,n,2*b[n]));
	graph[n].push_back(edge(n,n-2,-2*b[n]-1));
	for(int i=0;i<n;i++)
		graph[i].push_back(edge(i,i+1,1));
	
	queue<int> Q;
	inq[0]=true;
	d[0]=0;
	Q.push(0);
	while(!Q.empty())
	{
		int node=Q.front();
		Q.pop();
		inq[node]=false;
		visitcount[node]++;
		if(visitcount[node]>n)
			;//负环
		for(int j=0;j<graph[node].size();j++)
		{
			int aimed=graph[node][j].to;
			int cost=graph[node][j].cost;
			if(d[aimed]<d[node]+cost)
			{
				d[aimed]=d[node]+cost;
				if(!inq[aimed])
				{
					Q.push(aimed);
					inq[aimed]=true;
				}	
			}
		} 
	}
	for(int i=1;i<=n;i++)
		cout<<d[i]-d[i-1]<<" "; 
	
	cout<<endl;
	for(int i=0;i<=n;i++)
		cout<<d[i]<<" ";
	cout<<endl;

}
