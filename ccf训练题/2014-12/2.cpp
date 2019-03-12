#include<iostream>

using namespace std;

#define R 1 //�һ����� 
#define D 2
#define LD 3
#define RU 4

int main(){
	int n;
	cin>>n;
	int mat[n][n];
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
		cin>>mat[i][j];
	int y=0,x=0;
	int state=R;
	while(y!=n-1||x!=n-1)
	{
		
		switch(state)
		{
			case R:
				if(x+1<n){
					cout<<mat[y][x]<<" ";
					x+=1;
					if(y+1<=n-1)
						state=LD;
					else
						state=RU;
				}	
				else{
					state=D;
				} 	
				break;
			case LD:
				if (x-1>=0&&y+1<=n-1)
				{
					cout<<mat[y][x]<<" ";
					x=x-1; y=y+1;
				}
				else //����״̬ת��ʱ���ƶ���ֻ��״̬ 
				{
					if(y+1>n-1)
						state=R;
					else
						state=D; 
				}
				break;
			case D:
				if(y+1<=n-1)
				{
					cout<<mat[y][x]<<" ";
					y=y+1;
					if(x+1<=n-1&&y-1>=0)
						state=RU;
					else 
						state=LD;
				}
				else 
					state=R;
				break;
			case RU:
				if(x+1<=n-1&&y-1>=0)
				{
					cout<<mat[y][x]<<" ";
					x=x+1; y=y-1;
				}
				else
				{
					if(x+1<=n-1)
						state=R;
					else 
						state=D;
				}
				break;			
		}
	}
	cout<<mat[y][x]<<" ";
	return 0;
	
}


