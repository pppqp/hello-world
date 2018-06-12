#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
using namespace std;
int a[26][30003],n,m,v[26],p[26],w[26];
int main()
{int i,j;
	freopen("pack.in","r",stdin);
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		cin>>v[i]>>p[i];
		w[i]=v[i]*p[i];
	}
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(v[i]<=j)
			a[i][j]=max(a[i-1][j-v[i]]+w[i],a[i-1][j]);
			else a[i][j]=a[i-1][j];
			
		}
	}
	cout<<a[m][n];
}
