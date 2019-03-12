#include<iostream>

using namespace std;

int mat1[1002][1002];
int mat2[1002][1002];

int main(){
	int n,m;
	cin>>n>>m;
	
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
		cin>>mat1[i][j];
	
	
	for(int j=m-1;j>=0;j--)
	for(int i=0;i<n;i++)
		mat2[m-1-j][i]=mat1[i][j];
		
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
			cout<<mat2[i][j]<<" ";
		cout<<endl;
	}
	
	
//	for(int i=0;i<m;i++)
//	{
//		for(int j=0;j<n;j++)
//		mat2[i][j]=mat1[j][i];
//	}
//	
//	for(int i=m-1;i>=0;i--)
//	{
//		for(int j=0;j<n;j++)
//			cout<<mat2[i][j]<<" ";
//		cout<<endl;
//	}
	
	return 0;
}
