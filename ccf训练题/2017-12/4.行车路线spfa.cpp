#include<bits/stdc++.h>
using namespace std;


class edge{
	public: 
	int to,cost,type;  //cost表示这段路的总疲劳度 
	edge(int t,int c,int ty) 
	{
		to=t; 
		cost=c;
		type=ty;
		
	}
};

struct vertex{
	int base,conti,num;
	vertex(int b,int c,int n):base(b),conti(c),num(n) {}
};

#define INF 10000000
typedef long long ll;
typedef pair<int,int> ptag; //first标记到该点是否是由小路得来 

vector<vector<edge> > graph(505);

bool inq[505];
ll d[505]; 

int father[505];


int main()
{
	freopen("a.txt","r",stdin);
	
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int t,a,b,c;
		cin>>t>>a>>b>>c;
		graph[a].push_back(edge(b,c,t));
		graph[b].push_back(edge(a,c,t));
	}
	for(int i=1;i<=n;i++)
		d[i]=INF;
	memset(inq,0,sizeof(inq));
	d[1]=0;
	inq[1]=true;
	queue<vertex> Q;
	Q.push(vertex(0,0,1));
	while(!Q.empty())
	{
		vertex frontpair=Q.front();
		int node=frontpair.num;
		int conti=frontpair.conti;
		int base=frontpair.base;
		Q.pop();
		inq[node]=false;
		for(int k=0;k<graph[node].size();k++)
		{
			
			int cmpcost;
			int to=graph[node][k].to;
			int cost=graph[node][k].cost;
			int type=graph[node][k].type;
			if(type==1)
			{
				if(conti>0)
				{
					int dd=(cost+conti)*(cost+conti);
					if(base+dd<d[to])
					{
						d[to]=base+dd;
						if(!inq[to])
						{
							inq[to]=true;
							Q.push(vertex(base,cost+conti,to));
							father[to]=node;
						}
					}
					
					
				}
				else if(conti==0)
				{
					if(base+cost*cost<d[to])
					{
						d[to]=base+cost*cost;
						if(!inq[to])
						{
							inq[to]=true;
							Q.push(vertex(base,cost,to));
							father[to]=node;
						}
					}
					
				}
					
			}
			else if(type==0)
			{
				if(conti>0)
				{
					int dd=base+conti*conti;
					if(dd+cost<d[to])
					{
						d[to]=dd+cost;
						if(!inq[to])
						{
							inq[to]=true;
							Q.push(vertex(dd+cost,0,to));
							father[to]=node;
						}
					}
					
				}
				else if(conti==0)
				{
					if(base+cost<d[to])
					{
						d[to]=base+cost;
						if(!inq[to])
						{
							inq[to]=true;
							Q.push(vertex(base+cost,0,to));
							father[to]=node;
						}
					}
				
				}
			}
			

		}
	}

	
	for(auto dd:d)
		cout<<dd<<" ";
	cout<<endl;
	for(int i=0;i<10;i++)
		cout<<father[i]<<" ";
//	cout<<d[n]<<endl;
} 
