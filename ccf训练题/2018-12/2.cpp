#include<iostream>
using namespace std;

//n ����ֵ�ܴ�������ɳ����е�nowtimeһ������Ӵ�����Ҫ��long long�洢 

int main()
{
	int red,yellow,green;
	cin>>red>>yellow>>green;
	int n;
	cin>>n;
	long long nowtime=0;
	int k;
	int t;
	int total=red+yellow+green;
	for(int i=0;i<n;i++)
	{
		cin>>k>>t;
		if(k==0)
			nowtime+=t;
		else
		{
			int res,time;
			if(k==1)
			{
				time=red-t;
				res=(time+nowtime)%total;
			}
			else if(k==2)
			{
				time=red+green+(yellow-t);
				res=(time+nowtime)%total;
			}
			else if(k==3)
			{
				time=red+(green-t);
				res=(time+nowtime)%total;
			}
			
			if(res>=0&&res<=red)
			{
				nowtime+=red-res;
			}
			else if(res>red&&res<=red+green)
			{
				;
			}
			else if(res>red+green&&res<total)
			{
				nowtime+=total-res+red;
			}
		} 
	}
	cout<<nowtime;
} 
