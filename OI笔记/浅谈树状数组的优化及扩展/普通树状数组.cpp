#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[500010],n,m,t,x,y;
int sum(int x)
{
	int ans=0;
	for(int i=x;i;i-=i&(-i))ans+=a[i];
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);t=i;
		while(t<=n)
		{
			a[t]+=x;
			t+=t&(-t);
		}
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&t,&x,&y);
		if(t==1)
			while(x<=n)
			{
				a[x]+=y;
				x+=x&(-x);
			}
		else printf("%d\n",sum(y)-sum(x-1));
	}
	return 0;
}
