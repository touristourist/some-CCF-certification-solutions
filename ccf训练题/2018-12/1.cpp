#include<iostream>
using namespace std;

int main()
{
	int r,y,g;
	cin>>r>>y>>g;
	int n;
	cin>>n;
	int sumtime=0;
	for(int i=0;i<n;i++)
	{
		int k,t;
		cin>>k>>t;
		if(k==0)
			sumtime+=t;
		else if(k==1)
		{
			sumtime+=t;
		} 
		else if(k==2)
		{
			sumtime+=(t+r);
		}
		else 
		{
			;
		}
		
	}
	
	cout<<sumtime;
	
	return 0;
	 
}
