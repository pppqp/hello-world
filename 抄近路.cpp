#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int dx[1000],dy[1000],f[1000],x,y,n,maxn=0;
int main()
	{int i,j;
	freopen("shortline.in","r",stdin);
		cin>>x>>y>>n; 
		for(i=1;i<=n;i++)
		{
			cin>>dx[i]>>dy[i];
			for(j=i;j>=2;j--)
			{
				if(dx[j]<dx[j-1])
				{
				swap(dx[j],dx[j-1]);//第一次大括号没写…… 
				swap(dy[j],dy[j-1]);
				}
			}
		}
			//cout<<' '<<dx[1]<<' '<<dy[1]<<' '<<dx[2]<<' ';
			//cout<<' '<<dy[2]<<' '<<dx[3]<<' '<<dy[3]<<'\n';
		f[1]=1;
		for(i=2;i<=n;i++)
		{
			maxn=0;
			for(j=1;j<i;j++)
			{
				if(dy[j]<dy[i])
				{
					f[i]=max(f[j]+1,f[i]);
				}
				//if(maxn<f[i])
				//maxn=f[i];
			}
		}
		for(i=1;i<=n;i++)
		{
			maxn=max(maxn,f[i]);
		}
		//cout<<maxn<<' '<<f[1]<<' '<<f[2]<<' '<<f[3]<<' ';
		cout<<int(100*(double(x+y-2*maxn)+maxn*sqrt(2))+0.5);
	}
	
	
	/*dp的优化算法：在f[i],f[j]相同时的取舍
		当f[i]==f[j]时
		选择较小的 i
		具体方法：开一个数组long
		对于每一个f[]里的值，存储其最小的index(i,j中的i)
		long[f[i]]=i
		long[]的特征：有序 long[1]<long[2]<long[3]
		如此下来，对于一个新数a[k]
		首先
		把long[max](long[1],long[2],long[3]中的long[3]) 与 a[k] 作比较
		 1.a[k]>long[max] 那简单，把 a[k]接到a[long[max]]后面 ，max++
		 2. a[k]<long[max] 在long[]里搜索，找到使得(a[k]>a[i])的long[f[i]]最大的i
		 	接在后面,long[f[i]+1]=min()
	 */
