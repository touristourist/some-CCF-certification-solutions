#include<iostream>
using namespace std;

int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int rmonth[12]={31,29,31,30,31,30,31,31,30,31,30,31};

bool judge(int);

int main()
{
	int mon,day;
	int y,d;
	cin>>y>>d;
	int monsum=0;
	if(judge(y)){
		for(int i=0;i<12;i++)
		{
			monsum+=rmonth[i];
			if(d<=monsum){
				mon=i+1;
				monsum-=rmonth[i];
				day=d-monsum;
				break;
			}
		}
	}
	else{
		for(int i=0;i<12;i++)
		{
			monsum+=month[i];
			if(d<=monsum){
				mon=i+1;
				monsum-=month[i];
				day=d-monsum;
				break;
			}
		}
	}
	
	cout<<mon<<endl<<day;
}
//ÅÐ¶ÏÊÇ·ñÊÇÈòÄê 
bool judge(int y){
	if((y%4==0&&y%100!=0)||y%400==0)
		return true;
	else 
		return false;
} 
