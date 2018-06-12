#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
using namespace std;
int a[100+1],f[100+1],cou,lon;
int main()
{
	int i,j,n=1;
	//freopen("missile.in","r",stdin);
	while(scanf("%d",&a[n])!=EOF)
	n++;
	for(i=1;i<=n;i++)
	{
		f[i]=1;
	}
	for(i=1;i<n;i++)
	{
		for(j=1;j<i;j++)
		{
			if(a[i]<=a[j]&&f[i]<f[j]+1)
			f[i]=f[j]+1;
		}
	}
	for(i=1;i<=n;i++)
	{
		lon=max(lon,f[i]);
	}
	cout<<lon<<'\n';
	for(i=1;i<=n;i++)
	{
		f[i]=1;
	}
	
	for(i=1;i<n;i++)
	{
		for(j=1;j<i;j++)
		{
			if(a[i]>=a[j]&&f[i]<f[j]+1)
			f[i]=f[j]+1;
		}
	}
	for(i=1;i<=n;i++)
	{
		cou=max(cou,f[i]);
	}
	cout<<cou;
}
