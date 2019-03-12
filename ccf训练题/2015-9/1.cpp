#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int array[n];
	for(int i=0;i<n;i++)
		cin>>array[i];
	int segments=1;
	int last=array[0];
	for(int i=1;i<n;i++)
	{
		if(array[i]!=last)
		{
			segments++;
			last=array[i];
		}
	}
	
	cout<<segments;
	
	return 0;
}
