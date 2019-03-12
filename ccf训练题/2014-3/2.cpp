#include<iostream>

using namespace std;

int main(){
	int n,m;
	cin>>n>>m; 
	int windows[n][5];
	int click[m][2];
	for (int i=n-1;i>=0;i--){
		for (int j=0;j<4;j++)
			cin>>windows[i][j];
		windows[i][4]=n-i;
	}
	for (int i=0;i<m;i++)
		cin>>click[i][0]>>click[i][1];
	for (int i=0;i<m;i++)
	{
		int judge=-1;
		int tem[5];
		for(int j=0;j<n;j++)
		{
			if (click[i][0]>=windows[j][0]&&click[i][0]<=windows[j][2]&&click[i][1]>=windows[j][1]&&click[i][1]<=windows[j][3])
			{
				judge=windows[j][4];
				for (int d=0;d<5;d++)
					tem[d]=windows[j][d];
				for(int k=j-1;k>=0;k--)
				for(int d=0;d<5;d++)
					windows[k+1][d]=windows[k][d];
				for (int d=0;d<5;d++)
					windows[0][d]=tem[d];
				break;
			}
		}
		if(judge==-1)
			cout<<"IGNORED"<<endl;
		else 
			cout<<judge<<endl; 
	}

}

//int main(){
//	int n,m;
//	cin>>n>>m;
//	
//	int windows[n][5];
//	int click[m][2];
//	for (int i=0;i<n;i++)
//	{
//		cin>>windows[i][0]>>windows[i][1]>>windows[i][2]>>windows[i][3];
//		windows[i][4]=i;
//	}
//		
//	for(int i=0;i<m;i++)
//		cin>>click[i][0]>>click[i][1];
//	for(int i=0;i<m;i++)
//	{
//		int istrue=-1;
//		int j;
//		for(j=0;j<n;j++)
//		{
//			if(click[i][0]>=windows[j][0]&&click[i][0]<=windows[j][2]&&click[i][1]>=windows[j][1]&&click[i][1]<=windows[j][3])
//			{
//				istrue=windows[j][4]+1;
//				int tem[5];
//				for(int m=0;m<5;m++)
//					tem[m]=windows[j][m];
//				for(int k=j;k<n-1;k++)
//				{
//					for(int m=0;m<5;m++)
//						windows[k][m]=windows[k+1][m];
//				}
//				for(int m=0;m<5;m++)
//					windows[n-1][m]=tem[m];
//			}
//				
//		}
//		if (istrue==-1)
//			cout<<"IGNORED"<<endl;
//		else 
//			cout<<istrue<<endl;
//	}	
//	return 0;
//}
