#include<iostream>
#include<algorithm>
using namespace std;

int array[1000];

int main(){
	int n;
	cin>>n;
	
	for (int i=0;i<n;i++)
		cin>>array[i];
	for(int i=n-2;i>=0;i--)
//	for(int j=0;j<=i;j++)
//	{
//		if(array[j]>array[j+1])
//		{
//			int temp=array[j];
//			array[j]=array[j+1];
//			array[j+1]=temp;
//		}
//	}
	sort(array,array+n);
	
	
	int start,end;
	start=end=0;
	int mid=n/2;
	//�˴���˼·���ҵ���һ����ͬ�ľ�break����Ҳ�п���һֱ�Ҳ��� 
//	for(int i=0;i<=mid;i++)
//	{
//		if(array[mid-i]!=array[mid])
//		{
//			start=mid-i+1;
//			break;
//		}
//	}
//	for(int i=mid;i<n;i++)
//	{
//		if(array[i]!=array[mid])
//		{
//			end=i-1;
//			break;
//		}
//	}
	//�޸ĺ�˴����һֱ��ȣ�start��end��ֵҲ��仯 
	for(int i=0;i<=mid;i++)
	{
		if(array[mid-i]==array[mid])
		{
			start=mid-i;
		}
		else
			break; 
	}
	for(int i=mid;i<n;i++)
	{
		if(array[i]==array[mid])
		{
			end=i;
		}
		else 
			break;
	}
	
	if(start==(n-end-1))
	{
		cout<<array[mid];
	}
	else 
		cout<<-1;
	return 0;	
}
