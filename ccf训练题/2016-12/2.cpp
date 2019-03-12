#include<iostream>

using namespace std;

int getaftax(int );

#define base 3500
double rate[7]={0.03,0.10,0.20,0.25,0.30,0.35,0.45};
int bound[]={0,1500,4500,9000,35000,55000,80000,100001};
int dur[]={1500,3000,4500,26000,20000,25000};

int main (){
	int n;
	cin>>n;

	for(int i=n;i<100001;i+=1)
		if(getaftax(i)==n)
		{
			cout<<i;
			return 0;
		}	
		
//	cout<<getaftax(10000)<<endl;
}

int getaftax(int S)
{
	int A=S-3500;
	int outbase=0;
	if(A<=0)
		return S;
	else
	{
		int i=0;
		for(i=0;i<8;i++)
			if(A<bound[i])
				break;
		int over=A-bound[i-1];
		for(int j=0;j<=i-2;j++)
		{
			outbase=outbase+dur[j]*(1-rate[j]);
//			cout<<dur[j]*(1-rate[j])<<" "<<outbase<<endl;
		}
		outbase+=over*(1-rate[i-1]);
//		cout<<over*(1-rate[i-1])<<endl;
//		cout<<outbase<<" "<<base<<endl;
	
		return outbase+base;
	}
	
} 
