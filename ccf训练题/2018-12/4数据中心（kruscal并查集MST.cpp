#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;

struct edge
{
	int u,v,cost;
};

bool cmp(const edge& e1,const edge& e2)
{
	return e1.cost<e2.cost;
}

int bin[50001];   //并查集 
edge es[100001];  //边 

//使用kruscal求最小生成树，再得到最后一条边即可 

int find(int x)//路径压缩查找 
{
	int r=x;
	while(r!=bin[r])
		r=bin[r];
	int i=x;
	while(i!=r)
	{
		int j=bin[i];
		bin[i]=r;
		i=j;
	}
	return r;
}

bool same(int x,int y)
{
	int fx=find(x);
	int fy=find(y);
	if(fx==fy)	
		return true;
	else 	
		return false;
}


//注意是将x所在树和y所在树合并！！！！！！ 
void merge(int x,int y)
{
	int fx=find(x);
	int fy=find(y);
//	if(fx==fy)  
//		return;
	if(fx!=fy)
		bin[fx]=fy;
}

int main()
{
	int n,m,root;
	cin>>n>>m>>root;
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d",&(es[i].u),&(es[i].v),&(es[i].cost));
	}
	sort(es,es+m,cmp);
	for(int i=1;i<=n;i++)  //初始化并查集 
		bin[i]=i;
		
	int laste;
	for(int i=0;i<m;i++)
	{
		if(!same(es[i].u,es[i].v))
		{
			merge(es[i].u,es[i].v);
			laste=es[i].cost;
		//	cout<<"last "<<laste<<" "<<es[i].u<<" "<<es[i].v<<endl;
		}
	}
	
//	printf("\n");
//	for(int i=1;i<=n;i++)
//		printf("%d ",bin[i]);
	
	cout<<laste;
}
