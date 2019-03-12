#include<iostream>
using namespace std;

int abs(int );

int main(){
	int n;
	cin>>n;
	int price[n];
	for(int i=0;i<n;i++)
		cin>>price[i];
	int max=-1;	
	for(int i=1;i<n;i++)
	{
		int sub=abs(price[i]-price[i-1]);
		if(sub>max)
			max=sub;
	} 
	
	cout<<max;
}

int abs(int x){
	if(x<0)
		return -x;
	else 
		return x;
}
