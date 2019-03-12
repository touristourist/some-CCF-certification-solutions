#include<iostream>
#include<stdlib.h>

using namespace std;

int main(){
	string s;
	cin>>s;
	char str[20];
	int dcount=0;
	for(int i=0;i<s.length()-1;i++)
	{
		if(s[i]!='-')
		{
			str[dcount]=s[i];
			dcount++;
		}
	}
	str[9]='\0';
	int sum=0;
	for(int i=0;i<9;i++)
		sum+=(i+1)*(str[i]-'0');
	int result=sum%11;
	char c; 
	if(result==10)
		c='X';
	else 
		c=result+'0';
		
	if(c==s[s.length()-1])
		cout<<"Right";
	else 
	{
		s[s.length()-1]=c;
		cout<<s;
	}
	
}


itoa()
//int main()
//{
//	char tempstr[20];
//	char str[20];
//	
//	cin>>tempstr;
//	int dcount=0;
//	for(int i=0;i<12;i++)
//	{
//		if (tempstr[i]!='-')
//		{
//			str[dcount]=tempstr[i];
//			dcount++;
//		}
//	}
//	int sum=0;
//	int n;
//	for(int i=0;i<9;i++)
//	{
//		n=atoi(str+i);
//		sum+=n*(i+1);
//	}
//	int result=sum%11; 
//	if(result==10)
//	{
//		if(tempstr[12]=='X')
//			cout<<"Right"<<endl;
//		else 
//		{
//			tempstr[12]='X';
//			cout<<tempstr;
//		}
//			
//		return 0;
//	}
//	else 
//	{
//		if(atoi(tempstr+12)==result)
//			cout<<"Right";
//		else 
//		{
//			tempstr[12]='0'+result;
//			cout<<tempstr;
//		}
//		return 0;
//	}
//	
//	
//	
//}
