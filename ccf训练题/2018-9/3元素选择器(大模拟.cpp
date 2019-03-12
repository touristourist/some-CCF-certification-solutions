#include<bits/stdc++.h>
using namespace std;

class element{
	public:
		int line; //�������� 
		int father;//���ڵ����� 
		int level; //���м��� 
		string tag;
		string id;  //��ǩ��id 
};


vector<element> elements(102); //��ʼ��Ԥ�ȴ��� 
vector<vector<int> > spring(102);   //spring[i][.]��ʾ��i�е������Ӵ� 

int judgelevel(string s)  //html��0�� 
{
	int dotnum=0;
	for(auto &w:s)
	{
		if(w=='.')
			dotnum++;
	}
	return dotnum/2;	
}
void setTagId(string str,string &tag,string &id)
{
	bool tagst=false,cuttag=false;
	int begin=0;
	int strlen=str.length();
	for(int i=0;i<strlen;i++)
	{
		if(tagst==false&&str[i]!='.')
		{
			tagst=true;
			begin=i;
		}
		else if(tagst==true&&str[i]==' ')
		{
			tag=str.substr(begin,i-begin);
			cuttag=true;
		}
		else if(cuttag==true&&str[i-1]==' ')
		{
			id=str.substr(i,strlen-i);
			break;
		}
	}
	
	if(cuttag==false) 
	{
		tag=str.substr(begin,strlen-begin);
		id="";
	}
	 
}

int getfather(int le)
{	
	if(le==1)  //���ڵ�һ�е�father 
		return -1;
	
	int nowlevel=elements[le].level;
	for(int i=le-1;i>0;i--)
	{
		if(elements[i].level==nowlevel-1)  //���������ҵ���һ�������ϼ� 
		{
			spring[i].push_back(le);
			return i;  //���ظ��׵����� 
		}
			
	}
}

int main()
{
//	freopen("a.txt","r",stdin);
	
	int n,m;
	scanf("%d %d",&n,&m);
	string nu;
	getline(cin,nu);   //getline���������з����˴�������һ��ʣ�µĻ��з� 
	for(int i=1;i<=n;i++)
	{
		string str;
		getline(cin,str);
//		cout<<str<<endl;
		elements[i].line=i;
		elements[i].level=judgelevel(str);
		setTagId(str,elements[i].tag,elements[i].id);
		elements[i].father=getfather(i);
	}
	
	
//	for(int i=1;i<=n;i++)
//		cout<<elements[i].tag<<elements[i].id<<endl;
//	
//	string s1,s2;
//	setTagId("..headssssssss",s1,s2);
//	cout<<s1<<"."<<s2<<endl;	


//	for(int i=1;i<=n;i++)
//	{
//		cout<<i<<".       ";
//		for(int j=0;j<spring[i].size();j++)
//			cout<<spring[i][j]<<" ";
//		cout<<"~"<<spring[i].size()<<endl;
//		
//	}
//	

	
	for(int i=0;i<m;i++)
	{
		string instr="";
		getline(cin,instr);
		istringstream line(instr);
		string chostr;
		
//		list<int> relist;
		vector<int> result;
		
		bool first=true;
		while(line>>chostr)
		{
//			cout<<chostr<<endl;
			
			if(chostr[0]=='#')
			{
				if(first==true)
				{
					for(int dd=1;dd<=n;dd++)
						if(elements[dd].id==chostr)
							result.push_back(dd);
					first=false;
				}
				else
				{
					vector<int> temp;
					int len=result.size();
					for(int vv=0;vv<len;vv++)
					{
						int r=result[vv];
						for(int kk=0;kk<spring[r].size();kk++)
						{
							int kkp=spring[r][kk];
							if(elements[kkp].id==chostr)
								temp.push_back(kkp);
						}
					}
					result=temp;
				}
			}
			else  //tag 
			{
				if(first==true)
				{
					for(int dd=1;dd<=n;dd++)
						if(elements[dd].tag==chostr)
							 result.push_back(dd);
					first=false; 
				}
				else 
				{
					vector<int> temp;
					int len=result.size();
					for(int vv=0;vv<len;vv++)
					{
						int r=result[vv];
						
						for(int kk=0;kk<spring[r].size();kk++) //�±��0��ʼ���� 
						{
							int kkp=spring[r][kk];
							if(elements[kkp].tag==chostr)
								temp.push_back(kkp);
						}
							
					}
					result=temp;
				}
			}
			
			if(result.size()<=0)
			{
				cout<<0<<endl;
				break;
			}		
		}
		if(result.size()>0)
		{
			cout<<result.size();
			for(int c=0;c<result.size();c++)
				cout<<" "<<result[c];
			cout<<endl;
		}
	}
	
//	fclose(stdin);
} 
