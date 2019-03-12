#include<iostream>
using namespace std;

int chess[30][30];
int result[30][30];

int main()
{
	int n,m;
	cin>>n>>m;
	for (int i=0;i<n;i++)
	for (int j=0;j<m;j++)
		cin>>chess[i][j];
	for(int i=0;i<n;i++)
	for (int j=0;j<m;j++)
		result[i][j]=-1;	
		
	for(int i=0;i<n;i++)
	{
		for(int j=2;j<m;j++)
		{
			if(chess[i][j-2]==chess[i][j-1]&&chess[i][j-1]==chess[i][j])
			{
				result[i][j-2]=result[i][j-1]=result[i][j]=0;
			}
			else
			{
				for(int m=0;m<3;m++)
				{
					if(result[i][j-m]!=0)
					{
						result[i][j-m]=chess[i][j-m];
					}
				}
			
			}
		}	
	}
	
	for(int j=0;j<m;j++)
	for(int i=2;i<n;i++)  //for(int i=0;i<n;i++)就不对了，因为会数组溢出 
	{
		if(chess[i-2][j]==chess[i-1][j]&&chess[i-1][j]==chess[i][j])
			{
				result[i-2][j]=result[i-1][j]=result[i][j]=0;
			}
			else
			{
				for(int m=0;m<3;m++)
				{
					if(result[i-m][j]!=0)
					{
						result[i-m][j]=chess[i-m][j];
					}
				}
			
			}
	}
	
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
			cout<<result[i][j]<<" ";
		cout<<endl; 
	}

	
	
	
	return 0;
}
