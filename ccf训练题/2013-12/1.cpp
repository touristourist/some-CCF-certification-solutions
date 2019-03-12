#include<stdio.h>
#include<iostream>

using namespace std;

int constnum[10001];

int main()
{
	int n;
	int getnum; 
	int maxtimes=0;
	cin>>n;
	int intarr[n];
	for (int i=0;i<10001;i++)
		constnum[i]=0;
	for(int i=0;i<n;i++)
	{
		cin>>getnum;
		constnum[getnum]++;
		if (constnum[getnum]>maxtimes)
			maxtimes=constnum[getnum];
	}
	for (int i=1;i<10001;i++)
		if(maxtimes==constnum[i])
		{
			cout<<i;
			return 0;
		}
			
}

