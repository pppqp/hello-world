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
				swap(dx[j],dx[j-1]);//��һ�δ�����ûд���� 
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
	
	
	/*dp���Ż��㷨����f[i],f[j]��ͬʱ��ȡ��
		��f[i]==f[j]ʱ
		ѡ���С�� i
		���巽������һ������long
		����ÿһ��f[]���ֵ���洢����С��index(i,j�е�i)
		long[f[i]]=i
		long[]������������ long[1]<long[2]<long[3]
		�������������һ������a[k]
		����
		��long[max](long[1],long[2],long[3]�е�long[3]) �� a[k] ���Ƚ�
		 1.a[k]>long[max] �Ǽ򵥣��� a[k]�ӵ�a[long[max]]���� ��max++
		 2. a[k]<long[max] ��long[]���������ҵ�ʹ��(a[k]>a[i])��long[f[i]]����i
		 	���ں���,long[f[i]+1]=min()
	 */
