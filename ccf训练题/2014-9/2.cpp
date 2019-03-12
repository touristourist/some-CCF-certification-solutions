#include<iostream>

using namespace std;

int main(){
	int area[100][100];
	for(int i=0;i<100;i++)
	for(int j=0;j<100;j++)
		area[i][j]=0;
	int n;
	cin>>n;
	int rect[n][4];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<4;j++)
		{
			cin>>rect[i][j];
		}
		for(int y=rect[i][0];y<rect[i][2];y++)
		for(int x=rect[i][1];x<rect[i][3];x++)
			area[y][x]=1;
	}
	int sum=0;
	for(int i=0;i<100;i++)
	for(int j=0;j<100;j++)
	if(area[i][j]==1)
		sum++;
		
	cout<<sum;
	
		
	
	
}
