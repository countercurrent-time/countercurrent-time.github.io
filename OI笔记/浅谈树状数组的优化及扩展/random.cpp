#include<iostream>
#include<cstdio>
#include<ctime>
typedef long long ll;
using namespace std;

const int N=20;
ll rnd(ll n){
	return (((long long)rand()<<47)+((long long)rand()<<31)+(rand()<<15)+(rand()/2))%n;
}
int main(){
	int n=100000;
	srand(time(0));
	printf("%d %d\n",n,n);
	for(int i=1;i<=n;i++)printf("%lld ",rnd(N));
	for(int i=1;i<=n;i++){
		int op=rnd(2)+1;
		int l=rnd(n)+1,r=rnd(n)+1;
		if(l>r)swap(l,r);
		//if(op==1)printf("\n%d %d %d %lld",op,l,r,rnd(N));
		if(op==1)printf("\n%d %d %d",op,l,r);
		else printf("\n%d %d %d",op,l,r);
	}
	printf("\n");
	return 0;
}
