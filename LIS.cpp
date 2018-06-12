#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include <fstream> 
using namespace std;
int lon[100]={0},a[100],n,maxn,link[100];
//int f[100];
int main()
{int i,j;
	freopen("up.in","r",stdin);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		//f[i]=1;
	}
	maxn=1;
	lon[1]=a[1];
	for(i=2;i<=n;i++)
	{	int maxm=0;
	
		if (a[lon[maxn]]<a[i])
		{
			maxn++;
			lon[maxn]=i;
			link[i]=lon[maxn-1];
			//cout<<a[lon[maxn]]<<'\n';
			continue;
			
		}
		for(j=maxn;j>=1;j--)
		{
			
			if(a[lon[j]]<a[i])//j是一个长度 
			{ maxm=j;
				break;//maxm为最大长度 
			}
		}
		if(a[i]<a[lon[maxm+1]])
		{	lon[maxm+1]=i;
			link[i]=lon[maxm];
		}
		maxn=max(maxn,maxm+1);
		
	}
	//cout<<a[lon[4]]<<' '<<'\n';
	for(i=1;i<=100;i++)
	{
		if(lon[i]!=0)
		maxn=max(maxn,i);
	}
	cout<<a[lon[maxn]]<<' ';
	i=lon[maxn];
	while(link[i]!=0)
	{
		cout<<a[link[i]]<<' ';
		i=link[i];
	}
}
