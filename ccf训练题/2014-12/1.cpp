#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int number;
	int times[n];
	int result[n];
	for (int i=0;i<n;i++)
	{
		times[i]=0;
		result[i]=0;
	}
	
	for(int i=0;i<n;i++)
	{
		cin>>number;
		times[number-1]++;
		result[i]=times[number-1];
	}
	for(int i=0;i<n;i++)
		cout<<result[i]<<" ";
		
		
	return 0;
}
