#include<iostream>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int number=0;
	int array[n];
	for (int i=0;i<n;i++)
	{
		cin>>array[i];
		for(int j=0;j<i;j++)
		{
			if (array[i]==(-array[j]))
			number++;
		}
	}
	cout<<number;
	return 0;
}
