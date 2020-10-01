#include<cstdio>
typedef long long ll;
const int N=100005;
int n,m,l,r,op,lg=1;
ll x;
ll a[N],add[N][2];
inline int lowbit(int x){return x&(-x);}
void push_down(int x,bool d){
	if(x>n||x<1||!add[x][d])return ;//这里记得特判 
	if(x&1){add[x][0]=add[x][1]=0;return ;}
	if(d==0){
		int x1=x-lowbit(x)/2;
		a[x1]+=add[x][0]*lowbit(x1);
		add[x1][0]+=add[x][0];
		add[x1][1]+=add[x][0];
		add[x][0]=0;
	}
	else{
		int x1=x+lowbit(x)/2;
		a[x1]+=add[x][1]*lowbit(x1);
		add[x1][0]+=add[x][1];
		add[x1][1]+=add[x][1];
		add[x][1]=0;
	}
}
void upd(int x,ll v){
	if(!x)return ;
	for(int x1=x;x1;x1-=lowbit(x1)){
		a[x1]+=v*lowbit(x1);
		add[x1][0]+=v;//!!!
	}
	for(int x1=x+lowbit(x);x1<=n;x1+=lowbit(x1)){
		a[x1]+=v*(x-(x1-lowbit(x1)));
	}
}
ll query(int x){
	if(!x)return 0;
	ll ans=0;
	for(int x1=lg;x1!=x;){
		if(x1<x)push_down(x1,1),x1+=lowbit(x1)/2;
		else push_down(x1,0),x1-=lowbit(x1)/2;
	}
	for(;x;x-=lowbit(x))ans+=a[x];
	return ans;
}
void build(){
	scanf("%d",&n);
	scanf("%d",&m);
	//memset(a,0,sizeof(a));
	//memset(add,0,sizeof(add));
	ll x;
	for(int i=1;i<=n;i++){
		scanf("%lld",&x);
		a[i]+=x;
		if(i+lowbit(i)<=n)a[i+lowbit(i)]+=a[i];
	}
}
int main(){
	build();
	while(lg*2<=n)lg*=2;
	while(m--){
		scanf("%d%d%d",&op,&l,&r);
		switch(op){
			case 1:
				scanf("%lld",&x);
				upd(l-1,-x);
				upd(r,x);
				break;
			case 2:
				printf("%lld\n",query(r)-query(l-1));
				break;
		}
	}
	return 0;
}
