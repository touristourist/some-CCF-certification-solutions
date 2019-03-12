#include<iostream>
using namespace std;

#define N 1000
int sell[N];
int dsell[N];
int z[N];

int main(){
	int n;
	cin>>n;
	int i,j,k,sum;
	i=j=k=sum=0;
	for(i=0;i<n;i++)
	{
		cin>>sell[i];
		if(i>0)
		{
			dsell[j]=sell[i]-sell[i-1]>0?1:-1;
			j++; 
		}
		if(j>1)
		{
			z[k]=dsell[j-1]-dsell[j-2];
			if(z[k]!=0&&j>0)
				sum++;
			k++;
		}
		
	}
	cout<<sum;
}
