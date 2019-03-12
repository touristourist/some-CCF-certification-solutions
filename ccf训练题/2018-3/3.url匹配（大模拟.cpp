#include<bits/stdc++.h>
using namespace std;


vector<pair<string,string> > orirule;
//vector<string> orimat;
//split之后的字符串 
vector<pair<vector<string>,string> > rule;
//vector<vector<string> > vsmatch;
// vsmatch;


vector<string> split(string s)
{
	vector<string> v;
	int begin=0,len=0;
	bool hascut=false;
	string st="";
	for(int i=0;i<s.length();i++)
	{	
		if(i==0&&s[i]=='/')
			 ;
		else if(s[i]!='/')
		{
			if(hascut==false)
			{
				hascut=true;
				begin=i;
			}
		}
		else if(i>0&&s[i]=='/')
		{
			if(hascut==true)
			{
				len=i-begin;
				st=s.substr(begin,len);
				v.push_back(st);
				hascut=false;
			}
		}
	}
	if(hascut==true)
	{
		st=s.substr(begin,s.length()-begin);
		v.push_back(st);
	}
	return v;
}

bool judgeint(string s)
{
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>'9'||s[i]<'0')
			return false;
	}
	return true;
}

string outint(string s)
{
	string st;
	int start=true,beginpos;
	for(int i=0;i<s.length();i++)
	{
		if(start==true&&s[i]!='0')
		{
			start=false;
			beginpos=i;
			break;
		}	
	}
	st=s.substr(beginpos,s.length()-beginpos);
	return st; 
}

void outpath(vector<string> mt,int k)
{
	for(int i=k;i<mt.size();i++)
	{
		if(i!=k)	cout<<"/"; 
		cout<<mt[i];
	}
}

bool judgestr(string s)
{
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='/')
			return false;
	}
	return true;
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	string st1,st2;
	for(int i=0;i<n;i++)
	{
		cin>>st1>>st2;
		orirule.push_back(make_pair(st1,st2));
		vector<string> vs1=split(st1);
		rule.push_back(make_pair(vs1,st2));
	}
	for(int c=0;c<m;c++)
	{
		cin>>st1;
		string orimat=st1;
		vector<string> vsmatch=split(st1);
//		match.push_back(vsmatch);
		
		
		int judge;
		for(int i=0;i<n;i++)
		{
			judge=true;
			int count=0,j=0;
			for(j=0;j<rule[i].first.size();j++)
			{
				if(count>=vsmatch.size())  //match比rule短 
				{
					judge=false;
					break;
				}
				
//				cout<<" ~"<<rule[i].first[j]<<"~ "; 
				
				if(rule[i].first[j]=="<int>")
				{
					if(!judgeint(vsmatch[count]))
					{
						judge=false;
						break;
					}
						
				}
				else if(rule[i].first[j]=="<str>")
				{
					; 
				}
				else if(rule[i].first[j]=="<path>")
				{
					count=vsmatch.size();
					//检查最后一位不会以/结尾
					if(orimat[orimat.length()-1]=='/') 
					{
						judge=false;
						
					}
					break;
				}
				else  //全字匹配 
				{
					if(vsmatch[count]!=rule[i].first[j])
					{
						judge=false;
						break;
					}
				}
				
				count++;
			}
			if(j==rule[i].first.size()&&count<vsmatch.size())  //match比rule长 
				judge=false;
			
			if(judge==true)
			{
				cout<<rule[i].second<<" ";
				for(int k=0;k<rule[i].first.size();k++)
				{
					if(rule[i].first[k]=="<int>")
					{
						cout<<" "<<outint(vsmatch[k]);
					}
					else if(rule[i].first[k]=="<str>")
					{
						cout<<" "<<vsmatch[k];
					}
					else if(rule[i].first[k]=="<path>")
					{
						cout<<" ";
						outpath(vsmatch,k);
						break;
					}
				}
				cout<<endl;
				break;
			}
			
		} 
		if(judge==false)
			cout<<"404"<<endl;
		

	}
	

	
}
