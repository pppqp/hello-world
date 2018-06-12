#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
using namespace std;
long t,m,v[100005],c[100005],f[100005];
int main()
{int i,j;
	freopen("madmed.in","r",stdin);
	cin>>t>>m;
	for(i=1;i<=m;i++)
	{
		cin>>c[i]>>v[i];
	}
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=t;j++)
		{if(j-c[i]>=0)
			f[j]=max(f[j-c[i]]+v[i],f[j]);
			
			//cout<<f[i][j]<<' ';
		}
	}
	cout<<f[t];
}

