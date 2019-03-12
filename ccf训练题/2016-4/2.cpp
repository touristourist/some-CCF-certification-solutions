#include<iostream>
#include<string.h>
using namespace std;

int window[15][10];
int pic[4][4];

int main(){
	for(int i=0;i<15;i++)
	for(int j=0;j<10;j++)
		cin>>window[i][j];
	for(int i=0;i<4;i++)
	for(int j=0;j<4;j++)
	 cin>>pic[i][j];
	int left;
	cin>>left;
	int bottom[4]; //记录板块中每列的最底行数
	memset(bottom,-1,sizeof(bottom)); 
	int record[4][4];
	memset(record,-1,sizeof(record));
	for(int i=3;i>=0;i--)
	for(int j=0;j<=3;j++)
	{
		if(pic[i][j]==1)
		{
			bottom[j]=i;
			break;
		}
	}
	int minmove=100,bkmove=100;  //minmove表示板块的最少移动块数 
	for(int i=0;i<4;i++)
	{
		if(bottom[i]!=-1)
		{
			int isempty=true;
			for(int j=0;j<15;j++)
			{
				if(window[j][left-1+i]==1)
				{
					if(minmove>(j+(3-bottom[i])))
					{
						minmove=(j+(3-bottom[i]));
						bkmove=j;
					}
					isempty=false;
					break;
				}
			}
			if(isempty==true)
			{
				if(minmove>(15+(3-bottom[i])))
				{
					minmove=(15+(3-bottom[i]));
					bkmove=15;
				}
				
			}
		}
	}
	for(int j=0;j<4;j++)
	for(int i=3;i>=0;i--)
	{
		if(pic[i][j]==1)
		{
			window[bkmove-1-(3-i)][left-1+j]=1;
		}
	}
	
	for(int i=0;i<15;i++)
	{
		for(int j=0;j<10;j++)
		{
			cout<<window[i][j]<<" ";
		}
		cout<<endl;
	}
	
		
	
}
