#include<iostream>

using namespace std;

int main(){
	int n;
	cin>>n;
	int array[n];
	for(int i=0;i<n;i++)
		cin>>array[i];
	int totalnum=0;
	for(int i=0;i<n;i++)
	for(int j=i+1;j<n;j++)
	{
		if(array[i]-array[j]==1||array[i]-array[j]==-1)
			totalnum++;
	}
	cout<<totalnum;
	
	return 0;
} 
