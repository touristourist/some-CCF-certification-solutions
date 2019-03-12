#include<bits/stdc++.h>
using namespace std;

//int a[1005];

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	int send=0,friends=0,a;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a);
		send+=a;
		if(send>=k)
		{
			friends++;
			send=0;
		}
		else 
			;
	}
	if(send>0) friends++;
	printf("%d",friends);
	
}
