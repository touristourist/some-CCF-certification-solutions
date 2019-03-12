#include<iostream>
#include<string.h>

using namespace std;

int seat[20][5];

void print(int,int);

int main(){
	memset(seat,0,sizeof(seat));
	
	int n;
	cin>>n;
	int ticket;
	for(int i=0;i<n;i++){
		cin>>ticket;
		int contig=false;
		int havbuy=false;
		for(int r=0;r<20&&havbuy==false;r++)
		{
			for(int c=ticket-1;c<5&&havbuy==false;c++)
			{
				int judge1=true;
				for(int j=0;j<ticket&&judge1==true;j++)
				{
					if(seat[r][c-j]!=0)
						judge1=false;
				}
				if(judge1==true)
				{
					for(int j=ticket-1;j>=0;j--)
						print(r,c-j);
					cout<<endl;
					contig=true;
					havbuy=true;
				}
			}
		}
		if(contig==false)
		{
			int times=ticket;
			for(int u=0;u<20;u++)
			for(int v=0;v<5;v++)
			{
				if(seat[u][v]==0&&times>0)
				{
					print(u,v);
					times--;
				} 
			}
			cout<<endl;
		}
		
	}
		
}

void print(int r,int c){
	seat[r][c]=1;
	cout<<r*5+c+1<<" ";
}
