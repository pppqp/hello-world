#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
using namespace std;
long t,m,v[3005],c[3005],f[1000][3005];
int main()
{int i,j;
	freopen("med.in","r",stdin);
	cin>>t>>m;
	for(i=1;i<=m;i++)
	{
		cin>>c[i]>>v[i];
	}
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=t;j++)
		{if(j-c[i]>=0)
		
			f[i][j]=max(f[i-1][j-c[i]]+v[i],f[i-1][j]);
			else
			f[i][j]=f[i-1][j];
			//cout<<f[i][j]<<' ';
		}
	}
	cout<<f[m][t];
}

