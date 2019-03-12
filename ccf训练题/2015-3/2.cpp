#include<iostream>
using namespace std;

int times[1001][2];

int main()
{
	int n;
	cin>>n;
	int getnum;
	for (int i=0;i<1001;i++)
	{
		times[i][0]=i;
		times[i][1]=0;
	}
		
	for (int i=0;i<n;i++)
	{
		cin>>getnum;
		times[getnum][1]++;
//				cout<<"sa";
	}
	
	for (int i=999;i>=0;i--)
	for (int j=1;j<=i;j++)
	{
		if(times[j][1]<times[j+1][1])
		{
			int temp0=times[j][0];
			int temp1=times[j][1];
			times[j][0]=times[j+1][0];
			times[j][1]=times[j+1][1];
			times[j+1][0]=temp0;
			times[j+1][1]=temp1;
		}
	}
	
	int c=1;
	while(times[c][1]!=0)
	{
		cout<<times[c][0]<<" "<<times[c][1]<<endl;
		c++;
		
//		cout<<"sa";
	}
	
	return 0;
}
