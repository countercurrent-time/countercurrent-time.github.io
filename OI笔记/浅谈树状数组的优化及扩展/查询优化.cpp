#include<cstdio>
int n,m,a[500010];
int lowbit(int x){return x&(-x);}
void add(int x,int v){
	while(x<=n)a[x]+=v,x+=lowbit(x);
}
int query(int l,int r){
	l--;
	int sum=0;
	while(r>l)sum+=a[r],r-=lowbit(r);
	while(l>r)sum-=a[l],l-=lowbit(l);
	return sum;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		a[i]+=x;
		if(i+lowbit(i)<=n)a[i+lowbit(i)]+=a[i];
	}
	while(m--){
		int op,l,r;
		scanf("%d%d%d",&op,&l,&r);
		if(op==1)add(l,r);
		else printf("%d\n",query(l,r));
	}
	return 0;
}
