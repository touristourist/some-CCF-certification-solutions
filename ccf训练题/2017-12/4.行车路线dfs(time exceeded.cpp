#include<bits/stdc++.h>
using namespace std;

struct edge{
	int to,cost,type;
	edge(int t,int c,int ty):to(t),cost(c),type(ty) {}
};

vector<vector<edge> > graph(505);


bool visit[505];
int pathlen[505];
long long finalen=10000000;
int n,m;

void dfs(int node,int base,int conti)
{
	long long curlen=(long long)(base+conti*conti);
	if(node==n)
		if(curlen<finalen)
		{
			finalen=curlen;
//			visit[n]=false;
			return;
		}
		
	for(int k=0;k<graph[node].size();k++)
	{
		int to=graph[node][k].to;
		int cost=graph[node][k].cost;
		int type=graph[node][k].type;
		if(!visit[to]&&curlen<finalen)
		{
			visit[to]=true;
			if(type==1)
			{
				dfs(to,base,conti+cost);
			}
			else if(type==0)
			{
				dfs(to,curlen+cost,0);
			} 
			visit[to]=false;
		}
	}
		

}	


int main()
{
	memset(visit,0,sizeof(visit));
	memset(pathlen,0,sizeof(pathlen));
	
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int t,a,b,c;
		scanf("%d%d%d%d",&t,&a,&b,&c);
		graph[a].push_back(edge(b,c,t));
		graph[b].push_back(edge(a,c,t));
	}
	dfs(1,0,0);
	cout<<finalen;
}
