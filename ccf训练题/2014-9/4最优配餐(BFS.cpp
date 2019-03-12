#include<bits/stdc++.h>

using namespace std;


//��ͼ�в���Ҫ��¼�̼ҵ�λ�ã�ֱ�ӽ��̼ҵ�λ��ѹ������У��Ͳ�����grid[][]�������̼ң��û����ϰ� 

class Point{
	public:   
		int x,y,cost;    //�õ������Լ������̼��е��õ����̾��� 
		Point(int xx=0,int yy=0,int ccost=0):x(xx),y(yy),cost(ccost) {}
};

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int grid[1002][1002];  //grid�У�-1�����ϰ���0������ߵ�·��>0��ʾ�ͻ������� 
//int shortlen[1002][1002];  shortlen�п����кܶ�հף�������point�м�cost���� 
bool shortfind[1002][1002]; //��¼�õ��Ƿ����ҵ����·�� 

int main()
{
	memset(grid,0,sizeof(grid));
	memset(shortfind,0,sizeof(shortfind));
	
	int n,m,k,d;
	scanf("%d %d %d %d",&n,&m,&k,&d);
	queue<Point> Q;
	for(int i=0;i<m;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		Point shopp(x,y,0);
		Q.push(shopp);
		shortfind[x][y]=true;
	}
	for(int i=0;i<k;i++)
	{
		int x,y,num;
		scanf("%d %d %d",&x,&y,&num);
		grid[x][y]+=num;
	}
	for(int i=0;i<d;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		grid[x][y]=-1;
	}
	
	long long res=0;   //���--------��Ϊ���ֺܴ� 
	
	while(!Q.empty())
	{
		Point tempP=Q.front();
		Q.pop();
		int x=tempP.x,y=tempP.y,c=tempP.cost;
		if(grid[x][y]>0)
			res+=(long long)grid[x][y]*c;
		
		int xx,yy,cc;
		for(int i=0;i<4;i++)   //�ĸ����� 
		{
			xx=tempP.x+dx[i];
			yy=tempP.y+dy[i];
			cc=tempP.cost+1;
			if(xx>0&&xx<=n&&yy>0&&yy<=n&&!shortfind[xx][yy]&&grid[xx][yy]>=0)
			{
				Q.push(Point(xx,yy,cc));
				shortfind[xx][yy]=true;
//				res+=(long long)grid[xx][yy]*(cc);
			}
				
		}
		
	}
	
	printf("%lld",res);
}
