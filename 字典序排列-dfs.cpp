#include<iostream>
#include<cmath>
using namespace std;
int n,a[1000],used[1000]={0};
void print();
void dfs(int);

int main()
{
	cin>>n;
	
	dfs(1);
	
}

void dfs(int step)
{
	if(step>n)
	{
		print ();
		return;
	}
	int i;
	for(i=1;i<=n;i++)
	{
		if(used[i]==0)
		{
			a[step]=i;
			used[i]=1;
			dfs(step+1);
			used[i]=0;
		}
		
		
		
	}
	
}
void print()
{
	for(int i=1;i<=n;i++)
	{
	cout<<a[i];
	}
	cout<<'\n';
}

